#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph {
    int v;
    list<int> *adj;
    bool *visited;

    public:
        Graph(int v) {
            this->v = v;
            adj = new list<int>[v];
            visited = new bool[v];
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);        
        }

        void displayGraph(int v) {
            for(int i = 0; i < v; i++) {
                cout<<"\nVertex " << i <<":";
                for(auto x : adj[i]) {
                    cout<< "<-->" << x;
                }
                cout<<endl;
            }
        }

        void DFS(int src) {
 
            visited[src] = true; // visited src node
            cout << src <<" ";

            list<int>::iterator iter; // to store adjavent vertices
                
            for(iter = adj[src].begin(); iter != adj[src].end(); iter++) {
                int neighbour = *iter;
                if(!visited[neighbour]) {
                    DFS(neighbour);
                }
            }

        }
};

int main() {
    int v = 6;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.displayGraph(v);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}
