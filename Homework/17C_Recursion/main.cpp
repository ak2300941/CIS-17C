/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: CIS17A - Recursion
 * Created on October 27, 2014, 8:19 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Function Prototypes
float Recursion(float,float,float);

//Execution Begins Here
int main(int argc, char** argv) {
    float pv=1000;
    float interest=0.3;
    float years=100;
    for(int i=1;i<=years;i++){
        cout<<Recursion(pv,interest,i)<<endl;
    }
    return 0;
}

float Recursion(float pv,float i,float n){
    if(n==1)return (pv*(1+i));
    return(pv*pow((1+i),n));
}

