#include<iostream>
using namespace std;
class number{
    int a;
    public:
    number(){
        a=0;
    }
    void setdata(int x){
        a=x;
    }
    void showdata(){ cout<<a<<endl;}
       
    
    number operator ++(){
        number temp;
       
       temp.a=++a; 
      return temp;     
    }
    number operator --(){
         number temp;
        temp.a=--a;
      return temp;      
    }
    number operator ++(int){
          number temp;
          temp.a=a;
          ++a;          
      return temp;     
    }
    number operator --(int){
         number temp;
         temp.a=a;
         --a;
         
      return temp;      
    }
};

int main(){
   number n,n1,n2,n3,n4;
   n.setdata(5);   
   cout<<">>>>>>>>>>>."<<endl;
    n.showdata();
    n1=++n;
    cout<<">>>>>>>>>>>."<<endl;
     n1.showdata();
     n.showdata();
      n2=--n;
     cout<<">>>>>>>>>>>."<<endl;
      n2.showdata();
      n.showdata();
       n3=n++;
      cout<<">>>>>>>>>>>."<<endl;
       n3.showdata();
       n.showdata();
       n4=n--;
       cout<<">>>>>>>>>>>."<<endl;
        n4.showdata();
        n.showdata();


}