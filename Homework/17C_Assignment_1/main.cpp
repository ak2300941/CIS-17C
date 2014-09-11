/*
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: CIS17C - Assignment 1
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//User-Defined Libraries
#include "ArrayA.h"
#include "ArrayB.h"
using namespace std;

int main(){
    int rows=5,cols=5,perLine=10;
    //Construct the instance
    ArrayA<int> colAry(cols);
    ArrayB<int> triAry(rows,colAry.getArray());
    //Print the array
    colAry.print(perLine);
    triAry.print();
    //Delete the Array
    return 0;
}

