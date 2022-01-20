#include<iostream>
#include<stack>
#include<math.h>
#include "binnary_tree.h"
using namespace std;

class bst{
    public:
 struct node{
       int data;
       struct node* left;
       struct node* right;
 };

  struct node* root=NULL;
void create_bst(int x){     
     struct node* newnode=new struct node[sizeof(struct node)];
     newnode->right=NULL;
     newnode->left=NULL;
     newnode->data=x;
    if(root==NULL){
        root=newnode;
        return;
    }
    else{ 
         struct node* next,*curr;
         next=root;
         while(next!=NULL){
            curr=next;           
            if(x>next->data){
                next=next->right;
                if(next==NULL){
                    curr->right=newnode;
                }
            }
            else{
                next=next->left;
                if(next==NULL){
                    curr->left=newnode;
                }            
                }
           }
        } 
}
void inoreder(struct node* r){
    if(r==NULL){
        return;
    }
    inoreder(r->left);
    cout<<r->data<<" ";
    inoreder(r->right);
    }  
void preoreder(struct node* r){
    if(r==NULL){
        return;
    }
    cout<<r->data<<" ";
    preoreder(r->left);    
    preoreder(r->right);
    }  
struct node* search(int x){
     if(root==NULL){
         cout<<"tree is empty"<<endl;
        return NULL;
    }
    else if(root->data==x){
        cout<<x<<" data is present at "<<root<<" address"<<endl;
        return root;
         }
    else{
         struct node* temp=root;
         while(x!=temp->data){                      
            if(x>temp->data){temp=temp->right;}
            else{temp=temp->left;}
            if(temp==NULL){
                   cout<<"data is not present in the tree"<<endl;
                   return NULL;}}
            cout<<x<<" is present at "<<temp<<" address"<<endl;
            return temp;
        }
}
struct node* successor(struct node* r){
          if(r->right){
              r=r->right;
              while(r->left){
                  r=r->left;
              }
              return r;
          }         
            return NULL;
          
}
struct node* predecessor(struct node* r){
          if(r->left){
              r=r->left;
              while(r->right){
                  r=r->right;
              }
              return r;
          }         
            return NULL;
          
}
struct node* parent(struct node* r){
          if(r==root){
              return NULL;
          }
          else{
              struct node* temp,*pre;
              temp=root;
              while(temp->data!=r->data && temp!=NULL){
                  
                   pre=temp;
                   if(r->data>temp->data){                     
                      temp=temp->right;}
                   else{temp=temp->left;}}
                   
              if(temp){return pre; }
              else{return NULL;}
              
            
          }
          
}
struct node* inorder_successor(struct node* r){
          if(r->right){
              r=r->right;
              while(r->left){
                  r=r->left;
              }return r;}         
          else{
              struct node* temp=parent(r);
              if(temp){
                  while(temp!=root && temp->data<r->data){
                      temp=parent(temp);
                  }
                  if(temp->data>r->data){
                      return temp;
                  }
                  else{
                      cout<<"inorder successor is not define"<<endl;
                      return NULL;
                  }
              }
              else
              {   cout<<"inorder successor is not define"<<endl;
                  return NULL;
              }
        }          
}
struct node* inorderpredecessor(struct node* r){
          if(r->left){
              r=r->left;
              while(r->right){
                  r=r->right;
              }
              return r;
          }         
            else{ struct node* temp=parent(r);
              if(temp){while(temp!=root && temp->data>r->data){
                      temp=parent(temp);
                  }
                  if(temp->data<r->data){
                      return temp;
                  }
                  else{
                       cout<<"inorder predecessor is not define"<<endl;
                      return NULL;
                  } 
              }
               else{
                   cout<<"inorder predecessor is not define"<<endl;
                   return NULL;
               } }  }
struct node* delete_node(int x, struct node* temp,struct node* t=NULL){
    struct node* succ=successor(temp);
    if(succ){
        struct node* parent_succ=parent(succ);
        temp->data=succ->data;
        succ->data=x;
        delete_node(x,succ,parent_succ);
        
    }
    else{
        struct node* pre=predecessor(temp);
        if(pre){
            struct node* parent_pre=parent(pre);
            temp->data=pre->data;
            pre->data=x;
            // cout<<temp<<" "<<temp->data<<endl;
            // cout<<pre<<" "<<pre->data<<endl;
           delete_node(x,pre,parent_pre);          
        }
        else{
           if(t==NULL){
               t=parent(temp);
              if(t->left==temp){
               t->left=NULL;
               }
              else{
               t->right=NULL;
               }
           }
           else{
               if(t->left==temp){
               t->left=NULL;
               }
              else{
               t->right=NULL;
               }
           }          
           delete temp;
           return NULL;
        }        
    }     
}
void max(struct node* r){
    if(r==NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    else{
        if(r->right==NULL){
            cout<<"max element is "<<r->data<<endl;
        }
        else{
            while(r->right){
                r=r->right;
            }
            cout<<"max element is "<<r->data<<endl;
        }
    }
}
void min(struct node* r){
    if(r==NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    else{
        if(r->left==NULL){
            cout<<"min element is "<<r->data<<endl;
        }
        else{
            while(r->left){
                r=r->left;
            }
            cout<<"min element is "<<r->data<<endl;
        }
    }
}
bool isbst(struct node* r){
      if(r==NULL){
          cout<<"tree is empty"<<endl;
          return false;
      }
      else{
          if(r->left){
              if(r->left->data<=r->data && isbst(r->left)){
                  if(r->right){
                      if(r->right->data>r->data && isbst(r->right)){
                          return true;
                      }
                      else
                      { return false;
                      }                     
                  }
                  else{
                      return true;
                  }
              }else{
                  return false;
              }
          }else{
              if(r->right){
                      if(r->right->data>r->data && isbst(r->right)){
                          return true;
                      }
                      else
                      { return false;
                      }                     
                  }
                  else{
                      return true;
                  }
          }

      }
}

struct node* LCA(struct node* n1,struct node* n2){
         struct node* pn1,*pn2;
         pn1=n1;
         pn2=n2;
         while(pn1!=pn2){
               while(pn2!=NULL){
                   if(pn1==pn2){
                       return pn2;
                   }
                   pn2=parent(pn2);
               }
               pn1=parent(pn1);
               pn2=n2;
         }
}

struct node* Pre_to_Bst(int a[],int s,int e){
      struct node* newnode=new struct node[sizeof(struct node)];
      newnode->data=a[s];
      newnode->left=NULL;
      newnode->right=NULL;
      int i=s;
      while(a[i+1]<a[s]){
           i++;
      }
      if(s<e){
          newnode->left=Pre_to_Bst(a,s+1,i);
          newnode->right=Pre_to_Bst(a,i+1,e);
      }
      else{
          return newnode;
      }
      return newnode;     

} 

int* sort_array(int a[],int k){
    int flag=0;
    for(int i=0;i<k-2;i++){
           for(int j=0;j<k-2;j++){
               if(a[j]>a[j+1]){
                   int temp=a[j];
                   a[j]=a[j+1];
                   a[j+1]=temp;
                   flag=1;
               }
           }
           if(flag==0){
               return a;
           }
           else
           {
               flag=0;
           }
           
       }
       return a;
}
void rightrotation(struct node* r){
      struct node * temp=parent(r);
      if(temp){
          if(temp->left==r){
              temp->left=r->left;
              r->left=temp->left->right;
              temp->left->right=r;
              
          }
          else{
            
            temp->right=r->left;
            r->left=temp->right->right;
            temp->right->right=r;
            
          }
      }
      else{
          root=r->left;
          r->left=root->right;
          root->right=r;
      }
}
void leftrotation(struct node* r){
      struct node * temp=parent(r);
      if(temp){
          if(temp->left==r){
              temp->left=r->right;
              r->right=temp->left->right;
              temp->left->left=r;
              
          }
          else{
            temp->right=r->right;
            r->right=temp->right->left;
            temp->right->left=r;
            
          }
      }
      else{
          root=r->right;
          r->right=root->left;
          root->left=r;
      }
}

void leftrightrotation(struct node* r){
   struct node* temp=parent(r),*temp1,*temp2;
   temp1=r->left->right->left;
   temp2=r->left->right->right;
   if(temp){
       if(temp->right==r){
           
           temp->right=r->left->right;
           temp->right->left=r->left;
           temp->right->left->right=temp1;
           temp->right->right=r;
           r->left=temp2;
       }
       else{
          
           temp->left=r->left->right;
           temp->left->left=r->left;
           temp->left->left->right=temp1;
           temp->left->right=r;
           r->left=temp2;
       }
   }
   else{      
       root=r->left->right;
       root->left=r->left;
       root->right=r;
       root->left->right=temp1;
       r->left=temp2;
   }

}
void rightlefttrotation(struct node* r){
   struct node* temp=parent(r),*temp1,*temp2;
   temp1=r->right->left->left;
   temp2=r->right->left->right;
   if(temp){
       if(temp->right==r){           
           temp->right=r->right->left;
           temp->right->left=r;
           temp->right->right=r->right;
           temp->right->right->left=temp2;
           r->right=temp1;           
       }
       else{          
           temp->left=r->right->left;
           temp->left->left=r;
           temp->left->right=r->right;
           temp->left->right->left=temp2;
           r->right=temp1;
       }
   }
   else{      
       root=r->right->left;
       root->left=r;
       root->right=r->right;
       root->right->left=temp2;
       r->right=temp1;
   }

}
int maxoftwo(int l,int m){
     if(l>=m){
         return l;
     }
     else{
         return m;
     }
}
bool isblanced(struct node* r){
    if(r==NULL){
        return true;
    }
    int hl,hr,diff;
    hl=height(r->left);
    hr=height(r->right);
    diff=abs(hr-hl);
    if(diff<=1 && isblanced(r->left) && isblanced(r->right)){
        return true;
    }
    else{
        return false;
    }
}
int height(struct node* r){
    
    if(r==NULL){
        return -1;
    }
    return (maxoftwo(height(r->left),height(r->right))+1);
}
// void bst_to_blanced_bst(struct node* r){
//            if(r==NULL){
//                return;
//            }
//            int d,hr,hl;
//            hl=height(r->left);
//            hr=height(r->right);
//            d=abs(hl-hr);
//            if(!isblanced(r->left)){              
//               bst_to_blanced_bst(r->left);
//            }
//            if(!isblanced(r->right)){              
//                 bst_to_blanced_bst(r->right);                
//            }  
//            if(d>1){
//                 if(hl>hr){
//                    cout<<"....."<<r->data<<endl;
//                    rightrotation(r);
//                }
//                else{
//                    cout<<"....."<<r->data<<endl;
//                    leftrotation(r);
//                }
//            }        
// }

 struct node* blanced_bst(int a[],int s,int e){
    int mid =(s+e)/2;
    if(s>e){
        return NULL;
    }
    struct node* newnode=new struct node [sizeof(struct node)];
    newnode->data=a[mid];
    newnode->left=blanced_bst(a,s,mid-1);
    newnode->right=blanced_bst(a,mid+1,e);
    return newnode;
}
int* inorder_itrative(struct node* r,int &k)
{    int i=0;
     static int a[100];
    stack<struct node*> s;
    struct node* curr=r;
   while(!s.empty() || curr!=NULL){
       while(curr){
         s.push(curr);
        curr=curr->left;
       } 
         a[i]=s.top()->data;
          cout<<a[i]<<" ";
         i++;
         curr=s.top()->right;
         s.pop();         
        }
        k=i;
        return a;
}
int* addition_of_array(int a[],int b[],int l1,int l2,int &k){
    static int arr[100];
    for(int i=0;i<l1;i++){
          arr[i]=a[i];
    }
    int i=0;
    for(int j=l1;j<l2;j++){
          arr[j]=a[i];
          i++;
    }
    k=l1+l2;
    return arr;
}
int addition_of_two_bst(struct node* r1,struct node* r2,struct node* p){
            if(r1!=NULL && r2!=NULL){
                r1->data=r1->data+r2->data;
            }           
            if(r1->left!=NULL && r2->left!=NULL){                                  
                 r1->left->data=addition_of_two_bst(r1->left,r2->left,r1);
               }
            else{
                   if(r2->left!=NULL){
                       struct node* newnode=new struct node[sizeof(struct node)];
                       newnode->left=NULL;
                       newnode->right=NULL;
                       r1->left=newnode;
                       r1->left->data=addition_of_two_bst(r1->left,r2->left,r1);
                   }
               }                  
            if(r1->right!=NULL && r2->right!=NULL){
                 r1->right->data=addition_of_two_bst(r1->right,r2->right,r1);
               } 
            else{
                   if(r2->right!=NULL){
                       struct node* newnode=new struct node[sizeof(struct node)];
                       newnode->left=NULL;
                       newnode->right=NULL;
                       r1->right=newnode;
                       r1->right->data=addition_of_two_bst(r1->right,r2->right,r1);
                   }
               }                    
            return r1->data;

}

};

int main(){
    bst b,b1;
    b1.create_bst(4);
    b1.create_bst(3);
    b1.create_bst(5);
    b1.create_bst(2);
    b1.create_bst(6);
    b1.create_bst(1);
    b1.create_bst(7);

    b.create_bst(50);
    b.create_bst(21);
    b.create_bst(76);
    b.create_bst(4);
    b.create_bst(32);
    b.create_bst(2);
    b.create_bst(15);
    b.create_bst(3);
    b.create_bst(14);
    b.create_bst(100);
    b.create_bst(64);
    b.create_bst(52);
    b.create_bst(70);
    b.create_bst(83);
    b.create_bst(80);
    b.create_bst(87);  
    b.inoreder(b.root);   
    b.addition_of_two_bst(b.root,b1.root,NULL); 
    cout<<endl; 
    b.inoreder(b.root); 
     
        
    
    
    
    
}