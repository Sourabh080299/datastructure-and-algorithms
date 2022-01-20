#include<iostream>
using namespace std;
class hashing{
     struct pair{
      int data;
      int key;
      struct pair* next;
     };     
     struct pair hash_table[10][2];
     public:
      hashing(){
          for(int i=0;i<10;i++){
             for(int j=0;j<2;j++){
                hash_table[i][j].data=0;
                hash_table[i][j].next=NULL;
             }
         }
      }
     void insert_using_LL(int x,int y){         
         int k=x%10;
         int p;
         x>=0?p=0:p=1;
       if(hash_table[k][p].data==0){          
              hash_table[k][p].data=x;
              hash_table[k][p].key=y;      
       }
       else{
        //    while(hash_table[k][p].data!=0){
        //        k=(k+1)%10;
        //                  
        //    }
            struct pair* newnode=new struct pair[sizeof(struct pair)];
            newnode->data=x;
            newnode->key=y;
            newnode->next=NULL;
            struct pair* temp=hash_table[k][p].next;
            struct pair* pre=NULL;
            while(temp!=NULL){
                pre=temp;
               temp=temp->next;
            }
            if(pre==NULL){
              hash_table[k][p].next=newnode;
            }
            else{
                pre->next=newnode;
            }
       }
       cout<<x<<" inserted"<<endl;
     }
    //  void insert_using_linear_probing(int x){         
    //      int k=x%10;
    //      int p;
    //      x>=0?p=0:p=1;
    //    if(hash_table[k][p].data==0){          
    //           hash_table[k][p].data=x;
    //           hash_table[k][p].key=k;      
    //    }
    //    else{
    //        while(hash_table[k][p].data!=0){
    //            k=(k+1)%10;                         
    //        }
            
    //    }
    //    cout<<x<<" inserted"<<endl;
    //  }

     void display(){
         cout<<"key"<<"    "<<"data"<<endl;
         for(int i=0;i<10;i++){
             for(int j=0;j<2;j++){
                 if(hash_table[i][j].data!=0){
                 cout<<hash_table[i][j].key<<"      "<<hash_table[i][j].data<<endl;
                  struct pair* temp=hash_table[i][j].next;
                  while(temp!=NULL){      
                  cout<<temp->key<<"      "<<temp->data<<endl;
                  temp=temp->next;
                 }                 
                  }
             }
         }
     }

void search_using_key(int x){
    int p;
    x>=0?p=0:p=1;
     for(int i=0;i<10;i++){
             
                 if(hash_table[x][p].data!=0){
                     cout<<"enter"<<endl;
                 cout<<hash_table[x][p].data<<" ";
                  struct pair* temp=hash_table[x][p].next;
                  while(temp!=NULL){      
                  cout<<temp->data<<" ";
                  temp=temp->next;
                 }                 
                  }
             
         }
}

int search(int x){
      
        int k=x%10;
        int p;
        x>=0?p=0:p=1;
        if(hash_table[k][p].data!=0){             
            if(hash_table[k][p].data==x){                
                cout<<"data founded"<<endl;
                return hash_table[k][p].key;
            }
            else{
              if(hash_table[k][p].next==NULL){                              
               cout<<"data founded"<<endl;
               return hash_table[k][p].key;
           }
           else{                            
               struct pair* temp=hash_table[k][p].next;
               while(temp->data!=x){          
                    temp=temp->next; 
                    if(temp==NULL){
                    cout<<"wrong entry data not found"<<endl;
                    return 0;
                      }                      
               }
                cout<<"data founded"<<endl;
                return temp->key;               
           }
            }          
        }
        else{
            cout<<"wrong entry data not found"<<endl;
            return 0;
        }
    } 
  void delete_element(int x){
       int k=x%10;
       int p;
       x>=0?p=0:p=1;
       if(hash_table[k][p].data==x && hash_table[k][p].next==NULL){
           hash_table[k][p].data=0;
           hash_table[k][p].key=0;
           cout<<x<<" element  deleted"<<endl;
           return ;
       }
       else{
           struct pair* temp=hash_table[k][p].next;
           struct pair* next1=temp->next;
           struct pair* pre;
           if(hash_table[k][p].data==x){
               hash_table[k][p].data=temp->data;
               hash_table[k][p].next=temp->next;
               delete temp;
               cout<<x<<" element deleted"<<endl;
               return ;
           }
           else{
               if(temp->data==x){
                   hash_table[k][p].next=temp->next;
                   cout<<x<<" element deleted"<<endl;
                   delete temp;
                   return ;
               }
               while(temp->data!=x ){
                   pre=temp;
                   temp=temp->next;
                   next1=next1->next;
                   if(temp==NULL){
                    cout<<"wrong entry"<<endl;
                       return ;
                   }
               }
               pre->next=next1;
               cout<<x<<" element deleted"<<endl;
               delete temp;
               return ;
           }
           
       }
  }


};

class hasing_colision{
       struct pair{
            int data;
            int key;
       };
       struct pair hash_table[10][2];
       public:
          hasing_colision(){
               for(int i=0;i<10;i++){
               for(int j=0;j<2;j++){
                hash_table[i][j].data=0;
             }
         }
          }
        void insertion_linear_probing(int x){
            int k=x%10;
            int p;
            int i=0;
            x>=0?p=0:p=1;
            if(hash_table[k][p].data==0){
               hash_table[k][p].data=x;
               hash_table[k][p].key=k;
               cout<<x<<" data inserted"<<endl;
               return ;  
            }
            else{
                while(hash_table[k][p].data!=0){
                    k=(k+1)%10;
                    i++;
                    if(i>10){
                      cout<<"hash table completly filled "<<endl;
                      return ;  
                    }
                }
                hash_table[k][p].data=x;
                hash_table[k][p].key=k;
                cout<<x<<" data inserted"<<endl;
                return ; 
            }
        }
     void display(){
         cout<<"key"<<"    "<<"data"<<endl;
         for(int i=0;i<10;i++){
             for(int j=0;j<2;j++){
                 if(hash_table[i][j].data!=0){
                 cout<<hash_table[i][j].key<<"      "<<hash_table[i][j].data<<endl;               
                  }
             }
         }
     }


int search(int x){
    int k=x%10;
    int p,i=0;
    x>=0?p=0:p=1;
    if(hash_table[k][p].data==x){
        cout<<x<<" data founded"<<endl;
        return hash_table[k][p].key;
    }
    else{
        while(hash_table[k][p].data!=x){
            k=(k+1)%10;
            i++;
            if(i>10){
                cout<<x<<" data not founded"<<endl;
                return 0;
            }
        }
        cout<<x<<" data founded"<<endl;
        return  hash_table[k][p].key;
    }
}
void delete_linear_Probing(int x){
     int k=x%10;
     int p,i=0;
     x>=0?p=0:p=1;
     if(hash_table[k][p].data==x){
         hash_table[k][p].data=0;
         hash_table[k][p].key=0;
         cout<<x<<" data is deleted"<<endl;
         return;
     }
     else{
         while(hash_table[k][p].data!=x){
             k=(k+1)%10;
             i++;
             if(i>10){
                 cout<<x<<" data is not founded"<<endl;
                 return;
             }
         }
         hash_table[k][p].data=0;
         hash_table[k][p].key=0;
          cout<<x<<" data is deleted"<<endl;
         return;
     }
}
};

//  int main(){
//     hashing h;
//     h.insert_using_LL(1,0);
//     h.insert_using_LL(2,-1);
//     h.insert_using_LL(3,1);
//     h.insert_using_LL(4,-2);
//     h.insert_using_LL(5,-1);
//     h.insert_using_LL(6,0);
//     h.insert_using_LL(7,1);
//     h.insert_using_LL(8,2);
//     h.insert_using_LL(9,-3);
//     h.insert_using_LL(10,-2);
//     h.insert_using_LL(11,-1);
//     h.insert_using_LL(12,0);
//     h.display();
//     cout<<h.search(1)<<endl;
//     cout<<h.search(2)<<endl;
//     cout<<h.search(3)<<endl;
//     cout<<h.search(4)<<endl;
    
    

// }