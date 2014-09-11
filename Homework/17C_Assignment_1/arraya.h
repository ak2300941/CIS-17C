/*
 * File:   ArrayA.h
 * Author: Andrew Kim
 * Created on September 9, 2014, 7:04 PM
 */

#ifndef ARRAYA_H
#define	ARRAYA_H

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class ArrayA{
   private:
       T nCols;
       T *array;
   public:
       ArrayA(T);
       ~ArrayA();
       void print(T);
       T *getArray() const;
};

template <class T>
ArrayA<T>::ArrayA(T c){
    nCols=c;
    //Random Number Generator
    srand(static_cast<unsigned int>(time(0)));
    array=new int[nCols];
    for(int col=0;col<nCols;col++){
        array[col]=rand()%9+2;
    }
}

template <class T>
ArrayA<T>::~ArrayA(){
    delete []array;
}

template <class T>
void ArrayA<T>::print(T perLine){
    cout<<endl;
    for(int col=0;col<nCols;col++){
        cout<<array[col]<<" ";
        if(col%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

template <class T>
T *ArrayA<T>::getArray() const{
    return array;
}


#endif	/* ARRAYA_H */

