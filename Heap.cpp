#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  
class MaxHeap{   
   vector<int> h;
   vector<int> sorted;
   public:
   void insert(int data){
       if(h.empty()){
        h.push_back(data);       
        return;        
       }
       h.push_back(data);
       int i=h.size()-1,temp;
       while(i>0 && h[i]>h[(i-1)/2]){
                temp=h[i];
                h[i]=h[(i-1)/2];
                h[(i-1)/2]=temp;
                i=(i-1)/2;               
       }
       

   }

  void deletion(){
       if(h.empty()){
        cout<<"your maxheap is empty:"<<endl;
        return;
       }
       int max=h.front();
       h[0]=h.back();
       h.pop_back();
       int i=0;
       while((2*i+1)<h.size() && (h[i]<h[2*i+1] || h[i]<h[2*i+2])){
           if(2*i+2<h.size()){
               if(h[2*i+1]>h[2*i+2]){
                 int temp=h[i];
                 h[i]=h[2*i+1];
                 h[2*i+1]=temp;
                 i=2*i+1;
             }
             else{
                  int temp=h[i];
                  h[i]=h[2*i+2];
                  h[2*i+2]=temp;
                  i=2*i+2;
             }
           }
           else{
                int temp=h[i];
                 h[i]=h[2*i+1];
                 h[2*i+1]=temp;
                 i=2*i+1;
           }
            
       }
       sorted.push_back(max);
  }
  void show(){
      for(int i=0;i<sorted.size();i++){
          cout<<sorted[i]<<" ";
      }
  }

};
class MinHeap{   
   vector<int> h;
   vector<int> sorted;
   public:
   void insert(int data){
       if(h.empty()){
        h.push_back(data);
       
        return;        
       }
       h.push_back(data);
       int i=h.size()-1,temp;
       while(i>0 && h[i]<h[(i-1)/2]){
                temp=h[i];
                h[i]=h[(i-1)/2];
                h[(i-1)/2]=temp;
                i=(i-1)/2;
               
       }
       

   }

  void deletion(){
       if(h.empty()){
        cout<<"your maxheap is empty:"<<endl;
        return;
       }
       int max=h.front();
       h[0]=h.back();
       h.pop_back();
       int i=0;
       while((2*i+1)<h.size() && (h[i]>h[2*i+1] || h[i]>h[2*i+2])){
           if(2*i+2<h.size()){
               if(h[2*i+1]<h[2*i+2]){
                 int temp=h[i];
                 h[i]=h[2*i+1];
                 h[2*i+1]=temp;
                 i=2*i+1;
             }
             else{
                  int temp=h[i];
                  h[i]=h[2*i+2];
                  h[2*i+2]=temp;
                  i=2*i+2;
             }
           }
           else{
                int temp=h[i];
                 h[i]=h[2*i+1];
                 h[2*i+1]=temp;
                 i=2*i+1;
           }
            
       }
       sorted.push_back(max);
  }
  void show(){
      for(int i=0;i<sorted.size();i++){
          cout<<sorted[i]<<" ";
      }
  }

};


int main(){

    MinHeap m;
    m.insert(42);
    m.insert(5);
    m.insert(11);
    m.insert(52);
    m.insert(66);
    m.insert(41);
    m.insert(99);
    m.insert(4);
    m.insert(37);
    m.insert(21);
    m.insert(54);

    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.deletion();
    m.show();
    


}