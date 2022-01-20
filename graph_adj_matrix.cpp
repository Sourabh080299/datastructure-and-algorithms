#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

class graph{
    public:
    struct node{
    int v;
    int e;
    int adj[20][20];
    int distance[20][20];
    };   
    struct node* G=new struct node[sizeof(node)]; 
    graph(){
        cout<<"Enter number of nodes:"<<endl;
        cin>>G->v;
        cout<<"Enter number of edges:"<<endl;
        cin>>G->e;
        for(int i=0;i<G->v;i++){
            for(int j=0;j<G->v;j++){
                G->adj[i][j]=0;
        }        
        }
    }
    
    void deletion(int x,int y){
        G->adj[x][y]=0;
        G->adj[y][x]=0;
        G->distance[x][y]=0;
        G->distance[y][x]=0;
    }
    void edgeinsertion(int x,int y,int z){       
        G->adj[x][y]=1;
        G->adj[y][x]=1;
        G->distance[x][y]=z;
        G->distance[y][x]=z;
    }
    void edgeinsertion_directed(int x,int y,int z){       
        G->adj[x][y]=1;
        G->distance[x][y]=z;
    }

    void search_edge(){
        cout<<"which edge you want to search enter  the number of those two nodes :"<<endl;
        int x,y;
        cin>>x>>y;
        cout<<G->adj[x][y];
    }

    void showdata(){
        cout<<"  ";
        for(int i=0; i<G->v; i++){
             cout<<" | "<<i<<" | ";
        }
        cout<<endl<<endl<<endl;
         for(int i=0;i<G->v;i++){
             cout<<i<<" ";            
            for(int j=0;j<G->v;j++){
                cout<<" | "<<G->adj[i][j]<<" | ";
        }
        cout<<endl<<endl;
        }
    }

    void BFS(){
       queue<int> q;
       vector<int> visted;
       for(int i=0; i<G->v; i++){
           visted.push_back(0);
       }
       q.push(0);
       visted[0]=1;
       cout<<"BFS"<<endl;
       while(!q.empty()){
           for(int i=0; i<G->v;i++){
                  if(visted[i]==0 && G->adj[q.front()][i]==1){
                                q.push(i);
                                visted[i]=1;
                  }
           } 
            cout<<q.front()<<" ";
            q.pop();
       }
       cout<<endl;

    }

    void DFS(){
       stack<int> s;
       vector<int> visted;
       for(int i=0; i<G->v; i++){
           visted.push_back(0);
       }
       s.push(0);
       cout<<0<<" ";
       visted[0]=1;
       while(!s.empty()){
           l:
           for(int i=G->v-1;i>=0;i--){
               if(visted[i]==0 && G->adj[s.top()][i]){
                   s.push(i);
                   visted[i]=1;
                   cout<<i<<" ";
                   goto l;                   
               }
           }
           if(!s.empty()){
               s.pop();
               goto l;
           }
       }
       cout<<endl;
    }

    void Topological_sorting(){
       vector<int> incoming;
       for(int i=0;i<G->v;i++){
           int count=0;
           for(int j=0;j<G->v;j++){
               if(G->adj[j][i]==1){
                   count++;
               }
           }
           incoming.push_back(count);
       }
       int flag=1;
       while(flag!=1){
           for(int i=0; i<G->v; i++){
               
           }
       }
       
    }

    void dijkstra(){
        vector<bool> visted(G->v,false);
        priority_queue<pair<int,int>,vector< pair <int ,int> >,greater< pair<int ,int> > > mindistance;
        vector<int> sdistance(G->v,INT_MAX);
        mindistance.push(make_pair(0,0));
        sdistance[0]=0;
        for(int i=0; i<G->v; i++){
            int min=mindistance.top().second;
            mindistance.pop();
            for(int j=0; j<G->v; j++){
                if(visted[min]==false && G->adj[min][j]!=0 && (sdistance[j]==INT_MAX || sdistance[j]>sdistance[min]+G->distance[min][j]) ){
                    sdistance[j]=sdistance[min]+G->distance[min][j];
                    mindistance.push(make_pair(sdistance[j],j));
                }
            }
            visted[min]=true;
        }
      cout<<"Vertex \t\t Distance from Source\n"; 
       for(int i=0; i<G->v; i++){
           cout<<i<<" \t\t\t "<<sdistance[i]<<endl;
       }
    }

    bool cylce_detacter(){
         vector<int> visted(G->v,-1);

        //  - 1 for unvisted
        //    0 for visted
        //  + 1 for visted and poped from stack

        queue<int> q;
        q.push(0);
        visted[0]=0;
        while(!q.empty()){
            for(int i=0; i<G->v; i++){
               if(G->adj[q.front()][i]){
                   if(visted[i]==-1){
                       q.push(i);
                       visted[i]=0;
                   }
                   else if(visted[i]==0){
                       return true;
                   }
               }
            }
            visted[q.front()]=1;
            q.pop();
        }
        return false;
    } 
 
    graph prims(){
        graph g;
        vector<bool> visted(G->v,false);
        priority_queue< pair< int, pair<int,int> >,
                        vector< pair<int, pair<int,int> > > ,
                        greater< pair<int, pair<int,int> > > 
                        > q;
        queue<int> bfs;
        bfs.push(0);
        int k=0;
        while(!q.empty() || k==0){
            k=1;
            if(!bfs.empty()){
              for(int i=0; i<G->v; i++){
                if(G->adj[bfs.front()][i]){
                    if(visted[i]==false){
                        q.push(
                            make_pair(
                                      G->distance[bfs.front()][i],
                                      make_pair(bfs.front(),i)
                                     )  
                              );
                    }
                }
            }
            }
            
            pair< int, pair<int,int> > p=q.top();
            q.pop();
            g.edgeinsertion(p.second.first,p.second.second,p.first);
            if(visted[p.second.second]==false){
                  bfs.push(p.second.second);
            }            
            if(g.cylce_detacter()){
                g.deletion(p.second.first,p.second.second);
            }
            
            if(!bfs.empty()){
               visted[bfs.front()]=true;
               bfs.pop();
            }
          
        }
        g.showdata();
        return g;
    }

    graph kruskal(){
        priority_queue< pair< int, pair<int,int> >,
                        vector< pair<int, pair<int,int> > > ,
                        greater< pair<int, pair<int,int> > > 
                        > q;
        for(int i=0; i<G->v; i++){
            for(int j=0; j<G->v; j++){
                if(G->adj[i][j]){
                    q.push(make_pair(G->distance[i][j],make_pair(i,j)));
                }
            }
        }
        graph g;
        while(!q.empty()){
            pair<int, pair<int,int> > p;
            p=q.top();
            q.pop();
            g.edgeinsertion(p.second.first,p.second.second,p.first);
            if(g.cylce_detacter()){
                g.deletion(p.second.first,p.second.second);
            }
        }
      g.showdata();
      return g;
    }

    
};


int main(){
   graph g1;
   g1.edgeinsertion(0,1,4);
   g1.edgeinsertion(0,7,8);
   g1.edgeinsertion(1,2,8);
   g1.edgeinsertion(1,7,11);
   g1.edgeinsertion(2,8,2);
   g1.edgeinsertion(2,5,4);
   g1.edgeinsertion(2,3,7);
   g1.edgeinsertion(3,4,9);
   g1.edgeinsertion(3,5,14);
   g1.edgeinsertion(4,5,10);
   g1.edgeinsertion(5,6,2);
   g1.edgeinsertion(7,6,1);
   g1.edgeinsertion(6,8,6);
   g1.edgeinsertion(7,8,7);
//    g1.showdata();
//    g1.BFS();
//    g1.DFS();
//    g1.showdata();
//    g1.dijkstra();
   g1.prims();
   
}
