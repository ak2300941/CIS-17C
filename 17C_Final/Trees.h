/* 
 * File:   Trees.h
 * Author: Andrew
 * Created on December 12, 2014, 3:49 PM
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
        string data;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* createLeaf(string);
    void addLeafp(string,Node*);
    void prstringp(Node*);
    void removeNodep(string,Node*);
    //Helper functions
    Node* returnNodep(string,Node*);
    string findsmallestp(Node*);
    void removeRootMatch();
    void removeMatch(Node*,Node*,bool);
    string treeContains(Node*,string);
public:
    Trees();
    //Insert Function
    void addLeaf(string);
    //Prstring Function
    void prstring();
    //Delete Function
    void removeNode(string);
    Node* returnNode(string);
    string findsmallest();
    string treeContains(string);
    
};

#endif	/* TREES_H */

