/* 
 * File:   DLnkdLst.h
 * Author: Andrew Kim
 * Created on October 19, 2014, 1:56 PM
 */

#ifndef DLNKDLST_H
#define	DLNKDLST_H
#include <iostream>
using namespace std;

class DLnkdLst {
public:
    DLnkdLst(int);
    DLnkdLst(const DLnkdLst&);
    void append(int);
    void printF();  //Print Forward
    void PrintB();  //Print Backward
    virtual ~DLnkdLst();

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

#endif	/* DLNKDLST_H */

