/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Created on October 19, 2014, 1:42 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include "LnkdLst.h"
#include "DLnkdLst.h"
#include "StLnkdLst.h"
#include "QLnkedLst.h"
#include "CLnkdLst.h"
using namespace std;

int main(int argc, char** argv) {
    //Sorted linked list
    cout<<"~~Sorted Linked List~~"<<endl;
    int index=0;
    LnkdLst<int> link(10);
    index++;
    link.append(4);
    index++;
    link.append(25);
    index++;
    cout<<link.toString()<<endl;
    link.sort(index);
    cout<<link.toString()<<endl;
    //Doubly linked list
    cout<<"~~Doubly Linked List~~"<<endl;
    DLnkdLst dlist(5);
    dlist.append(14);
    dlist.append(20);
    dlist.printF();
    dlist.PrintB();
    //Stack using linked list
    cout<<"~~Using Stacks on Linked List~~"<<endl;
    StLnkdLst stack;
    stack.push(25);
    stack.push(23);
    stack.push(14);
    stack.push(13);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    //Queues using linked list
    cout<<"~~Using Queues on Linked List~~"<<endl;
    QLnkedLst Queue;
    Queue.add(11);
    Queue.add(14);
    Queue.add(25);
    Queue.del();
    Queue.del();
    Queue.del();
    Queue.del();
    //Circular linked list
    cout<<"~~Circular Linked List~~"<<endl;
    CLnkdLst Circular(15);
    Circular.append(20);
    Circular.append(12);
    Circular.printF();
    return 0;
}

