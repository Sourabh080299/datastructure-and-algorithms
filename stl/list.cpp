#include<iostream>
#include<list>
using namespace std;
void show(list<int> g){
    list<int>::iterator it;
    for(it=g.begin();it!=g.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    list<int> l1,l2;
    for(int i=0;i<10;i++){
        l1.push_back(i*2);
        l2.push_front(i*3);
    }
    l1.pop_back();
    l2.pop_back();
    l1.pop_front();
    l2.pop_front();
    cout<<"l1"<<endl;
    show(l1);
    cout<<"l2"<<endl;
    show(l2);
    cout<<"l1.front "<<l1.front()<<endl;
    cout<<"l2.back "<<l2.back()<<endl;
    

    
}