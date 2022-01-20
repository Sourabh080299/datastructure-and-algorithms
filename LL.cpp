#include<iostream>
#include<math.h>
using namespace std;

class Link_List{
public:
struct node{
    int data;
    struct node * next;
}*head=NULL,*newnode,*temp,*previ,*next1,*temp1;
    int size;
struct node* create_linklist(){
        int n;        
        cout<<"Enter size of linked list:"<<endl;
        cin>>size;
        n=size;
        cout<<"enter "<<n<<" elements:"<<endl;
        while(n--){
            newnode=new struct node[sizeof(struct node)];
            newnode->next=NULL;
            cin>>newnode->data;
            if(head==NULL){
             head=newnode;
             temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
        }
    cout<<"linked list created successfully:"<<endl<<endl;
     return head;
    }

struct node* reverse_LL_itratative(){
    previ=head;
    temp=previ->next;
    previ->next=NULL;
    while(temp->next!=NULL){
        next1=temp->next;
        temp->next=previ;
        previ=temp;
        temp=next1;
    }
    head=temp;
    temp->next=previ;
    cout<<"linked list reversed successfully:"<<endl<<endl;    
}
void reverse_LL_recursive(struct node* previ,struct node* temp,struct node* next1){
    temp->next=previ;
    if(next1!=NULL){
        reverse_LL_recursive(temp,next1,next1->next);
    }
   else{
       head->next=NULL;
       head=temp;
   }     
}

struct node* reverse_LL_ingroup(){
    int k;
    cout<<"enter numbers of elements in group:"<<endl;
    cin>>k;
    cout<<k<<" elements of linked list reversed successfully using group method:"<<endl<<endl;    
    previ=head;
    temp=previ->next;
    while(--k){
        next1=temp->next;
        temp->next=previ;
        previ=temp;
        temp=next1;
    }
    head->next=next1;
    head=previ;    
}
void display(){
    temp=head;
    while(temp!=NULL){
        cout<<"|"<<temp->data<<"|"<<temp->next<<"|->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
     cout<<endl<<"linked list display successfully:"<<endl<<endl;
}
bool loop(){
    temp=head;
    int n=size;
    while(--n){
        temp=temp->next;
    }
    if(temp->next==NULL){
        return false;
    }
    else{
        return true;
    }
}
void delete_loop(){
    temp=head;
    int n=size;
    while(--n){
        temp=temp->next;
    }
    if(temp->next!=NULL){
        temp->next=NULL;
    }
}
void start_point_loop(){
    temp=head;
    int n=size;
    while(--n){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"there is no loop:"<<endl<<endl;  }
    else{
        cout<<"data at starting point of loop is:"<<temp->next->data<<endl<<"and address of starting point is:"<<temp->next<<endl<<endl;
    }
}

void remove_duplicat_sorted_LL(){
    temp=head;
    while(temp->next!=NULL){
        if(temp==head){
            if(temp->data==temp->next->data){
                head=temp->next;
                delete temp;
                temp=head;
                size--;
            }
            else{
                temp=temp->next;
            }
        }
        else{
             if(temp->data==temp->next->data){
                next1=temp->next;
                temp->next=temp->next->next;
                delete next1;
                size--;
            }
            else{
                temp=temp->next;
            }
        }
    }
    cout<<"remove_duplicat_ from sorted _LL successfully:"<<endl<<endl;
}
void remove_duplicat_unsorted_LL(){
    temp=head;
    while(temp->next!=NULL){
        cout<<"enter1"<<endl;
       temp1=temp->next;
       while(temp1->next!=NULL){
            cout<<"enter2"<<endl;
          if(temp==head){
              if(temp1->data==temp->data){
                  head=head->next; 
                  delete temp;
                  temp=head;
              }
          }
          else{
              if(temp1->data==temp->data){
                  previ->next=temp->next;
                  delete temp;
                  temp=previ->next;
                  temp1=temp->next;
              }
          }
          temp1=temp1->next;
       }
        previ=temp;
        temp=temp->next;
    }   
    cout<<"remove_duplicat_ from sorted _LL successfully:"<<endl<<endl;
}
void last_shift_to_first(){
    temp=head;
    while(temp->next!=NULL){
        previ=temp;
        temp=temp->next;
    }
    previ->next=NULL;
    temp->next=head;
    head=temp;
    cout<<"last element shift to first successfully:"<<endl<<endl;    
}

void add_one_to_last(){
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->data=temp->data+1;
    cout<<"last element incremented successfully:"<<endl<<endl;    
}

int LL_to_number(){
  temp=head;
  int num=0,t=pow(10,size-1);
  while(temp!=NULL){
    num+=t*temp->data;
    t=t/10;
    temp=temp->next;
  }
  return num;
}

void create_LL_using_num(int n){
        int k;
        while(n){
            k=n%10;
            newnode=new struct node[sizeof(struct node)];
            newnode->next=NULL;
            newnode->data=k;
            if(head==NULL){
             head=newnode;
             temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            n=n/10;
        }
    cout<<"linked list created using number successfully:"<<endl<<endl;
} 

Link_List add_two_numbers(Link_List a,Link_List b){
   Link_List c;
   int n1,n2,n3;
   n1=a.LL_to_number();
   n2=b.LL_to_number();
   n3=n1+n2;
   c.create_LL_using_num(n3);
   c.reverse_LL_itratative();
   return c;
        
}
Link_List intersection_sorted_LL(Link_List a,Link_List b){
   Link_List c;
   int n1,n2,n3,k,p=0,q;
   a.remove_duplicat_sorted_LL();
   b.remove_duplicat_sorted_LL();
   n1=a.LL_to_number();
   n2=b.LL_to_number();
   q=n2;
   while(n1){
       n2=q;
       while(n2){
         if(n1%10==n2%10){
            k=pow(10,p);
            n3+=(n1%10)*k;
            p++; 
         }
         n2=n2/10;
       }
       n1=n1/10;
   }
   c.create_LL_using_num(n3);
   return c;
        
}

void creation_intersecting_LL(Link_List a,Link_List b,Link_List c){      
       temp=a.head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=c.head;
       temp=b.head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=c.head;
}

int intersection_point(Link_List a,Link_List b){
     int k;
     k=a.size;
     temp=a.head;
     while(k--){
         temp=temp->next;
     }
     k=b.size;
     previ=b.head;
      while(k--){
         previ=previ->next;
     }
     if(previ==temp && previ!=NULL){
         return temp->data;
     }
     else{
         return 0;
     }
}

void push(int d){
    newnode=new struct node[sizeof(struct node)];
    newnode->data=d;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{ 
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

Link_List merge_two_sorted_LL(Link_List a,Link_List b){
    struct node* l1,*l2;
    Link_List c;
    l1=a.head;
    l2=b.head;
    while(l1!=NULL && l2!=NULL){
        if(l1->data>=l2->data){
           c.push(l2->data);
           l2=l2->next;
        }
        else{
            c.push(l1->data);
            l1=l1->next;
        }
    }
    if(l2!=NULL){
      while(l2!=NULL){
           c.push(l2->data);
           l2=l2->next;
      }
    }
    if(l1!=NULL){
           while(l1!=NULL){
           c.push(l1->data);
           l1=l1->next;
                  }
    }
    return c;

}

struct node* mid_point_of_LL(){
    cout<<"enter"<<endl;
      struct node* f,*s;
      f=s=head;
      while(f->next!=NULL && f->next->next!=NULL){
           cout<<"enter11"<<endl;
          f=f->next->next;
          s=s->next;
      }
      return s;
}

Link_List merge_sort_LL(Link_List a,struct node* s,struct node* e){
        struct node* mid=a.mid_point_of_LL();
        Link_List left,right,sorted;
        if(s==mid){
            Link_List b;
            b.push(s->data);
            return b;
        }
           left=left.merge_sort_LL(a,s,mid);
           right=right.merge_sort_LL(a,mid->next,e);
           sorted=sorted.merge_two_sorted_LL(left,right);

        return sorted;

}
struct node* end(){
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

};





int main()
{   Link_List l1,l2,l3;
    l1.create_linklist();
    struct node* e;
    e=l1.end();
    l3=l3.merge_sort_LL(l1,l1.head,e);
} 
