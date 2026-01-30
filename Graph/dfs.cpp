#include <iostream>
using namespace std;
#include <list>
#include <queue>

class Graph{
    int V;
    list<int>*l;

public:
   Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u, int v, bool undir=true){
        l[u].push_back(v);
        if(undir){
            l[v].push_back(u);
        }
    }

   void dfsHelper(int u, vector<bool>& visited){
      visited[u]=true;
      cout<<u<<" ";
      for(int v:l[u]){
         if(!visited[v]){
            dfsHelper(v,visited);
         }
      }
   }

   void dfs(){
      vector<bool> visited(V,false);
      dfsHelper(0,visited);
   }
};
int main(){
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,3);

g.dfs();
return 0;
}