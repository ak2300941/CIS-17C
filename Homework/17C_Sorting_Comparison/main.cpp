/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: Sorting Comparison
 * Created on November 16, 2014, 10:35 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Function Prototypes
void fillVector(vector<int> &,int);
void printVector(vector<int>,int);
void BubbleSort(vector<int> &);
void SelectionSort(vector<int> &);
void HeapSort(vector<int> &);
void makeHeap(vector<int> &,int);
void mergeSort(vector<int> &,int,int);
void merge(vector<int> &,int,int,int);
void quickSort(vector<int> &,int,int);

//Execution Begins Here
int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int> v;
    fillVector(v,100);
    cout<<"Randomized Vector"<<endl;
    printVector(v,10);
//    cout<<"Bubble Sorted Vector"<<endl;
//    BubbleSort(v);
//    printVector(v,10);
//    cout<<"Selection Sorted Vector"<<endl;
//    SelectionSort(v);
//    printVector(v,10);
//    cout<<"Heap Sorted Vector"<<endl;
//    makeHeap(v,v.size());
//    HeapSort(v);
//    printVector(v,10);
//    cout<<"Merge Sorted Vector"<<endl;
//    mergeSort(v,0,v.size()-1); 
//    printVector(v,10);
    cout<<"Quick Sorted Vector"<<endl;
    quickSort(v,0,v.size()-1);
    printVector(v,10);
    return 0;
}

void fillVector(vector<int> &v,int n)
{
    for(int i=0;i<n;++i){
        v.push_back(rand()%90+10);
    }
}

void printVector(vector<int> v,int perLine)
{
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//O(n^2) Function
void BubbleSort(vector<int> &v)
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
void SelectionSort(vector<int> &v)
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
void HeapSort(vector<int> &v)
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
void makeHeap(vector<int> &v,int n)
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
void mergeSort(vector<int> &v,int low,int high)
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

void merge(vector<int> &v,int low,int high,int mid)
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
void quickSort(vector<int> &v,int left,int right)
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