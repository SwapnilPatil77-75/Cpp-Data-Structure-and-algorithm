#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
public:
    int V ; // no of vertices 
    list<int> * l;  // an Linked-List to store the edges for a node 
    bool isDirect;
    Graph(int v, bool isDirect = true){
        this-> V = V;
        l = new list<int> [V];  // list's with size of V;
        this->isDirect = isDirect;
    }


    int addEdge(int u, int v){
        l[u].push_back(v);
        if(isDirect){
            l[v].push_back(u);
        }
    }

    void printGraph(){
        for(int i = 0;i<5;i++){
            list<int> neighbour = l[i];
            cout<<i<<":";
            for(int v : neighbour){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

void dfs(int src, int dest, vector<bool> &vis, string &path){
    if(src == dest){
        cout<<path<<dest<<endl;  // if src and destination match then print the path 
        return;
    }

    vis[src] = true;
    path += to_string(src);

    list<int> neighbour = l[src];
    for(int v : neighbour){
        if(!vis[v]){
            dfs(v,dest,vis,path);
        }
    }

    vis[src] = false;
    path = path.substr(0,path.size()-1);
}

void allPaths(int src, int dest){
    vector<bool> vis(V,false);
    string path = " ";

    dfs(src,dest,vis,path);
}

};


int main(){

    Graph graph(6,false);
    graph.addEdge(5,2);
    graph.addEdge(5,0);
    graph.addEdge(2,3);
    graph.addEdge(0,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.allPaths(5,1);
    
    return 0;
}