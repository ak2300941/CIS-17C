/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: Final Exam
 * Created on December 9, 2014, 12:21 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <iomanip>
#include <list>
#include <stdio.h>
#include <limits.h>
using namespace std;

//User-Defined Libraries
#include "Trees.h"


//Function Prototypes
void Menu();
int getN();
void def(int);
//Problem 1
void problem1();
int hash(string);
//Problem 2
void problem2();
float h(float,stack<char> &);
float g(float,stack<char> &);
//Problem 3
void problem3();
//Problem 4
void problem4();
void BubbleSort(vector<short> &);
void SelectionSort(vector<short> &);
void HeapSort(vector<short> &);
void makeHeap(vector<short> &,int);
void mergeSort(vector<short> &,int,int);
void merge(vector<short> &,int,int,int);
void quickSort(vector<short> &,int,int);
void printVector(vector<short>,int);
//Problem 5
void problem5();
//Problem 6
void problem6();

//Execution Begins Here
int main(int argc, char** argv)
{
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;
    return 0;
}

void Menu()
{
    cout<<"Menu for the Final"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void problem1()
{
    //Person
    string test="MEL";
    int person=hash(test);
    //Generate 1000
    int collisions=0;
    int SIZE=1000;
    string store[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    char letters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<SIZE;i++)
    {
        //Get 3 Random Letters into 1 string
        for(int j=0;j<3;j++)
        {
            char x=letters[rand()%26];
            store[i].push_back(x);
        }
        //cout<<store[i]<<" ";
    }
    //Test For Collisions (And Search for name)
    float tstart=time(0);
    float tend;
    for(int i=0;i<SIZE;i++)
    {
        int temp=hash(store[i]);
        if(temp==person)
        {
            collisions++;
            tend=time(0);
        }
        //cout<<temp<<" ";
    }
    //Format
    cout<<"Collisions: "<<collisions<<endl;
    cout<<"Average Search Time: "<<tstart-tend<<" Seconds"<<endl;
    cout<<endl;
}

int hash(string name)
{
    int total=0;
    
    for(int i=0;i<3;i++)
    {
        if(name.at(i)=='A'||name.at(i)=='B'||name.at(i)=='C')
        {
            if(i==0)total=total+200;
            if(i==1)total=total+20;
            if(i==2)total=total+2;
        }
        if(name.at(i)=='D'||name.at(i)=='E'||name.at(i)=='F')
        {
            if(i==0)total=total+300;
            if(i==1)total=total+30;
            if(i==2)total=total+3;
        }
        if(name.at(i)=='G'||name.at(i)=='H'||name.at(i)=='I')
        {
            if(i==0)total=total+400;
            if(i==1)total=total+40;
            if(i==2)total=total+4;
        }
        if(name.at(i)=='J'||name.at(i)=='K'||name.at(i)=='L')
        {
            if(i==0)total=total+500;
            if(i==1)total=total+50;
            if(i==2)total=total+5;
        }
        if(name.at(i)=='M'||name.at(i)=='N'||name.at(i)=='O')
        {
            if(i==0)total=total+600;
            if(i==1)total=total+60;
            if(i==2)total=total+6;
        }
        if(name.at(i)=='P'||name.at(i)=='Q'||name.at(i)=='R'||name.at(i)=='S')
        {
            if(i==0)total=total+700;
            if(i==1)total=total+70;
            if(i==2)total=total+7;
        }
        if(name.at(i)=='T'||name.at(i)=='U'||name.at(i)=='V')
        {
            if(i==0)total=total+800;
            if(i==1)total=total+80;
            if(i==2)total=total+8;
        }
        if(name.at(i)=='W'||name.at(i)=='X'||name.at(i)=='Y'||name.at(i)=='Z')
        {
            if(i==0)total=total+900;
            if(i==1)total=total+90;
            if(i==2)total=total+9;
        }
    }
    return total;
}

void problem2()
{
    stack<char> data;
    //Testing out recursive trig functions
    float angDeg=45;
    float angRad=angDeg*atan(1)/45;
    cout<<"Angle = "<<angDeg<<" sinh = "<<sinh(angRad)<<
            " our h = "<<h(angRad,data)<<endl;
    cout<<"Angle = "<<angDeg<<" cosh = "<<cosh(angRad)<<
            " our g = "<<g(angRad,data)<<endl;
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    //Display
    cout<<"Stack Size: "<<data.size()<<endl;
    int indexH=0,indexG=0;
    bool check=false;
    do
    {
        if(data.top()=='h'&&check==false)
        {
            if(data.size()!=1)
            {
                indexH++;
                data.pop();
            }
            else
            {
                indexH++;
                check=true;
            }
        }
        if(data.top()=='g'&&check==false)
        {
            if(data.size()!=1)
            {
                indexG++;
                data.pop();
            }
            else
            {
                indexG++;
                check=true;
            }
        }
    }while(check==false);
    cout<<"# of times calling function H: "<<indexH<<endl;
    cout<<"# of times calling function G: "<<indexG<<endl;
    cout<<endl;
}

float h(float angR,stack<char> &s)
{
    float tol=1e-6;
    s.push('h');
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h((angR/2),s)*g((angR/2),s);
}
float g(float angR,stack<char> &s)
{
    float tol=1e-6;
    s.push('g');
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h((angR/2),s);
    return 1+2*b*b;
}

void problem3()
{
    queue<int> customers;
    vector<int> clerks;
    vector<int> etime;
    //Find Maximum
    int maxcustomer=0;
    int maxclerk=0;
    //Variables to find average wait time
    int custom=0;
    int time;
    //integer i is seconds //Break the loop when customers reach 0
    for(int i=1;i<=300000;i++)
    {
        //Add Customer every 20 seconds
        if(i%20==0)
        {
            customers.push(i);
            custom++;
        }
        //Find Highest Number of Customers in the line
        if(customers.size()>maxcustomer)
        {
            maxcustomer=customers.size();
        }
        //Clerk 1
        if(i%60==0)
        {
            customers.pop();
        }
        //Clerk 2
        if(i%120==0)
        {
            customers.pop();
        }
        //Clerk 3
        if(i%80==0)
        {
            customers.pop();
        }
        //Add Clerk per 5 customers
        if(customers.size()>=5)
        {
            //Use second to use to mod at that area
            clerks.push_back(60);
            customers.pop();
            //cout<<"Time when new Clerk got called: "<<i<<endl;
            //Time at 0
            etime.push_back(0);
        }
        //Find Highest Number of Clerks
        if(clerks.size()>maxclerk)
        {
            maxclerk=clerks.size();
        }
        //Do loop for new clerks
        for(int j=0;j<clerks.size();j++)
        {
            //if 60=60  //etime counts to 60 and resets
            if(clerks[j]==etime[j])
            {
                //cout<<"New Clerk popped a guy"<<endl;
                customers.pop();
                etime[j]=0;
            }
        }
        //cout<<"Timer: "<<i<<endl;
        //Fire a clerk when line reaches 0
        if(customers.size()==0&&clerks.size()>0)
        {
            clerks.pop_back();
            //cout<<"Clerk Left"<<endl;
        }
        //If no customers left
        if(customers.size()==0&&i>60)
        {
            time=i;
            break;
        }
        //Forward time for new clerks
        if(etime.size()>0)
        {
            for(int k=0;k<etime.size();k++)
            {
                etime[k]++;
            }
        }
        
    }
    cout<<"~Results~"<<endl;
    cout<<"Max Customers: "<<maxcustomer<<endl;
    //Add 3 For the original clerks
    cout<<"Max Clerks: "<<maxclerk+3<<endl;
    cout<<"Total Time: "<<time<<" seconds"<<endl;
    cout<<"Total Customers: "<<custom<<endl;
    cout<<"Average Wait Time: "<<time/custom<<" seconds"<<endl;
    cout<<endl;
}

void problem4()
{
    //If the n^2 Functions can be LogN functions or NLogN function will make them faster.
    //For NLogN Functions it can be quicken if configured to be LogN Functions.
    //LogN functions are already as fast as they can be.
    srand(static_cast<unsigned int>(time(0)));
    int SIZE=100000;
    //Any Value to search
    int p=10;
    int btime;
    int etime;
    vector<short> data;
    //Initialize
    for(int i=0;i<SIZE;i++)
    {
        data.push_back(rand()%90+10);
    }
    btime=time(0);
    //Bubble Sort
    BubbleSort(data);
    etime=time(0);
    cout<<"Bubble Sort "<<etime-btime<<" Seconds"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<data.at(i)<<" ";
    }
    cout<<endl;
    data.clear();
    //Initialize
    for(int i=0;i<SIZE;i++)
    {
        data.push_back(rand()%90+10);
    }
    //Selection Sort
    btime=time(0);
    SelectionSort(data);
    etime=time(0);
    cout<<"Selection Sort "<<etime-btime<<" Seconds"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<data.at(i)<<" ";
    }
    cout<<endl;
    data.clear();
    //Initialize
    for(int i=0;i<SIZE;i++)
    {
        data.push_back(rand()%90+10);
    }
    //Heap Sort
    btime=time(0);
    makeHeap(data,data.size());
    HeapSort(data);
    etime=time(0);
    cout<<"Heap Sort "<<etime-btime<<" Seconds"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<data.at(i)<<" ";
    }
    cout<<endl;
    data.clear();
    //Initialize
    for(int i=0;i<SIZE;i++)
    {
        data.push_back(rand()%90+10);
    }
    //Merge Sort
    btime=time(0);
    mergeSort(data,0,data.size()-1);
    etime=time(0);
    cout<<"Merge Sort "<<etime-btime<<" Seconds"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<data.at(i)<<" ";
    }
    cout<<endl;
    data.clear();
    //Initialize
    for(int i=0;i<SIZE;i++)
    {
        data.push_back(rand()%90+10);
    }
    //Quick Sort
    btime=time(0);
    quickSort(data,0,data.size()-1);
    etime=time(0);
    cout<<"Quick Sort "<<etime-btime<<" Seconds"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<data.at(i)<<" ";
    }
    cout<<endl;
    cout<<endl;
    
}

void printVector(vector<short> v,int perLine)
{
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//O(n^2) Function
void BubbleSort(vector<short> &v)
{
    int n=v.size();
    //n times
    for(int i=0;i<n;++i)
    {
        //n times
        for(int j=0;j<n-1;++j)
        {
            if(v[j]>v[j+1])
            {
                int temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
            }
        }
    }
}

//O(n^2) Function
void SelectionSort(vector<short> &v)
{
    int mid,temp,n=v.size();
    //n times
    for(int i=0;i<n-1;++i)
    {
        mid=i;
        //n times
        for(int j=i+1;j<n;++j)
        {
            if(v[j]<v[mid])mid=j;
        }
        if(mid!=i)
        {
            temp=v[i];
            v[i]=v[mid];
            v[mid]=temp;
        }
    }
}

//O(nlogn) Function
void HeapSort(vector<short> &v)
{
    int temp,n=v.size();
    //n times
    for(int i=n-1;i>=1;--i)
    {
        temp=v[i];
        v[i]=v[0];
        v[0]=temp;
        //O(logn) Function
        makeHeap(v,i);
    }
}

//O(logn) Function
void makeHeap(vector<short> &v,int n)
{
    int temp,k,j;
    //Function halving the number of items each time
    for(int i=1;i<n;++i)
    {
        temp=v[i];
        k=(i-1)/2;
        j=i;
        while(j>0&&v[k]<temp)
        {
            v[j]=v[k];
            j=k;
            k=(j-1)/2;
        }
        v[j]=temp;
    }
}

//O(nlogn) Function
void mergeSort(vector<short> &v,int low,int high)
{
    int mid;
    //Function halving the number of items each time
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,high,mid);
    }
}

void merge(vector<short> &v,int low,int high,int mid)
{
    int i,j,k,c[v.size()];
    i=low;
    k=low;
    j=mid+1;
    //n times ?
    while(i<=mid&&j<=high)
    {
        if(v[i]<v[j])
        {
            c[k]=v[i];
            k++;
            i++;
        }
        else
        {
            c[k]=v[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        c[k]=v[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k]=v[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++){
        v[i]=c[i];
    }
}

//O(nlogn)
void quickSort(vector<short> &v,int left,int right)
{
    int i=left,j=right;
    int temp;
    //Function halving the number of items each time
    int pivot=v[(left+right)/2];
    //n times ?
    while(i<=j)
    {
        while(v[i]<pivot)i++;
        while(v[j]>pivot)j--;
        if(i<=j)
        {
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
    }
    if(left<j)quickSort(v,left,j);
    if(i<right)quickSort(v,i,right);
}

void problem5()
{
    //Person
    string test="MEL";
    int person=hash(test);
    //Generate 1000
    int collisions=0;
    int SIZE=3000;
    string store[SIZE];
    //Using Tree
    Trees tree;
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<SIZE;i++)
    {
        //Get 3 Random Letters into 1 string
        for(int j=0;j<1;j++)
        {
            char a=rand()%26+65;
            char b=rand()%26+65;
            char c=rand()%26+65;
            store[i].push_back(a);
            store[i].push_back(b);
            store[i].push_back(c);
        }
        tree.addLeaf(store[i]);
    }
    cout<<endl;
    tree.prstring();
    //Search
    float tstart=time(0);
    string check=tree.treeContains(test);
    float tend=time(0);
    //Format
    cout<<"Did you find a match: "<<check<<endl;
    cout<<"Average Search Time: "<<tstart-tend<<" Seconds"<<endl;
    cout<<endl;
}

void problem6()
{
    
}
 

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}