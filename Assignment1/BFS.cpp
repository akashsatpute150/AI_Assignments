#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph {
    int v;
    list<int> *adj;

    public:
        Graph(int v) {
            this->v = v;
            adj = new list<int>[v];
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

        void BFS(int src) {
            bool *visited = new bool[v];
            for(int i = 0; i < v; i++) {
                visited[i] = false;
            }

            list<int> queue; 
            visited[src] = true; // visited src node
            queue.push_back(src); 

            list<int>::iterator iter; // to store adjavent vertices
            while(!queue.empty()) {
                int currNode = queue.front();
                cout << "Visited " << currNode << endl;
                queue.pop_front();
                
                for(iter = adj[currNode].begin(); iter != adj[currNode].end(); iter++) {
                    int neighbour = *iter;
                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        queue.push_back(neighbour);
                    }
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
    g.BFS(2);
    return 0;
}