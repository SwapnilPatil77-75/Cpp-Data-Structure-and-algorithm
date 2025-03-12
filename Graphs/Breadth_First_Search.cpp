#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
            list<int> neighbours = l[i];
            cout<<i<<": ";
            for(int v : neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
// Bradth First Search 
    void bfs(){   // O(v+u)
        queue<int> Q;
        vector<bool> vis(V,false);
        Q.push(0);
        vis[0] = true;
        while(Q.size()> 0){
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";
            list<int> neighbour = l[u];
            for(int v : neighbour){
                if(!vis[v]){
                    Q.push(v);
                    vis[v] = true;
                }
            }

        }
        cout<<endl;
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
    
    g.printGraph();
    g.bfs();



}