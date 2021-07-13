#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adjList;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    vector<int> BFS(int source);
};

Graph::Graph(int V){
  this->V = V;
  this->adjList = new list<int>[V];
}

void Graph::addEdge(int src, int dest){
  adjList[src].push_back(dest);
  adjList[dest].push_back(src);
}

vector<int> Graph::BFS(int src){
  vector<bool>visited(V, false);
  vector<int> level(V,0);
  
  list<int>queue;
  visited[src]=true;
  queue.push_back(src);
  level[src]=0;

  while(!queue.empty()){
    src = queue.front();
    queue.pop_front();
    
    for(auto i:adjList[src]){
      if(!visited[i]){
        level[i]=level[src]+1;
        visited[i]=true;
        queue.push_back(i);
        }
      }
    }
  return level;
}

int main(){

  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(2, 5);

  vector<int> levels=g.BFS(0) ;
  for(int i=0; i<6; i++) printf("Node:%d, at level: %d\n",i,levels[i]);
return 0;
}
