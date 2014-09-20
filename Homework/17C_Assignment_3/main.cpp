/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: 17C - Assignment 3
 * Created on September 19, 2014, 7:05 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
int *fillArray(int);
void printArray(int *,int,int);
void destroy(int *);
void sort(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D array
    int rows=20000;
    int cls=rows,perLine=10;
    int *colAry=fillArray(cls);
    int tstart=time(0);
    //Bubble Sort
    sort(colAry,cls);
    int tend=time(0);
    cout<<"Total Time taken = "<<tend-tstart<<endl;
    //Print the array
    //printArray(colAry,cls,perLine);
    //Delete the array
    destroy(colAry);
    return 0;
}

void sort(int *a,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void destroy(int *array){
    //Destroy row pointer
    delete []array;
}

void printArray(int *array,int cols,int perLine){
    //Print the array
    cout<<endl;
    for(int col=0;col<cols;col++){
        cout<<array[col]<<" ";
        if(col%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillArray(int cols){
    //Declare the 1-D Array
    int *array=new int[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}
