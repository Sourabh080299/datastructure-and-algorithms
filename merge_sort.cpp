#include<iostream>
using namespace std;

void merge(int a[],int s,int e){
    int k,i=1,j=1,count=1,b[e],mid;
    mid=(s+e)/2;
    j=mid+1;
     for(k=s;k<=e;k++){
       if(j>e or i>mid){
             if(j>e){
              b[count]=a[i];
              i++;
                    }
             if(i>mid){
               b[count]=a[j];
               }
                         }
       else{
           if(a[i]>=a[j]){
           b[count]=a[j];
           j++;
           }
           else{
           b[count]=a[i];
           i++;
            }
            }
            count++;
     }
     for(i=s;i<=e;i++){
         a[i]=b[i];
     } 




}

void merge_sort(int a[],int s,int e){
    int mid=(s+e)/2;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    merge(a,s,e);
}

int main(){
    int a[10],p;
    for(p=1;p<=10;p++){
        cin>>a[p];
    }
    merge_sort(a,1,10);
     for(p=1;p<=10;p++){
        cout<<a[p]<<"|";
    }
}
