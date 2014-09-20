/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Created on September 17, 2014, 12:37 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User-Defined Libraries
#include "SimpleVector.h"

//Execution Begins Here
int main(int argc, char** argv) {
    int SIZE=10;
    SimpleVector<int> test(SIZE);
    //Original
    cout<<"Original Vector"<<endl;
    //Test if working
    cout<<"Vector stores "<<test.size()<<" numbers"<<endl;
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    //Push
    cout<<"Vector after Push"<<endl;
    test.Push(5);
    //Test if working
    cout<<"Vector stores "<<test.size()<<" numbers"<<endl;
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    //Pull
    cout<<"Vector after Pull"<<endl;
    test.Pull();
    //Test if working
    cout<<"Vector stores "<<test.size()<<" numbers"<<endl;
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}

