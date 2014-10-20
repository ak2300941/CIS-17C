/* 
 * File:   QLnkedLst.h
 * Author: Andrew Kim
 * Created on October 19, 2014, 3:11 PM
 */

#ifndef QLNKEDLST_H
#define	QLNKEDLST_H
#include <iostream>
using namespace std;

class QLnkedLst {
public:
    QLnkedLst();
    QLnkedLst(const QLnkedLst&);
    void add(int);
    void del();
    virtual ~QLnkedLst();
private:
    struct Node{
        int data;
        Node *next;
    };
    Node *front;
    Node *rear;
    Node *worker;
};

#endif	/* QLNKEDLST_H */

