/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 22, 2014, 8:18 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int bcoeff(int,int);
int gcd(int,int);
void towers(int,char,char,char);
int max(int *,int);
float sinR(float);
float cosR(float);

int main(int argc, char** argv) {
    //Utilize the recursive binary coefficient function
    int rows=10;
    for(int n=0;n<rows;n++){
        for(int k=0;k<=n;k++){
            cout<<bcoeff(n,k)<<" ";
        }
        cout<<endl;
    }
    //Testing the gcd with euclid algorithm
    int n=26*6,m=26*17;
    cout<<endl;
    cout<<"The GCD of "<<n<<" and "<<m<<" = "<<gcd(m,n)<<endl;
    cout<<"The GCD of "<<m<<" and "<<n<<" = "<<gcd(n,m)<<endl;
    cout<<endl;
    //Play the game Towers of Hanoi
    int nDsks=2;
    char peg1='A',peg2='B',peg3='C';
    towers(nDsks,peg1,peg2,peg3);
    //Fill array and find the max
    srand(static_cast<unsigned int>(time(0)));
    int size=100;
    int array[size];
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
    cout<<endl;
    cout<<"Max elements in the array = "<<max(array,size)<<endl;
    cout<<endl;
    //Testing out recursive trig functions
    float angDeg=30;
    float angRad=angDeg*atan(1)/45;
    cout<<"Angle = "<<angDeg<<" sin = "<<sin(angRad)<<
            " our sin = "<<sinR(angRad)<<endl;
    cout<<"Angle = "<<angDeg<<" sin = "<<cos(angRad)<<
            " our cos = "<<cosR(angRad)<<endl;
    //Exit Stage Right
    return 0;
}

float cosR(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1-angR*angR/2;
    float a=cosR(angR/2);
    float b=sinR(angR/2);
    return a*a-b*b;
}

float sinR(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR-angR*angR*angR/6;
    return 2*sinR(angR/2)*cosR(angR/2);
}

int max(int *a,int n){
    if(n==1)return a[0];
    int half=n/2;
    int top=n-half;
    int m1=max(a,half);
    int m2=max(a+half,top);
    return (m1>m2?m1:m2);
}

void towers(int n,char source,char spare,char destination){
    if(n>1) towers(n-1,source,destination,spare);
    cout<<"Source = "<<source<<" move to "<<destination<<endl;
    if(n>1) towers(n-1,spare,source,destination);
}

int gcd(int m,int n){
    if(m==0) return n;
    if(m>=n) return gcd(m%n,n);
    if(m<n) return gcd(n%m,m);
}

int bcoeff(int n,int k){
    if(k==0) return 1;
    if(k==n) return 1;
    return bcoeff(n-1,k-1)+bcoeff(n-1,k);
}

