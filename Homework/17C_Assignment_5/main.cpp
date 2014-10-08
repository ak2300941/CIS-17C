/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 1:55 PM
 * Purpose:  Explore creation of a linked list class Version 3
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst<int> list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    //Print First
    cout<<list.first()<<endl;
    //Print Last
    cout<<list.last()<<endl;
    //Prepend add one
    list.prepend(10);
    //Print the data
    cout<<list.toString()<<endl;
    //Extract chain with value 10
    list.extract(10);
    //Print the data
    cout<<list.toString()<<endl;
    //Insert Number with Position (After)
    list.insertA(20,2);
    //Print the data
    cout<<list.toString()<<endl;
    //Insert Number with Position (Before)
    list.insertB(15,3);
    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    return 0;
}