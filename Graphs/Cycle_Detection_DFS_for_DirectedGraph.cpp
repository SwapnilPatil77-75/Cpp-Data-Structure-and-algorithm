#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{
public:
    int V;
    list<int> * l;
    bool isDirect;

    Graph(int V,bool isDirect = true){
        this->V = V;
        l = new list<int> [V];
        this->isDirect = isDirect;
    }


    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isDirect){
            l[v].push_back(u);
        }
    }

    bool isCyclePreHelp(int src, vector<bool> &vis, vector<bool> &rcrPath){
        vis[src] = true;
        rcrPath[src] = true;
// if the cycle is present in Directed Graph
        list<int> neighbour = l[src];
        for(int v : neighbour){
            if(!vis[v]){
                if(isCyclePreHelp(v,vis,rcrPath)){
                    return true;
               }
            }else{
                if(rcrPath[v]){
                    return true;
                }
            }
        }
        rcrPath[src] = false;
        return false;
    }

    bool isCyclePre(){
        vector<bool> vis(V,false);
        vector<bool> recursionPath(V,false);

        for(int i = 0;i<V; i++){
            if(!vis[i]){
                if(isCyclePreHelp(i,vis,recursionPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    Graph g(5,false);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,3);
    
    cout<<g.isCyclePre();
}