/* 
 * File:   DLnkdLst.cpp
 * Author: Andrew Kim
 * Created on October 19, 2014, 1:56 PM
 */

#include "DLnkdLst.h"

DLnkdLst::DLnkdLst(int n) {
    worker=new Node;
    worker->data=n;
    worker->prev=NULL;
    head=worker;
    tail=worker;
}

DLnkdLst::DLnkdLst(const DLnkdLst&){
    
}

void DLnkdLst::append(int n){
    worker=new Node;
    worker->data=n;
    worker->prev=tail;
    tail->next=worker;
    tail=worker;
    tail->next=NULL;
}

void DLnkdLst::printF(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void DLnkdLst::PrintB(){
    Node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

DLnkdLst::~DLnkdLst() {
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
        }while(head);
    }
}