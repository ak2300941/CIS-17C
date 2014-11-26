/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: Create Tree Class
 * Created on November 24, 2014, 7:29 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User-Defined Libraries
#include "Trees.h"

//Execution Begins Here
int main(int argc, char** argv) {
    int treeData[16]={50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    Trees myTree;
    cout<<"Printing the tree in order before adding numbers."<<endl;
    myTree.print();
    cout<<"Printing the tree in order after adding numbers."<<endl;
    for(int i=0;i<16;++i)
    {
        myTree.addLeaf(treeData[i]);
    }
    myTree.print();
    cout<<endl;
    cout<<"Removing number 64"<<endl;
    myTree.removeNode(64);
    myTree.print();
    cout<<endl;
    cout<<"Adding number 22"<<endl;
    myTree.addLeaf(22);
    myTree.print();
    return 0;
}

