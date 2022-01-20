#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* xor_next;
};

class bits_manipulation{
	public:
		unsigned char x=5,y=9;
		void bitwise_oprator(){
        cout<<"x & y->"<<(x & y)<<endl;
        cout<<"x | y->"<<(x | y)<<endl;
        cout<<"x ^ y->"<<(x ^ y)<<endl;
        cout<<"y>>1 ->"<<(y>>1)<<endl;
        cout<<"y<<1 ->"<<(y<<1)<<endl;
        x=~x;
        cout<<"~ x->"<<int(x)<<endl;
            
		}  
		
		int oddoccurance(){
		       vector<int> v {1,1,2,2,3,3,4,4,5,6,6,7,7,8,8,8,8,1,1};
		       int ans=0;
		       vector<int>::iterator it;
		       
		       for(it=v.begin();it!=v.end();it++){
		          ans=ans^(*it);
		       }
		       return ans;
		}
		
		void swaptwoNumber(){
			cout<<"x:"<<int(x)<<" "<<"y:"<<int(y)<<endl;
			x=x^y;
			y=x^y;
			x=x^y;
			cout<<"x:"<<int(x)<<" "<<"y:"<<int(y)<<endl;
		}
		
		node* Xor(node* x, node* y)
		{
			return reinterpret_cast<node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
		}
		
		node* XOR_DLL(){
			node *head=NULL,*prev,*curr,*next;
			cout<<"Enter number of element"<<endl;
			int n;
			cin>>n;
			while(n--){
				cout<<"enter data->";
				int a;
				cin>>a;
				node* newnode=new node();
				newnode->data=a;
				if(head==NULL){
					head=newnode;
					newnode->xor_next=NULL;
				}
				else{
					prev->xor_next=Xor(prev->xor_next,newnode);
					newnode->xor_next=prev;
				}
				prev=newnode;
		   }
		   curr=head;
		   prev=NULL;
		   while(curr!=NULL){
				cout<<curr->data<<"->";
				next=Xor(curr->xor_next,prev);
				prev=curr;
				curr=next;
			}
		}
		
		    
};




int main(){
   bits_manipulation b;
   b.XOR_DLL();
}




