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
        cout<<"in Add Edge func"<<endl;
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
    void bfs(int st,vector<bool> &vis){   // O(v+u)
        queue<int> Q;
        //vector<bool> vis(V,false);
        Q.push(st);
        vis[st] = true;
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

    void bfsHelp(){
        vector<bool> vis(V,false);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                bfs(i,vis);
            }
        }
    }

};


int main(){
    Graph g(6);
    g.addEdge(1,6);
    g.addEdge(6,4);
    g.addEdge(4,9);
    g.addEdge(4,3);
    g.addEdge(3,8);
    g.addEdge(3,7);
    // g.addEdge(2,0);
    // g.addEdge(2,5);
    
    g.printGraph();
    //g.bfsHelp();



}