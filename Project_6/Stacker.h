//CSCI 301
//Stacker.h
//Stacker Class: A Class to implement a Stack ADT (Abstract Data Type).
//Hissamuddin Shaikh
//This class contains a variety of functions, that allows for the creation, manipulation and querying of a stack.
//The stack present in this class, has been implemented sequentially (is array-based).
#ifndef STACKER_H
#define STACKER_H
#include <iostream>
using namespace std;
//Class, containing functions that will implement a sequential (array-based) stack.
class Stacker
{
    public:
        //An Alias for the type assignment, to make it easier to change the type of Stack, if necessary.
        typedef int Item;
        /*Constant Member Functions and Data Variable*/
        const static int Capacity = 75;
        //Constructor
        Stacker();
        /*Modification and Query Functions*/
        void Push(Item Entry);
        //Pre-Condition: Takes in an entry, of the type defined by "Item" .
        //Post-Condition: Places the Value into the Stack(Array), while also establishing it as the top of the stack.
        Item Pop();
        //Post-Condition: Removes the Value at the top of the Stack(Array).
        int Size();
        //Post-Condition: Returns how many Values are present in the Stack.
        bool Empty();
        //Post-Condition: Returns whether or not the Stack is Empty(True = Empty).
    private:
        /*Data Members for the Class*/
        Item Data[Capacity];
        //The Array, which will be the Stack.
        int Used;
        //The Variable to track what is at the top of the stack,
        //and, in turn how many Values are in the stack.
};
#endif //STACKER_H
