#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class graph{
   public:
         int v;
         int e;
         list<int>* adj;
         vector< vector<int> > w;
    graph(){
        cout<<"Enter number of nodes:"<<endl;
        cin>>v;
        cout<<"Enter number of edges:"<<endl;
        cin>>e;
        adj=new list<int>[v];  
        for(int i=0;i<v;i++) {
               w.push_back(vector<int> (v,-1));           
        }    
    }
    
    void insetedge(int v,int x,int weight=0) {
        adj[v].push_back(x);
        adj[x].push_back(v);
        w[v][x]=weight;
        w[x][v]=weight;
    }
    
    void insetedge_directed(int v,int x,int weight=0) {
        adj[v].push_back(x);
        w[v][x]=weight;
    }
    
    void showdata(){
        for(int i=0;i<v;i++){
            list<int>::iterator it;
            cout<<i<<":";
            for(it=adj[i].begin();it!=adj[i].end();it++){
                    cout<<"->"<<*it;
            }
            cout<<endl;
        }
    }
    
    void  topologicalsort_func(int v,stack<int>& s,vector<int>& visted){
          visted[v]=1;
          list<int>::iterator it;
          for(it=adj[v].begin();it!=adj[v].end();it++){
              if(visted[*it]==0){
               topologicalsort_func(*it,s,visted);
            }
          }
          s.push(v);
    }
    
    void topologicalsort(){
        cout<<"Topological sorting:"<<endl;
        vector<int> visted(v,0);
        stack<int> s;
        for(int i=0; i<v; i++){
            if(visted[i]==0){
               topologicalsort_func(i,s,visted);
            }
        }
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        
    }
    
    void dijkhtra_algo(){
    vector<int> dist(v,-1);
    vector<int> visted(v,-1);
    dist[0]=0;
    priority_queue<int> q;
    q.push(0);
    while(!q.empty()){
        list<int>::iterator it;
        for(it=adj[q.top()].begin(); it!=adj[q.top()].end();it++){
           
            if( dist[*it]==-1 || (dist[*it] > ( dist[q.top()] + w[q.top()][*it] )) ){
                            dist[*it]=dist[q.top()] + w[q.top()][*it];
            }
            if(visted[*it]==-1){
            q.push(*it);
            visted[*it]=1;
            }
           
        }
        q.pop();
    }
    vector<int>::iterator it1;
    for(it1=dist.begin(); it1!=dist.end(); it1++){
        cout<<*it1<<" ";
    }    
 }

  void bellmanford_algo(){
    vector<int> dist(v,-1);
    dist[0]=0;
     for(int i=0; i<v; i++){
         int flag=0;
         for(int j=0;j<v;j++){
            list<int>::iterator it;            
            for(it=adj[j].begin();it!=adj[j].end();it++){
                if(dist[*it]==-1 || (dist[*it]>dist[j]+w[j][*it])){
                    dist[*it]=dist[j]+w[j][*it];
                    flag=1;
                }
            }
         }
         if(flag==0){
             break;
         }
     }
    vector<int>::iterator it1;
    for(it1=dist.begin(); it1!=dist.end(); it1++){
        cout<<*it1<<" ";
    }    
}
    void bridge_count(){
        int count=0;
        stack<int> s;
        vector<int> vistedin(v,-1);
        vector<int> vistedout(v,-1);
        s.push(0);
        vistedin[0]=1;
        int k=2;
        while(!s.empty()){
             list<int>::iterator it;
             l:
             for(it=adj[s.top()].begin();it!=adj[s.top()].end();it++){
                  if(vistedin[*it]==-1){
                      s.push(*it);
                      vistedin[*it]=k;
                      k++;
                      goto l;
                  }
             }
             int p=s.top();
             s.pop(); 
             vistedout[p]=vistedin[p];
             
             for(it=adj[p].begin();it!=adj[p].end();it++){
                  if(vistedout[p]>vistedin[*it] && *it!=s.top()){
                      
                       vistedout[p]=vistedin[*it];
                  }
                  if(vistedout[p]>vistedout[*it] && *it!=s.top() && vistedout[*it]!=-1){
                       vistedout[p]=vistedout[*it];
                  }                  
             }
             if(vistedout[p]>vistedin[s.top()]){
                 count++;
             }          
              
        }
        cout<<"number of bridge:"<<count<<endl;
    }
    
    int connected_component(){
        int count=0;
        queue<int> q;
        vector<int> visted(v,-1);
         for(int i=0; i<v; i++){
             if(visted[i]==-1){
                 q.push(i);
                 visted[i]=0;
                 while(!q.empty()){
                    list<int>::iterator it;
                    for( it=adj[q.front()].begin(); it!=adj[q.front()].end(); it++){
                       if(visted[*it]==-1){
                          q.push(*it);
                          visted[*it]=0;
                        }   
                    }
                    q.pop();
                }
                count++;
             }            
            
         }
        //  cout<<"connected components are: "<<count<<endl;
         return count;
    }
    
    void dfs(int v,vector<int>& visted){
          if(visted[v]==-1){
              visted[v]=0;
            //   cout<<v<<" ";
              list<int>::iterator it;
              for(it=adj[v].begin();it!=adj[v].end(); it++){
                  if(visted[*it]==-1){
                     dfs(*it,visted);
                  }                 
              }
          }
    }

    void mother_vertex(){
         vector<int> mother;
         for(int i=0; i<v; i++){
              vector<int> visted(v,-1);
              dfs(i,visted);
              int flag=0;
              for(int j=0; j<v; j++){
                  if(visted[j]==-1){
                       flag=1;
                       break;
                  }
              }
              if(flag==0){
                  mother.push_back(i);
              }
         }
         cout<<"List of all monther vertexs are: "<<endl;
         vector<int>::iterator it;
         for(it=mother.begin();it!=mother.end(); it++){
             cout<<*it<<" ";
         }
          cout<<endl;
    }
    
    void spaning_tree(){
        if(connected_component()>1){
            cout<<"graph is disconnected since spanning tree does not exists"<<endl;
            return;
        }
        vector<int> visted(v,-1);
        stack<int> s;
        graph g;
        s.push(0);
        visted[0]=0;
        while(!s.empty()){

            list<int>::iterator it;
            l:
            for(it=adj[s.top()].begin(); it!=adj[s.top()].end(); it++){
                if(visted[s.top()]==-1 || visted[*it]==-1 ){
                      g.insetedge(s.top(),*it);
                }
                if(visted[*it]==-1){
                      s.push(*it);
                      visted[*it]=0;
                      goto l;
                }                
            }
            s.pop();
        }
        g.showdata();
    }
    
    void s(int n,string a){
        int b[5][5];
        for(int i=0; i<5; i++){
            cout<<b[i]<<" ";
        }
    }
  };


int main(){ 
    
     graph g1;
     g1.insetedge(0,1);
     g1.insetedge(0,2);
     g1.insetedge(1,3);
     g1.insetedge(2,4);
     g1.insetedge(3,4);
     g1.insetedge(4,5);
     g1.insetedge(5,6);
     g1.insetedge(5,7);
     g1.insetedge(7,6);
     g1.insetedge(7,8);
     g1.insetedge(8,9);
     g1.insetedge(8,10);
     g1.insetedge(9,10);
    //  g1.spaning_tree();
    // g1.showdata();
    int p=5;
    string r;
     g1.s(p,r);
 
      }
