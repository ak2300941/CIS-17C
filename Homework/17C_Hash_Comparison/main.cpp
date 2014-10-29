/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Created on October 26, 2014, 2:56 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Function Prototypes
char getRandom(char *,int);
int linearSearch(char *,int);
int binarySearch(char *,int);
void sort(char *,int);
unsigned int RSHash(string);

int main(int argc, char** argv) {
    int SIZE=20;
    long long N=10;
    char array[SIZE];
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Generate a random string
    getRandom(array,SIZE);
    cout<<"Random String: "<<array<<endl;
    //Linear Search
    int t1start=time(0);
    for(int i=0;i<N;i++){
        linearSearch(array,SIZE);
    }
    int t1end=time(0);
    cout<<"Linear Search Time Taken = "<<t1end-t1start<<endl;
    //Binary Search (needs to be sorted first)
    sort(array,SIZE);
    cout<<"Sorted String: "<<array<<endl;
    int t2start=time(0);
    for(int i=0;i<N;i++){
        binarySearch(array,SIZE);
    }
    int t2end=time(0);
    cout<<"Binary Search Time Taken = "<<t2end-t2start<<endl;
    //Hash Function (first convert to string)
    string brray=string(array);
    int t3start=time(0);
    N=100000000;
    for(int i=0;i<N;i++){
        RSHash(brray);
    }
    int t3end=time(0);
    cout<<"Hash Time Taken = "<<t3end-t3start<<endl;
    
    return 0;
}

unsigned int RSHash(string str){
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;

    for(std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }

    return (hash & 0x7FFFFFFF);
}

void sort(char *a,int l){
    //Find the minimum at this starting position
    for(int i=0;i<l-1;i++){
        //Swap the larger values as you go down the list
        for(int j=i+1;j<l;j++){
            //Check for swap
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
}

int binarySearch(char *a,int l){
    //Find numbers 1~9
    //int find=1+rand()%9;
    int find=1;
    int first=0;
    int last=l-1;
    int middle;
    int position=-1;
    bool found=false;
    while(!found&&first<=last){
        middle=(first+last)/2;
        if((a[middle]-48)==find){
            found=true;
            position=middle;
        }
        else if((a[middle]-48)>find){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
        return position;
    }
}

int linearSearch(char *a, int l){
    //Find numbers 1~9
    int find=1+rand()%9;
    int first=0,
        last=l-1,
        middle,
        position=-1;
    bool found=false;
    while(!found&&first<=last){
        middle=(first+last)/2;
        if((a[middle]-48)==find){
            found=true;
            position=middle;
        }
        else if((a[middle]-48)>find){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
        return position;
    }
}

char getRandom(char *a,int l){
    static const char alphanum[]=
        "0123456789";
        //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        //"abcdefghijklmnopqrstuvwxyz";
        //"abcdefghij";
    for(int i=0;i<l;i++){
        a[i]=alphanum[rand()%(sizeof(alphanum)-1)];
    }
    a[l]=0;
}



