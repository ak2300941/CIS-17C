/* 
 * File:   stackcount.h
 * Author: Andrew
 * Created on November 11, 2014, 6:40 PM
 */

#ifndef STACKCOUNT_H
#define	STACKCOUNT_H
#include <stack>
#include <vector>
using namespace std;

class stackcount {
public:
    stackcount(){
        stackc.push(6);
        stackc.push(5);
        stackc.push(4);
        stackc.push(3);
        stackc.push(2);
        stackc.push(1);
        stackc.push(0);
    }
    void stackdown(){
        stackc.pop();
    }
    
    int getS(){
        return stackc.top();
    }
    
private:
    stack<int> stackc;
};

#endif	/* STACKCOUNT_H */

