/* 
 * File:   Trees.cpp
 * Author: Andrew
 * Created on December 12, 2014, 3:49 PM
 */

#include "Trees.h"

Trees::Trees()
{
    root=NULL;
}

Trees::Node* Trees::createLeaf(string data)
{
    Node* n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void Trees::addLeaf(string data)
{
    addLeafp(data,root);
}

void Trees::addLeafp(string data, Node* ptr)
{
    //Check if tree is empty
    if(root==NULL)
    {
        root=createLeaf(data);
    }
    //Left side of the tree (less than)
    else if(data<ptr->data)
    {
        //If it is postringing to something already (recursive)
        if(ptr->left!=NULL)
        {
            addLeafp(data,ptr->left);
        }
        //If it is not postringing to anything
        else
        {
            ptr->left=createLeaf(data);
        }
    }
    //Right side of the tree (greater than)
    else if(data>ptr->data)
    {
        //If it is postringing to something already (recursive)
        if(ptr->right!=NULL)
        {
            addLeafp(data,ptr->right);
        }
        //If it is not postringing to anything
        else
        {
            ptr->right=createLeaf(data);
        }
    }
    //If data value is equal to exactly the same as one already in
    else
    {
        //cout<<"The data "<<data<<" is already in the tree"<<endl;
    }
}

void Trees::prstring()
{
    prstringp(root);
    cout<<endl;
}

void::Trees::prstringp(Node* ptr)
{
    //Check if its empty or not
    if(root!=NULL)
    {
        //is it possible to go left
        if(ptr->left!=NULL)
        {
            prstringp(ptr->left);
        }
        cout<<ptr->data<<" ";
        //is it possible to go right
        if(ptr->right!=NULL)
        {
            prstringp(ptr->right);
        }
    }
    else
    {
        cout<<"Tree is empty"<<endl;
    }
}

Trees::Node* Trees::returnNode(string data)
{
    return returnNodep(data,root);
}

Trees::Node* Trees::returnNodep(string data, Node* ptr)
{
    //If the postringing passing in is postringing to something
    if(ptr!=NULL)
    {
        //If found the Node
        if(ptr->data==data)
        {
            return ptr;
        }
        else
        {
            //If less than (recursive)
            if(data<ptr->data)
            {
                return returnNodep(data,ptr->left);
            }
            //If greater than (recursive)
            else
            {
                return returnNodep(data,ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}


string Trees::findsmallest()
{
    findsmallestp(root);
}

string Trees::findsmallestp(Node* ptr)
{
    //If empty
    if(root==NULL)
    {
        cout<<"Tree is empty."<<endl;
        return NULL;
    }
    //When not empty
    else
    {
        if(ptr->left!=NULL)
        {
            return findsmallestp(ptr->left);
        }
        else
        {
            return ptr->data;
        }
    }
}

string Trees::treeContains(string a)
{
    return treeContains(root,a);
}

string Trees::treeContains(Node* root,string item)
{
    if ( root == NULL ) {
        // Tree is empty, so it certainly doesn't contain item.
        return "Not found";
    }
    else if ( item == root->data ) {
        // Yes, the item has been found in the root node.
        return "Yes";
    }
    else if ( item < root->data ) {
        // If the item occurs, it must be in the left subtree.
        return treeContains( root->left, item );
    }
    else {
        // If the item occurs, it must be in the right subtree.
        return treeContains( root->right, item );
    }
}

void Trees::removeNode(string data)
{
    removeNodep(data,root);
}

void Trees::removeNodep(string data, Node* parent)
{   
    //If not empty
    if(root!=NULL)
    {
        //If found the data to delete
        if(root->data==data)
        {
            //removeRootMatch();
        }
        //If not found
        else
        {
            //Left child
            if(data<parent->data&&parent->left!=NULL)
            {
                parent->left->data==data ?
                removeMatch(parent,parent->left,true):
                removeNodep(data,parent->left);
            }
            //Right child
            else if(data>parent->data&&parent->right!=NULL)
            {
                parent->right->data==data ?
                removeMatch(parent,parent->right,false):
                removeNodep(data,parent->right);
            }
            else
            {
                cout<<"The data "<<data<<" was not found in the tree."<<endl;
            }
        }
    }
    //If empty
    else
    {
        cout<<"The tree is empty."<<endl;
    }
}

void Trees::removeRootMatch()
{
    if(root!=NULL)
    {
        Node* delPtr=root;
        string rootData=root->data;
        string smallestright;
        //0 children
        if(root->left==NULL&&root->right==NULL)
        {
            root=NULL;
            delete delPtr;
        }
        //1 Child
        //  child on right
        else if(root->left==NULL&&root->right!=NULL)
        {
            root=root->right;
            delPtr->right=NULL;
            delete delPtr;
        }
        //  child on left
        else if(root->left!=NULL&&root->right==NULL)
        {
            root=root->left;
            delPtr->left=NULL;
            delete delPtr;
        }
        //2 Children
        else
        {
            smallestright=findsmallestp(root->right);
            removeNodep(smallestright,root);
            root->data=smallestright;
        }
    }
    else
    {
        cout<<"Can not remove root, tree is empty"<<endl;
    }
}

void Trees::removeMatch(Node* parent, Node* match, bool left)
{
    if(root!=NULL)
    {
        Node* delPtr;
        string matchData=match->data;
        string smallestright;
        //0 Children
        if(match->left==NULL&&match->right==NULL)
        {
            delPtr=match;
            left==true?parent->left=NULL:parent->right=NULL;
            delete delPtr;
        }
        //1 Child
        //  Right child
        else if(match->left==NULL&&match->right!=NULL)
        {
            left==true?parent->left=match->right:parent->right=match->right;
            match->right=NULL;
            delPtr=match;
            delete delPtr;
        }
        //  Left child
        else if(match->left!=NULL&&match->right==NULL)
        {
            left==true?parent->left=match->left:parent->right=match->left;
            match->left=NULL;
            delPtr=match;
            delete delPtr;
        }
        //2 Children
        else
        {
            smallestright=findsmallestp(match->right);
            removeNodep(smallestright,match);
            match->data=smallestright;
        }
    }
    else
    {
        cout<<"Can not remove match. Tree is empty"<<endl;
    }
}