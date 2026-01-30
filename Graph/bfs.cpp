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

    void bfs(){
      queue<int> q;
      vector<bool> visited(V,false);

        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            for(int v:l[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        
    }
};

int main(){
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,3);

g.bfs();
return 0;
}