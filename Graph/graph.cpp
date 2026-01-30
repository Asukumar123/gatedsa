#include <iostream>
using namespace std;
#include <list>

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

    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<i<<"->";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,3);

g.printAdjList();
return 0;
}