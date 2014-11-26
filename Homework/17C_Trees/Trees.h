/* 
 * File:   Trees.h
 * Author: Andrew
 * Created on November 24, 2014, 7:30 PM
 */

#ifndef TREES_H
#define	TREES_H
//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

class Trees {
private:
   struct Node{
        int data;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* createLeaf(int);
    void addLeafp(int,Node*);
    void printp(Node*);
    void removeNodep(int,Node*);
    //Helper functions
    Node* returnNodep(int,Node*);
    int findsmallestp(Node*);
    void removeRootMatch();
    void removeMatch(Node*,Node*,bool);
public:
    Trees();
    //Insert Function
    void addLeaf(int);
    //Print Function
    void print();
    //Delete Function
    void removeNode(int);
    Node* returnNode(int);
    int findsmallest();
};

#endif	/* TREES_H */

