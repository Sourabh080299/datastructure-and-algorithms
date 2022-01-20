#include<iostream>
#include<string>
using namespace std;
class stack{
    char a[100];
    int b[100];
    int top,size;
    public:
    stack(){
        top=-1;
        size=100;
    }
    void push(int data){
        if(top>=size){
         cout<<"stack is overflow:"<<endl;
        }
        else{
        top++;
        b[top]=data;        
        }   
    }
    void push(char data){
        if(top>=size){
         cout<<"stack is overflow:"<<endl;
        }
        else{
        top++;
        a[top]=data;        
        }   
    }
    void disply_char_satck(){
        for(int i=top;i>=0;i--){
            cout<<a[i]<<"|";
        }
        cout<<endl;
    }    
    void disply_int_satck(){
        for(int i=top;i>=0;i--){
            cout<<b[i]<<"|";
        }
        cout<<endl;
    }    
    char pop_char_satck(){
        if(top<0){
          cout<<"stack is empty:"<<endl;
        }
        else{
           char k=a[top];
           top--;
           return k;
          
        }
    }
    int pop_int_satck(){
        if(top<0){
          cout<<"stack is empty:"<<endl;
        }
        else{
           int k=b[top];
           top--;
           return k;
          
        }
    }
    char peek_char(){
         if(top<0){
          return '0';
        }
        else{
           return a[top];
        }
    }
    char peek_int(){
         if(top<0){
          return '0';
        }
        else{
           return b[top];
        }
    }
    void is_full(){
         if(top>=size){
          cout<<"yes stack is full:"<<endl;
        }
        else{
            cout<<"no, stack is not full"<<endl;
        }
    }
    bool is_empty(){
         if(top==-1){
         return true;
        }
        else{
           return false;
        }
    }
    bool not_empty(){
         if(top==-1){
         return false;
        }
        else{
           return true;
        }
    }
   void mid_point_char(){
       if(top==-1){
           cout<<"stack is empty!"<<endl;
       }
       else{
           if(top==0){
               cout<<"only one element is present in stack !"<<endl;
           }
           else{
               int k;
               k=top/2;
               cout<<a[k]<<" is mid point element!"<<endl;
           }
       }
   }
   void mid_point_int(){
       if(top==-1){
           cout<<"stack is empty!"<<endl;
       }
       else{
           if(top==0){
               cout<<"only one element is present in stack !"<<endl;
           }
           else{
               int k;
               k=top/2;
               cout<<b[k]<<" is mid point element!"<<endl;
           }
       }
   }
bool parenthesis_checker(string s){
    int l;
    l=s.length();
        stack c;
          for(int i=0;i<l;i++){
              cout<<s[i]<<endl;

              if(s[i]=='{' || s[i]=='[' || s[i]=='('){
               c.push(s[i]);
              }
              else{
                  if(c.is_empty()){
                      return false;
                  }
                 else{
                  if(s[i]=='}'){
                     while(c.peek_char()!='{' && c.not_empty()){
                         c.pop_char_satck();
                     }
                     c.pop_char_satck();
                 }
                 if(s[i]==']'){
                     while(c.peek_char()!='['  && c.not_empty()){
                         c.pop_char_satck();
                     }
                     c.pop_char_satck();
                 }
                 if(s[i]==')'){
                     while(c.peek_char()!='('  && c.not_empty()){
                         c.pop_char_satck();
                     }
                     c.pop_char_satck();
                 }                  
              }
          }
         
                 }
                  if(c.is_empty()){
              return true;
          }
          else{
              return false;}
              
          
           cout<<"..............";
           c.disply_char_satck();
    }

string reverse_string_using_stack(string s){
    stack c;
    for(int i=0;i<s.length();i++){
        c.push(s[i]);
    }
    for(int i=0;i<s.length();i++){
        s[i]=c.pop_char_satck();
    }
    return s;
}
int min_of_stack(){
    int min=b[top];
    for(int i=top;i>=0;i--){
     if(min>b[i]){
         min=b[i];
     }
    }
    return min;
}
int sec_max_of_stack(){
    int max=b[top],sec_max=0;
    for(int i=top;i>=0;i--){
     if(max<b[i]){
         max=b[i];
     }
    }
    for(int i=top;i>=0;i--){
      if(sec_max<b[i] && b[i]<max){
        sec_max=b[i];
        cout<<sec_max<<endl;
     }
    }
    
    return sec_max;
}
int* next_larger_element(int* arr,int n){
    int flag=0;
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
   for(int j=i+1;j<n;j++){
       if(arr[j]>arr[i]){
           arr[i]=arr[j];
           flag=1;
           goto l;
       }
   }
   l:
   if(flag==0){
        arr[i]=-1;
   }
   else{
       flag=0;
   }

}
return arr;
}
};
class two_stack_in_one_array{
    int b[100],size1,size2,top1,top2;
    public:
    two_stack_in_one_array(){
        top1=-1;
        size1=50;
        top2=50;
        size2=100;
    }
    void push1(int data){
         if(top1>size1){
            cout<<"stack1 is fully filled!"<<endl;
            }
         else{
             top1++;
             b[top1]=data;
             cout<<b[top1]<<" is inserted successfully in satck1"<<endl;
         }        
    }
    void push2(int data){
        if(top2>size2){
            cout<<"stack2 is fully filled!"<<endl;
        }
        else{
            top2++;
            b[top2]=data;
            cout<<b[top2]<<" is inserted successfully in satck2"<<endl;
        }
    }
    void pop1(){
         if(top1==-1){
            cout<<"stack1 is empty we can't pop!"<<endl;
            }
         else{
            cout<<b[top1]<<" is poped out from satck1"<<endl;
             top1--;
         }        
    }
    void pop2(){
        if(top2==50){
            cout<<"stack2 is fully filled!"<<endl;
        }
        else{
            cout<<b[top2]<<" is poped out from satck2"<<endl;
            top2--;
        }
    }

    void display1(){
    cout<<"elements of stack1"<<endl;
     for(int i=top1;i>=0;i--){
      cout<<b[i]<<"|";
     }
     cout<<endl;
    }


    void display2(){
    cout<<"elements of stack2"<<endl;
     for(int i=top2;i>=50;i--){
      cout<<b[i]<<"|";
     }
     cout<<endl;
    }
    void peek1(){
        if(top1==-1){
            cout<<"stack1 is empty!"<<endl;
        }
        else{
            cout<<b[top1]<<" is peek element"<<endl;
        }
    }
    void peek2(){
        if(top2==50){
            cout<<"stack2 is empty!"<<endl;
        }
        else{
            cout<<b[top2]<<" is peek element"<<endl;
        }
    }
    void isempty1(){
        if(top1==-1){
            cout<<"yes, stack1 is empty"<<endl;
        }
        else{
            cout<<"no, stack1 is not empty"<<endl;
        }
    }
    void isempty2(){
        if(top2==50){
            cout<<"yes, stack2 is empty"<<endl;
        }
        else{
            cout<<"no, stack2 is not empty"<<endl;
        }
    }
    void isfull1(){
        if(top1==50){
            cout<<"yes, stack1 is full"<<endl;
        }
        else{
            cout<<"no, stack1 is not full"<<endl;
        }
    }
    void isfull2(){
        if(top2==100){
            cout<<"yes, stack2 is full"<<endl;
        }
        else{
            cout<<"no, stack2 is not full"<<endl;
        }
    }

};

int main(){
    stack s1;
    int p[6]={8,7,5,10,12,3};
    s1.next_larger_element(p,6);
    for(int i=0;i<6;i++){
        cout<<" "<<p[i];
    }
}
