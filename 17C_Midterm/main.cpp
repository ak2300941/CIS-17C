/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Purpose: Midterm 17C
 * Created on November 6, 2014, 9:06 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <list>
using namespace std;

//Class for Problem 6
class statClass{
   public:
       statClass();
       void Listmin(list<int>);
       void Listmax(list<int>);
       void Listavg(list<int>);
       void Listmode(list<int>);
       int getMin();
       int getMax();
       float getAvg();
       map<int, int> getMode();
   private:
       int min;
       int max;
       float avg;
       map<int, int> mode;
};
statClass *stat(list<int>);

//Function Prototypes
void Menu();
int getN();
void def(int);
//Problem 1
void problem1();
void fillVec(vector<int> &,int);
void prntVecA(vector<int>,int);
void prntVecB(vector<int> *,int);
vector<int> *top(vector<int>,int);
//Problem 2
void problem2();
vector<int> *mode(vector<int>);
//Problem 8
void problem3();
float tanR(float);
//Problem 9
void problem4();
float hRec(float);
float gRec(float);
//Problem 6
void problem5();
void fillList(list<int> &,int);
void prntList(list<int>,int);

//Execution Begins Here
int main(int argc, char** argv) {
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
        default:   def(inN);}
    }while(inN>=1&&inN<=5);
    return 0;
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1 (15pts)"<<endl;
    cout<<"Type 2 for problem 2 (20pts)"<<endl;
    cout<<"Type 3 for problem 3 (15pts)"<<endl;
    cout<<"Type 4 for problem 4 (25pts)"<<endl;
    cout<<"Type 5 for problem 5 (25pts)"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    vector<int> a;
    vector<int> *b=new vector<int>;
    int p=30;
    //Fill Vector (Enter SIZE on second slot)
    fillVec(a,100);
    //Print Vector
    prntVecA(a,10);
    //Top Function
    b=top(a,p);
    //Print Vector
    prntVecB(b,10);
    //Delete Vector
    b->erase(b->begin(),b->end());
    delete b;
}

void fillVec(vector<int> &a,int size){
    for(int i=0;i<size;++i){
        a.push_back(rand()%90+10);
    }
}

void prntVecA(vector<int> a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();++i){
        cout<<a.at(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntVecB(vector<int> *b,int perLine){
    cout<<endl;
    for(int i=0;i<b->size();++i){
        cout<<b->at(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

vector<int> *top(vector<int> a,int top){
    vector<int> *temp=new vector<int>;
    for(int i=0;i<top;i++){
        temp->push_back(a.at(i));
    }
    return temp;
}

void problem2(){
    vector<int> a;
    vector<int> *b=new vector<int>;
    //Fill Vector
    fillVec(a,100);
    //Print Vector
    prntVecA(a,10);
    //Sort
    sort(a.begin(),a.end());
    //Print Sorted Vector
    prntVecA(a,10);
    //Mode Function
    b=mode(a);
    //Print Mode Vector
    prntVecB(b,10);
    cout<<endl;
    //Delete Vector
    b->erase(b->begin(),b->end());
    delete b;
}

vector<int> *mode(vector<int> a){
    vector<int> *temp=new vector<int>;
    int count=1,max=1,number;
    for(int i=1;i<a.size();i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max){
                max=count;
                number=a.at(i);
            }
        }
        else count=1;
    }
    for(int i=0;i<max;i++){
        temp->push_back(number);
    }
    return temp;
}


void problem3(){
    float angDeg=100;
    float angRad=angDeg*atan(1)/45;
    cout<<"Angle = "<<angDeg<<" tan = "<<tan(angRad)<<" our tan = "<<tanR(angRad)<<endl;
    cout<<endl;
}

float tanR(float angR){
    float epsilon=1e-2; //Accuracy to 2 decimal places
    //Taylor Series
    if(angR>-epsilon&&angR<epsilon)return angR+angR*angR*angR/3;
    //Given tan2x Function
    return 2*(tanR(angR/2))/(1-(tanR(angR/2)*(tanR(angR/2))));
}

void problem4(){
    float x=3;
    cout<<endl;
    cout<<"H(2x): "<<hRec(x)<<endl;
    cout<<"G(2x): "<<gRec(x)<<endl;
    cout<<endl;
}

float hRec(float x){
    float epsilon=1e-6;
    if(x>-epsilon&&x<epsilon)return x+x*x*x/6;
    return 2*hRec(x/2)*gRec(x/2);
}

float gRec(float x){
    float epsilon=1e-6;
    if(x>-epsilon&&x<epsilon)return 1+x*x/2;
    return 1+2*(hRec(x/2)*hRec(x/2));
}

void problem5(){
    list<int> a;
    fillList(a,30); //Size 30
    prntList(a,10); //PerLine is 10
    statClass *k=stat(a);
    map<int,int> mode=k->getMode();
    cout<<"Min: " <<k->getMin()<<endl;
    cout<<"Max: " <<k->getMax()<<endl;
    cout<<"Average: "<<k->getAvg()<<endl;
    cout<<"Mode Data: "<<endl;
    map<int,int>::iterator i;
    for(i=mode.begin();i!=mode.end();++i){
        cout<<i->first<<" frequency "<<i->second<<endl;
    }
    cout<<endl;
}

void fillList(list<int> &a,int size){
    for(int i=0;i<size;++i){
        a.push_back(rand()%90+10);
    }
}

void prntList(list<int> a,int perLine){
    cout<<endl;
    int index=0;
    for(int i=0;i<a.size();++i){
        cout<<a.front()<<" ";
        a.push_back(a.front());
        a.pop_front();
        index++;
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

statClass *stat(list<int> a){
    statClass *k = new statClass;
    k->Listavg(a);
    k->Listmax(a);
    k->Listmin(a);
    k->Listmode(a);
    return k;
}

//Class Functions
statClass::statClass(){
    
}


void statClass::Listmin(list<int> a){
    min=a.front();
    a.erase(a.begin());
    for(int i=1;i<a.size();++i){
        if(min>a.front())
            min=a.front();
        //Delete
        a.erase(a.begin());
    }
}

void statClass::Listmax(list<int> a){
    max=a.front();
    a.erase(a.begin());
    for(int i=1;i<a.size();++i){
        if(max<a.front())
            max=a.front();
        //Delete
        a.erase(a.begin());
    }
}

void statClass::Listavg(list<int> a){
    float sum=0;
    for(int i=0;i<a.size();++i) {
        sum=sum+a.front();
        a.erase(a.begin());
    }
    avg=sum/a.size();
}

void statClass::Listmode(list<int> a){
    //Beginning have to be 0 because  then the first find would be 1
    mode[a.front()]=0;
    bool check=false;
    for(int i=0;i<a.size();++i){
        //Check if list is in map
        if(mode.find(a.front())!=mode.end()){
            check=true;
            mode.find(a.front())->second++;
        }else
            check=false;
        //If it doesn't exist on map, initialize to 1 (Since found)
        if(check==false){
            mode[a.front()]=1;
        }
        a.erase(a.begin());
    }
}

int statClass::getMin(){
    return min;
}

int statClass::getMax(){
    return max;
}

float statClass::getAvg(){
    return avg;
}

map<int,int> statClass::getMode(){
    return mode;
}


