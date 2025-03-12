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
// check if path is present between src and destination using bfs 
    bool isPthPresentHelper(int src, int dst, vector<bool> &vis,vector<int> &pr){
        queue<int> Q;
        Q.push(src);
        vis[src] = true;
        int i = 0;
        pr[i] = src;
        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();
            list<int> neigbour = l[u];
            for(int v: neigbour){
                if(!vis[v]){
                    if(v == dst){
                        return true;
                    }
                    Q.push(v);
                    vis[v] =true;
                    pr[i++] = v;
                }
            }
        }
        return false;
    }
    bool isPthPresent(int src, int dst){
        vector<bool> vis(V,false);
        vector<int> pr;
       bool ans = isPthPresentHelper(src,dst,vis,pr);
       for(int i = 0;i<pr.size();i++){
        cout<<pr[i]<<" ";
       }

       return ans;

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
    //g.addEdge(5,6);
    
    cout<<g.isPthPresent(0,5);
    //g.bfs();


}