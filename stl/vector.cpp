#include<iostream>
#include<vector>
using namespace std;
int main(){
 //    int arr[]={1,2,3,4,5,6,7,8,9};
//    vector<int> v ={1,2,3,4,5,6,7,8,9};
//    vector<int> vec(begin(arr),end(arr));
//    vector<int> vec;
//    cout<<"Enter the element"<<endl;
//     int k;
//   for(int i=0;i<5;i++){
//       cin>>k;
//       vec.push_back(k);
//   }
 // cout<<"done"<<endl;
  // cout<<*vec.begin();
 //  cout<<*(vec.end()-1);

  int arr[]={4,7,22,9,11,6,3,11,22};    
    int asize=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+asize);
    vector<int> v1;
    v1.assign(7,100);
    // v.pop_back();
    //cout<<v.at(1);
    // cout<<v.back()<<endl;
    // cout<<v.front()<<endl;
    // for(int i=0;i<v1.size();i++){
    //     cout<<v1[i]<<endl;
    // }
   // cout<<*(v.rbegin());
    //cout<<*(v.rend());
//    cout<<*(v.cbegin())<<endl;
//     cout<<*(v.cend());


    return 0;
}