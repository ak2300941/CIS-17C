/* 
 * File:   CLnkdLst.h
 * Author: Andrew Kim
 * Created on October 19, 2014, 3:51 PM
 */

#ifndef CLNKDLST_H
#define	CLNKDLST_H
#include <iostream>
using namespace std;

class CLnkdLst {
public:
    CLnkdLst(int);
    CLnkdLst(const CLnkdLst&);
    void append(int);
    void printF();  //Print Forward
    void PrintB();  //Print Backward
    virtual ~CLnkdLst();

private:
    struct Node{
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    Node *worker;
};

#endif	/* CLNKDLST_H */

