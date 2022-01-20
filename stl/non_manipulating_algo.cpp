#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
void show(int a[], int arraysize)
{    for (int i = 0; i < arraysize; ++i)
        cout << a[i] << ",";
        cout<<endl;
}
bool comprator(int a,int b){
    return a>b;
}
bool is_positive(int x){
    return x>0;
}
int main(){
    // int arr[]={4,7,22,9,11,6,3,11,22};    
    // int asize=sizeof(arr)/sizeof(arr[0]);
    // vector<int> v(arr,arr+asize);
    // for (int i=0; i<v.size(); i++)
    //     cout << v[i] << " ";
    //     cout<<endl;
    // sort(arr,arr+asize,comprator);
    // sort(arr,arr+asize,greater<int>());
    // reverse(arr,arr+asize);
    // cout<<*max_element(arr,arr+asize)<<endl;
    // cout<<*min_element(arr,arr+asize)<<endl;
    // cout<<accumulate(arr,arr+asize,0)<<endl;
    //cout<<count(arr,arr+asize,11)<<endl;
    //cout<<count(v.begin(),v.end(),11)<<endl;
    //cout<<*find(arr,arr+asize,11)<<endl;
    //cout<<binary_search(arr,arr+asize,11)<<endl;
     // cout<<distance(v.begin(),max_element(v.begin(),v.end())); 
    //sort(v.begin(),v.end());   
    //v.erase(v.begin()+1); 
    //duplicates⬇️
    //v.erase(unique(v.begin(),v.end()),v.end());

    // vector<int>::iterator it;
    // it=std::unique(v.begin(),v.end());
    // v.resize(std::distance(v.begin(),it));

    //  for (it = v.begin(); it != v.end(); ++it){ 
    //     cout << *it << " "; 
    //     }
    //all_of(arr,arr+asize,[](int x){return x>0;})?cout<<"all are +ve.":cout<<"ALL are not +ve";
    
    //   any_of(v.begin(),v.end(),is_positive)? 
    //       cout << "There exists a negative element" : 
    //       cout << "All are positive elements";
    // int arr1[asize]; 
    // copy_n(arr,asize,arr1);
    // show(arr1,asize);
    
}
