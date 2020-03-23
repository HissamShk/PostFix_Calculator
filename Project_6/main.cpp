//CSCI 301
//PROJECT 6
//Postfix Calculator
//Hissamuddin Shaikh
//This program utilizes the class, Stacker, to compute a multitude of arithmetical expressions, containing
//multi-digit integers, which are in PostFix notation. The Expression are accessed from a file inserted by the user.
//It exercises most of the functions of the Stacker class, and has error control present to allow the program to
//run smoothly.
#include<iostream>
#include<string>
#include<fstream>
#include "Stacker.h"
using namespace std;
using namespace std;
/*Function Prototypes*/
void openFile(ifstream &File, string FileName);
//Pre-Condition: Takes in the object, through which the data in the file will be accessed.
//               Takes in the name of the file to be opened.
//Post-Condition: Opens the file.
int Apply(char Optr, int Opnd1, int Opnd2);
//Pre-Condition: Takes in 2 Operands upon which the operation, dictated by the operator, is to be performed.
//Post-Condition: Returns the result of the operation.
bool IsNumericDigit(char C);
//Pre-Condition: Takes in a Character.
//Post-Condition: Determines whether the character is a Numeric Digit or not.
//                Returns true if it is, otherwise false.
bool IsOperator(char C);
//Pre-Condition: Takes in a Character.
//Post-Condition: Determines whether the character is an operator or not.
//                Returns true if it is, otherwise false.
int EvaluatePostfix(string expression);
//Pre-Condition: Takes in an expression, as a string.
//Post-Condition: Scans each character in the string, including spaces.
//                Determines whether the character is a Numeric Digit (multi or single) or an Operator
//                through the IsNumericDigit or IsOperator functions.
//                Computes the subexpression, and then ultimately the whole expression by pushing the operands,
//                popping the appropriate operands when running into an operator, performing the necessary
//                operations and then pushing the result.
int main()
{
	//Data Variables
	ifstream File;
	string Expression;
	string FileName;
	int Result;
    //Prompt for the Name of the File, containing the Expressions.
    cout << endl;
    cout << " |Postfix Calculator|" << endl;
    do{
        cout << endl;
        cout << " Enter the Name of an Existing Input File: ";
        //Opening the File
        getline (cin, FileName);
        openFile(File, FileName);} while(File.fail());
	cout << endl;
    while (!File.eof())
	{
        //Extracting an Expression from the File
        getline(File,Expression);
        //Computing the Expression, and storing the Result.
        Result = EvaluatePostfix(Expression);
        //Displaying the Expression, and its Respective Result.
        cout <<" Expression: " << Expression << endl;
        cout<<" Value = " << Result << endl;
        cout << endl;
	}
}
//Function to Open a File
void openFile(ifstream &File, string FileName)
{
    File.open(FileName.c_str());
}
//Function to Perform Mathematical Operation
int Apply(char Optr, int Opnd1, int Opnd2)
{
	if(Optr == '+') return Opnd1 + Opnd2;
	else if(Optr == '-') return Opnd1 - Opnd2;
	else if(Optr == '*') return Opnd1 * Opnd2;
	else if(Optr == '/') return Opnd1 / Opnd2;
	else cout <<" Unexpected Error " << endl;
	return -1;
}
//Function to determine if the character is a digit or not.
bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}
//Function to determine if the character is a digit or not.
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}
//Function to Perform the Evaluation of the respective Expression
int EvaluatePostfix(string expression)
{
	//Data Variables
	Stacker S;
	int operand2;
	int operand1;
	int operand;
	int result;
	//For-Loop to address each character in the string, scanning from left to right.
	for(int i = 0;i< expression.length();i++) {
		// If character is a delimitter, move on.
		if(expression[i] == ' ') continue;
		// If the character is an operator, pop 2 elements from Stack, Perform respective operation
		// and push the acquired result back.
		else if(IsOperator(expression[i])) {
			// Pop two operands.
			operand2 = S.Pop();
			operand1 = S.Pop();
			// Perform respective operation
			result = Apply(expression[i], operand1, operand2);
			//Push back the result of the operation on to a stack.
			S.Push(result);
		}
		else if(IsNumericDigit(expression[i])){
			// Extract the Numeric operand from the string expression
			// Keep incrementing i as long as you are getting a numeric digit.
			operand = 0;
			while(i < expression.length() && IsNumericDigit(expression[i])) {
				// Whenever, we run into a number with more than one digit towards right, we can multiply current
				//total in operand by 10 and add the new digit.
				operand = (operand * 10) + (expression[i] - '0');
				i++;
			}
                //Decrement once, so as not to skip the non-numeric character by incrementing i twice.
			i--;
			// Push the operand onto a stack.
			S.Push(operand);
		}
	}
	// If expression is in correct format, Stack will have one element in the end. This will be the output.
	return S.Pop();
}
