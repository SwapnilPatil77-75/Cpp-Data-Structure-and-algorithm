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
    bool bfs(){   // O(v+u)
        queue<int> Q;
        vector<int> vis(V,-1);

        Q.push(0);
        vis[0] = 0;
        while(Q.size()> 0){
            int u = Q.front();
            Q.pop();
            //cout<<u<<" ";
            list<int> neighbour = l[u];
            for(int v : neighbour){
                if(vis[v] == -1){
                    Q.push(v);
                    vis[v] = !vis[u];
                }else{
                    if(vis[v] == vis[u]){
                        return false;
                    }
                }
            }

        }
        return true;
        cout<<endl;
    }


};


int main(){
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,2);

    cout<<g.bfs()<<endl;

    return 0;
}