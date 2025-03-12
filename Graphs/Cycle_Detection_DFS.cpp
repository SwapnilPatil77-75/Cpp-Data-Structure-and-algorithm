#include<iostream>
#include<vector>
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

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph(){
        for(int i = 0;i<V;i++){
            cout<<i<<":";
            list<int> neighbour = l[i];
            for(int v : neighbour){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
// Cycle detection for undirected graph  using dfs Algorithm
    bool isCyclePreHelp(int src, vector<bool> &vis, int par){
        vis[src] = true;
        list<int> neighbour = l[src];
        for(int v : neighbour){
            if(!vis[v]){
                return isCyclePreHelp(v,vis,src);
            }else{
                if(v != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclePre(){
        vector<bool> vis(V,false);
        return isCyclePreHelp(0,vis,-1);
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
   // g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.printGraph();
    cout<<g.isCyclePre();

}