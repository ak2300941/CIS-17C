/* 
 * File:   QLnkedLst.cpp
 * Author: Andrew Kim
 * Created on October 19, 2014, 3:11 PM
 */

#include "QLnkedLst.h"

QLnkedLst::QLnkedLst() {
    front=NULL;
    rear=NULL;
}

QLnkedLst::QLnkedLst(const QLnkedLst&) {
    
}

void QLnkedLst::add(int n){
    worker=new Node;
    if(worker==NULL)cout<<"Queue Full"<<endl;
    worker->data=n;
    worker->next=NULL;
    if(front==NULL){
        rear=front=worker;
        return;
    }
    rear->next=worker;
    rear=rear->next;
}

void QLnkedLst::del(){
    if(front==NULL){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"Deleting: "<<front->data<<endl;
    worker=front;
    front=front->next;
}

QLnkedLst::~QLnkedLst() {
    if(front=NULL)return;
    while(front!=NULL){
        worker=front;
        front=front->next;
        delete worker;
    }
}

