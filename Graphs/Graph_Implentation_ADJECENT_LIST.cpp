#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V ; // no of vertices 
    list<int> * l;   // an Linked-List to store the edges for a node 
public:
    Graph(int v){
        this-> V = V;
        l = new list<int> [V];  // list's with size of V;
    }

    int addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
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


};


int main(){

    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.printGraph();

    return 0;
}