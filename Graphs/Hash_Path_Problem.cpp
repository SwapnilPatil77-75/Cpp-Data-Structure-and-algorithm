#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;


class Graph{
public:
    int V;
    list<int> * l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
// check if a path present between source and destination 
   bool isPthPresentHelp(int src, int dest, vector<bool> &vis){
    if(src == dest){
        return true;
    }
    list<int> neighbour = l[src];
    vis[src] = true;
    for(int v : neighbour){
        if(!vis[v]){
            return isPthPresentHelp(v,dest,vis);
        }
    }
    return false;
   }
   bool isPthPresent(int src, int dest){
        vector<bool> vis(V,false);
        return isPthPresentHelp(src,dest,vis);
    }
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    
    cout<<g.isPthPresent(0,5);
    //g.bfs();


}