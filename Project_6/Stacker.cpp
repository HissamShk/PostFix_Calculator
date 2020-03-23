//CSCI 301
//Stacker.cpp
//Stacker Class: A Class to implement a Stack ADT (Abstract Data Type).
//Hissamuddin Shaikh
#include <iostream>
#include "Stacker.h"
#include <typeinfo>
//Constructor
Stacker::Stacker()
{
    Used = 0;
}
//Function to place a Value into the Stack (Array).
void Stacker::Push(Item Entry)
{
    Data[Used] = Entry;
    ++Used;
}
//Function to remove the Value at the top of Stack (Array).
Stacker::Item Stacker::Pop()
{
    --Used;
    return Data[Used];
}
//Function to return the number of Values (Size) in the Stack (Array).
int Stacker::Size()
{
    return Used;
}
//Function to inform whether or not the Stack(Array) is empty.
bool Stacker::Empty()
{
    return (Used = 0);
}
