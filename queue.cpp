#include<iostream>
using namespace std;
class queue{
  int a[10],size=10;
  int front=-1,back=-1;
  public:
 void enqueue(int data){
     if(back>=size){
         cout<<"queue is fully filled:"<<endl;
     }
     else if(front==back==-1){
         front++;
         back++;
         a[front]=data;
     }
     else{
         back++;
         a[back]=data;
     }
 }
 void dequeue(){
    if(front==back==-1){
        cout<<"queue is empty:"<<endl;
    }
    else if(front==back){
        cout<<a[front]<<endl;
        front=back=-1;
    }
    else{
        cout<<a[front]<<endl;
        front++;
    }
 }
};

int main(){
    queue q1;
}