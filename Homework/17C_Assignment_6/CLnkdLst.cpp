/* 
 * File:   CLnkdLst.cpp
 * Author: Andrew Kim
 * Created on October 19, 2014, 3:51 PM
 */

#include "CLnkdLst.h"

CLnkdLst::CLnkdLst(int n) {
    worker=new Node;
    worker->data=n;
    worker->prev=NULL;
    head=worker;
    tail=worker;
}

CLnkdLst::CLnkdLst(const CLnkdLst&){
    
}

void CLnkdLst::append(int n){
    worker=new Node;
    worker->data=n;
    worker->prev=tail;
    tail->next=worker;
    tail=worker;
    tail->next=NULL;
}

void CLnkdLst::printF(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void CLnkdLst::PrintB(){
    Node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

CLnkdLst::~CLnkdLst() {
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}