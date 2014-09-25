/* 
 * File:   LnkdLst.cpp
 * Author: Andrew Kim
 * Created on September 24, 2014, 3:51 PM
 */

#include "LnkdLst.h"

LnkdLst::LnkdLst(int n) {
    head = NULL;
}

void LnkdLst::append(int num) {
    Node *newNode;
    Node *nodePtr;
    //Allocate a new node and store the number here.
    newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    //If there are no nodes in the list 
    //make the first node.
    if (!head)head = newNode;
    else { //If Not insert newNode at the end
        //Initialize nodePtr to head of list
        nodePtr = head;
        //Find the last node in the list
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        //Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

void LnkdLst::toString() {
    Node *nodePtr; //To move through the list
    //Position nodePtr at the head of the list.
    nodePtr = head;
    //While nodePtr points to a node, traverse the list.
    while (nodePtr) {
        for (int i = 0; i < 3; i++) {
            cout << nodePtr->data <<endl;;
            nodePtr = nodePtr->next;
        }
    }
}

LnkdLst::~LnkdLst() {
    Node *nodePtr; //To tranverse the list
    Node *preNode; //To point to the previous node
    //If the list is empty
    if (!head)return;
    //Determine if the first node is the one.
    if (head->data == 1) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        //Initialize nodePtr to head of list
        nodePtr = head;
        //Skip all nodes whose value member is not equal to number.
        while (nodePtr != NULL && nodePtr->data != 1) {
            preNode = nodePtr->next;
        }
        //If nodePtr is not at the end of the list, link the previous node
        //to the node after nodePtr, then delete nodePtr.
        if (nodePtr) {
            preNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

