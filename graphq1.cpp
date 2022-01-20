#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<string> path;
    string s;
    bool findPath(vector<vector<int> > m, int n,string s1,int i=0,int j=0){
             
              m[i][j]=0;
              if(m[i][j+1]==1 && (i<n-1 || j<n-1)){                 
                s1.push_back('R'); 
                bool cheack;        
                cheack=findPath(m,n,s1,i,j+1);                
                if(i==n-1 && j==n-1){
                    cout<<s1<<endl;
                    path.push_back(s1);
                }
                else if(!cheack){
                    s1.resize(s1.size()-1);
                    return false;
                }
                else{
                    return true;
                }
              }         
              if(m[i+1][j]==1 && (i<n-1 || j<n-1) ){                            
                s1.push_back('D');
                bool cheack;        
                cheack=findPath(m,n,s1,i+1,j );
                if(i==n-1 && j==n-1){
                    cout<<s1<<endl;
                 path.push_back(s1);
                }
                else if(!cheack){
                    s1.resize(s1.size()-1);
                    return false;
                }
                else{
                    return true;
                }
              }
              if(m[i][j-1]==1 && i>0 && j>0  && i<n-1 && j<n-1){
                s1.push_back('U');
                bool cheack;        
                cheack=findPath(m,n,s1,i,j-1);
                if(i==n-1 && j==n-1){
                    cout<<s1<<endl;
                    path.push_back(s1);
                }
                else if(!cheack){
                    s1.resize(s1.size()-1);
                    return false;
                }
                else{
                    return true;
                }
              }
              if(m[i-1][j]==1 && i>0 && j>0  && i<n-1 && j<n-1){
                s1.push_back('L');
                bool cheack;        
                cheack=findPath(m,n,s1,i-1,j );
                if(i==n-1 && j==n-1){
                    cout<<s1<<endl;
                    path.push_back(s1);
                }
                else if(!cheack){
                    s1.resize(s1.size()-1);
                    return false;
                }
                else{
                    return true;
                }
              }
              return false;
              
        }
};
// DDRDRR DRDDRR
int main(){
    vector<vector<int> > vect;
    for(int i=0; i<4; i++){
        vector<int> v;
        for(int j=0; j<4; j++){
            int p;
            cin>>p;
            v.push_back(p);
        }
        vect.push_back(v);
    }
    Solution s;
    string q;
    s.findPath(vect,4,q);
    vector<string>::iterator it;
    for(it=s.path.begin() ; it!=s.path.end(); it++){
        cout<<*it<<" ";
    }
}
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}