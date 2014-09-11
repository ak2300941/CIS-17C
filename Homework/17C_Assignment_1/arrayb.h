/*
 * File:   ArrayB.h
 * Author: Andrew Kim
 * Created on September 9, 2014, 7:21 PM
 */

#ifndef ARRAYB_H
#define	ARRAYB_H

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class ArrayB{
   private:
       T nRows;
       T *array;
       T **triarray;
   public:
       ArrayB(T,T *);
       ~ArrayB();
       void print();
};

template <class T>
ArrayB<T>::ArrayB(T r, T *a){
    nRows=r;
    array=a;
    //Random Number Generator
    srand(static_cast<unsigned int>(time(0)));
    triarray=new int *[nRows];
    for(int row=0;row<nRows;row++){
        triarray[row]=new int[array[row]];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<nRows;row++){
        for(int col=0;col<array[row];col++){
            triarray[row][col]=rand()%90+10;
        }
    }
}

template <class T>
ArrayB<T>::~ArrayB(){
    for(int row=0;row<nRows;row++){
        delete []triarray[row];
    }
    //Destroy row pointers
    delete []triarray;
}


template <class T>
void ArrayB<T>::print(){
    cout<<endl;
     for(int row=0;row<nRows;row++){
        for(int col=0;col<array[row];col++){
            cout<<triarray[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

#endif	/* ARRAYB_H */

