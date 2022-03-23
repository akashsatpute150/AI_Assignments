


#include <iostream>

#include<queue>

 

using namespace std;

 

typedef pair<int, int> pi;

 

class Graph{

int n;

int *heuristic;

int **adj;

public:

Graph(int n){

this->n = n;

adj = new int*[n];

for(int i = 0; i < n; i++){

adj[i] = new int[n];

}

heuristic = new int[n];

}

void add_edge(int x, int y, int cost){

adj[x][y] = cost;

adj[y][x] = cost;

}

void show_graph(){

for(int i = 0; i < n; i++){

for(int j = i; j < n; j++){

if(adj[i][j] > 0){

cout<<i<<" <-> "<<j<<endl;

}

}

}

}

void add_heuristic(int hr[]){

for(int i = 0; i < n; i++){

heuristic[i] = hr[i];

}

}

int astar(int source, int destination){

int total_cost = 0;

bool *visited = new bool[n];

for(int i = 0; i < n; i++){

visited[i] = false;

}

priority_queue<pi, vector<pi>, greater<pi> > pq;

pq.push(make_pair(0, source));

int prev_node = source;

visited[source] = true;

pair<int, int> value;

 

while(!pq.empty()){

value = pq.top();

pq.pop();

pq = priority_queue<pi, vector<pi>, greater<pi> >();

value.first -= heuristic[value.second];

if(value.second == destination){

break;

}

cout<<value.second<<"->";

for(int i = 0; i < n; i++){

if(adj[value.second][i] > 0 && !visited[i]){

pq.push(make_pair(value.first + adj[value.second][i] + heuristic[i], i));

visited[i] = true;

}

}

}

return value.first + heuristic[value.second];

}

};

 

int main()

{

int vertices, edges, x, y, cost;

cout<<"Enter Number of Vertices\n";

cin>>vertices;

 

cout<<"Enter Number of Edges\n";

cin>>edges;

Graph g(vertices);

for(int i = 0; i < edges; i++){

cout<<"For edge "<<i+1<<" Enter x and y: ";

cin>>x>>y;

cout<<"Enter Cost: ";

cin>>cost;

g.add_edge(x, y, cost);

}

int *heuristic = new int[vertices];

cout<<"Enter heuristic values\n";

for(int i = 0; i < vertices; i++){

cout<<"Enter for vertice "<<i<<endl;

cin>>heuristic[i];

}

g.add_heuristic(heuristic);

 

g.show_graph();

 

int source, destination;

cout<<"Enter source and destination\n";

cin>>source>>destination;

 

int totalcost = g.astar(source, destination);

 

cout<<"\nF is "<<totalcost<<endl;

 

return 0;

}
