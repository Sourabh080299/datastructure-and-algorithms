#include<bits/stdc++.h>
using namespace std;

class tree{

    struct node{
                    int data;
                    struct node* left,*right; 
            };

    public:

    struct node* root;
    struct node* insertion(int key){

        struct node* newnode= new struct node[sizeof(struct node)];
        newnode->data=key;
        newnode->left=newnode->right=NULL;
        return newnode;

    }
    void preorder(struct node* r){
       if(r==NULL){
           return ;
       }
       cout<<r->data<<" ";
       preorder(r->left);
       preorder(r->right);
       return ;
    }
    void postorder(struct node* r){        
       if(r==NULL){
           return ;
       }      
       postorder(r->left);
       postorder(r->right);
       cout<<r->data<<" ";
       return ;
    }
    void inorder(struct node* r){
       if(r==NULL){
           return ;
       }      
       inorder(r->left);
       cout<<r->data<<" ";
       inorder(r->right);
       return ;
    }
    void levelorder(struct node* r){
       queue<struct node*> q;
       q.push(r);
       while(!q.empty()){
         if(q.front()->left){
             q.push(q.front()->left);
         }
         if(q.front()->right){
             q.push(q.front()->right);
         }
         cout<<q.front()->data<<" ";
         q.pop();         
       }
    }
    void reverse_levelorder(struct node* r){
       queue<struct node*> q;
       stack<int> p;
       q.push(r);
       while(!q.empty()){
         if(q.front()->left){
             q.push(q.front()->left);
         }
         if(q.front()->right){
             q.push(q.front()->right);
         }
         p.push(q.front()->data);
         q.pop();         
       }
       while(!p.empty()){
            cout<<p.top()<<" ";
            p.pop();
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
int height(struct node* r){
    if(r==NULL){
        return 0;
    }
    else{
        return maxoftwo(height(r->left),height(r->right))+1;
    } 
}
int diameter(struct node* r){
    if(r==NULL){
        return 0;
    }
    int lheight=height(r->left);
    int rheight=height(r->right);
    int ldiameter=diameter(r->left);
    int rdiameter=diameter(r->right);
    return maxoftwo(lheight+rheight+1,maxoftwo(ldiameter,rdiameter));
}
int diameter1(struct node* r,int* height){
    if(r==NULL){
        *height=0;
        return 0;
    }
    int rh=0,lh=0;
    int ld=0,rd=0;
    ld=diameter1(r->left,&lh);
    rd=diameter1(r->right,&rh);
    *height=maxoftwo(lh,rh)+1;
    return maxoftwo(lh+rh+1,maxoftwo(ld,rd));
}
struct node* mirror(struct node* r){
    struct node* p;
     if(r==NULL){
         return NULL;
     }
     p=r->left;
     r->left=r->right;
     r->right=p;
     mirror(r->left);
     mirror(r->right);
     return r;
}
void postorder_itrative(struct node* r){
    stack<struct node*> s;
    stack<int> p;
    s.push(r);
    struct node* curr;
   while(!s.empty()){
        curr=s.top();
        s.pop();
        p.push(curr->data);
        if(curr->left){
           s.push(curr->left);
        }
        if(curr->right){
            s.push(curr->right);
        }
   }
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
        k=i+1;
        return a;
}
void preorder_itrative(struct node* r){
    stack<struct node*> s;
    s.push(r);
    struct node* curr;
   while(!s.empty()){
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right){
           s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
   }
}
void left_view(struct node* r){
    queue<struct node*> q;
    struct node* curr=r;
    q.push(r);
    q.push(NULL);
    cout<<r->data<<" ";
    while(!q.empty()){
     if(q.front()==NULL){
       q.pop();
       cout<<q.front()->data<<" ";
       if(q.front()){
       q.push(NULL);
       }      
     }
     else{
         if(q.front()->left){
         q.push(q.front()->left);
         }
        if(q.front()->right){
         q.push(q.front()->right);
         }        
         q.pop();
     }cout<<"done";
    }cout<<"done.........";
}
void right_view(struct node* r){
    queue<struct node*> q;
    struct node* curr=r;
    q.push(r);
    q.push(NULL);
    cout<<r->data<<endl;
    while(!q.empty()){
     if(q.front()==NULL){
       q.pop();
       cout<<q.front()->data<<" ";
       cout<<endl;
       if(q.front()){
       q.push(NULL);
       }      
     }
     else{
        if(q.front()->right){
         q.push(q.front()->right);
         } 
         if(q.front()->left){
         q.push(q.front()->left);
         }        
         q.pop();
     }
    }
}
void bottom_view(struct node* r){
    queue<struct node*> q;
    q.push(r);
    struct node* curr=r;
    while(!q.empty()){
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        if(q.front()->left==NULL && q.front()->right==NULL){
            cout<<q.front()->data<<" ";
            q.pop();
        }else{
            q.pop();
        }
    }
}
void get_vertical_view(struct node* r,int hd,map<int, vector<int> > &m){
          if(r==NULL){
              return;}
          m[hd].push_back(r->data);
          get_vertical_view(r->left,hd-1,m);         
          get_vertical_view(r->right,hd+1,m);
          return;        
}
void print_vertical_view(struct node* r){
    map<int, vector<int> > m1;
    get_vertical_view(r,0,m1);
     map<int,vector<int> >::iterator i1=m1.begin();
     for(i1;i1!=m1.end();i1++){
         for(int i=0;i<i1->second.size();i++){
             cout<<i1->second[i]<<" ";
         }
      cout<<endl;
     }
}
void print_bottom_view(struct node* r){
    map<int, vector<int> > m1;
    get_vertical_view(r,0,m1);
     map<int,vector<int> >::iterator i1=m1.begin();     
     for(i1;i1!=m1.end();i1++){         
            cout<<i1->second[i1->second.size()-1]<<" ";
     }
    
}
//O(n^2)
void zigzag_trzversal(struct node* r){
    int count=0;
    queue<struct node*> q;
    stack<struct node*> s;
    if(r==NULL){
        return;
    }
    else{
        q.push(r);
        while(!q.empty()){
            while(!q.empty()){
            s.push(q.front());
            cout<<q.front()->data<<" ";
            q.pop();
            }
            while(!s.empty()){
                 if(count%2==0){
                   if(s.top()->right){
                    q.push(s.top()->right);
                     }
                   if(s.top()->left){
                    q.push(s.top()->left);
                    }  
                   }
                else{
                  if(s.top()->left){
                    q.push(s.top()->left);
                    }
                   if(s.top()->right){
                   q.push(s.top()->right);
                }
            }  
             s.pop();                      
            }          
            count++;           
        }
    }   
}
//O(n)
void zigzag_trzversal1(struct node* r){
    int count=0;
    stack<struct node*> curr_level;
    stack<struct node*> next_level;
    stack<struct node*> temp;
    if(r==NULL){
        return;
    }
    else{
        curr_level.push(r);
        while(!curr_level.empty() or !next_level.empty()){
             
              if(count%2==0){
                   cout<<curr_level.top()->data<<" "; 
                   if(curr_level.top()->left){
                    next_level.push(curr_level.top()->left);
                   }
                   if(curr_level.top()->right){
                    next_level.push(curr_level.top()->right);
                    }
                    curr_level.pop();
                    if(curr_level.empty()){
                        count++;  
                    }
               }
               else{
                   cout<<next_level.top()->data<<" "; 
                   if(next_level.top()->right){
                    curr_level.push(next_level.top()->right);
                    }
                    if(next_level.top()->left){
                    curr_level.push(next_level.top()->left);
                   }
                    next_level.pop();
                    if(next_level.empty()){
                        count++;  
                    }
               }
                     
        }
    }   
}
   
int height_tree(struct node* r){
    if(r==NULL){
        return -1;
    }
    return maxoftwo(height_tree(r->left),height_tree(r->right))+1;
}  

bool isblanced(struct node* r){
    if(r==NULL){
        return true;
    }
    int hl,hr,diff;
    hl=height_tree(r->left);
    hr=height_tree(r->right);
    diff=abs(hr-hl);
    if(diff<=1 && isblanced(r->left) && isblanced(r->right)){
        return true;
    }
    else{
        return false;
    }
}

void get_digonal_traversal(struct node* r,map<int ,vector<int> > &m,int hd,int vd){
        if(r==NULL){
            return;
        }
       int f=abs(hd-vd);
       m[f].push_back(r->data);
       get_digonal_traversal(r->left,m,hd-1,vd+1);
       get_digonal_traversal(r->right,m,hd+1,vd+1); 
       return;   
}

void print_digonal_view(struct node* r){
    map<int, vector<int> > m1;
    get_digonal_traversal(r,m1,0,0);
    map<int,vector<int> >::iterator i1=m1.begin();
     for(i1;i1!=m1.end();i1++){
         for(int i=0;i<i1->second.size();i++){
             cout<<i1->second[i]<<" ";
         }
      cout<<endl;
     }
}

struct node* Binary_to_bst(struct node* r,int a[]){
    int i=0;
    stack<struct node*> s;
    struct node* curr=r;
   while(!s.empty() || curr!=NULL){
       while(curr){
         s.push(curr);
        curr=curr->left;
       } 
         
         cout<<s.top()->data<<" ";
         s.top()->data=a[i];
         i++;
         curr=s.top()->right;
         s.pop();         
        }
        return r;   
}


// struct node* construct_tree_usnig_pstring(string s,int k){
//       struct node* newnode= new struct node[sizeof(struct node)]; 
//       newnode->left=NULL;
//       newnode->right=NULL;
//       newnode->data=s[k];
//       if(s[k+1]=='('){
//           k++;
//           newnode->left=construct_tree_usnig_pstring(s,k+1);
//       }
//       if(s[k+1]==')'){
//           return newnode;
//       }
//       if(k+4=='('){
//           newnode->right=construct_tree_usnig_pstring(s,k+5);  
//       }
//       if(k+8=="("){
          
//       } 
// }

    };


// int main(){
//     tree t;
//     t.root=t.insertion(1);
//     t.root->left=t.insertion(2);
//     t.root->right=t.insertion(3);
//     t.root->left->left=t.insertion(4);
//     t.root->left->left->right=t.insertion(9);
//     t.root->left->left->left=t.insertion(8);
//     t.root->left->right=t.insertion(5);
//     t.root->left->right->left=t.insertion(10);
//     t.root->left->right->right=t.insertion(11);
//     t.root->right->left=t.insertion(6);
//     t.root->right->left->left=t.insertion(12);
//     t.root->right->left->right=t.insertion(13);
//     t.root->right->right=t.insertion(7);
//     t.root->right->right->right=t.insertion(15);
//     t.root->right->right->left=t.insertion(14);
   
    
// }