#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V ; // no of vertices 
    list<pair<int,int>> * l;   // an Linked-List to store the edges for a node 
public:
    Graph(int v){
        this-> V = V;
        l = new list<pair<int,int>> [V];  // list's with size of V;
    }
// weighted graph
    int addEdge(pair<int,int> u,pair<int,int> v){
        l[u.first].push_back(v);
        l[v.first].push_back(u);
    }

    void printGraph(){
        for(int i = 0;i<5;i++){
            list<pair<int,int>> neighbour = l[i];
            cout<<i<<":";
            for(pair<int,int> v : neighbour){
                cout<<v.first<<"--"<<v.second<<" ";
            }
            cout<<endl;
        }
    }


};


int main(){

    Graph graph(5);
    graph.addEdge({0,5},{1,5});
    graph.addEdge({1,1},{2,1});
    graph.addEdge({1,3},{3,3});
    graph.addEdge({2,1},{3,1});
    graph.addEdge({2,2},{4,2});
    
    graph.printGraph();

    return 0;
}