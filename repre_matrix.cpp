#include<iostream>
using namespace std;
class complex{    
    int a,b;
    public:
    static int d;
    complex(){
        a=0;
        b=0;
    }
    complex(int x){
        a=x;
        b=0;
    }
    complex(int x,int y){
        a=x;
        b=y;
    }
    static void func();
    void setdata(int x , int y){
        a=x;
        b=y;
    }
    void showdata(){
        cout<<"a+ib="<<a<<"+"<<b<<"i"<<endl;
    }
    complex operator +(complex &c){
        complex temp;
        temp.a=c.a+a;
        temp.b=c.b+b;
        return temp;
    }
    complex operator -(complex &c){
        complex temp;
        temp.a=a-c.a;
        temp.b=b-c.b;
        return temp;
    }
    complex operator -(){
        complex temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
    }
    
};
int complex:: d=5;
void complex:: func(){
cout<<"this is from static function and this from static variable:"<<d<<endl;
}
int main(){
    complex c1(5,4),c2=complex(9),c3=6,c4;
    c1.showdata();
    c2.showdata();
    c3=-c3;
    c3.showdata();
    c4=c1+c2;
    c4=-(c1-c2);
    c4.showdata();
    complex::func();
    cout<<complex::d<<endl;
}