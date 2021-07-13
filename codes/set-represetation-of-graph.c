#include<bits/stdc++.h>
using namespace std;

struct Graph{
  int V;
  set<int, greater<int>>* adjacency_list;
};

Graph* create_graph(int V){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->adjacency_list = new set<int, greater<int>>[V];
return graph;
}

Graph* add_edge(Graph* graph, int src, int dest){
  graph->adjacency_list[src].insert(dest);
  graph->adjacency_list[dest].insert(src);
}

void print_graph(Graph* graph){
  for(int i=0; i<graph->V; i++){
    set<int, greater<int>>lst = graph->adjacency_list[i];
    printf("Adjacency list for vertex %d: \n",i);
    for(auto itr=lst.begin(); itr!=lst.end(); itr++){
      printf("%d ",*itr);
    }
    printf("\n");
  }
}

void search_edge(Graph* graph, int src, int dest){
  auto itr = graph->adjacency_list[src].find(dest);
  if(itr==graph->adjacency_list[src].end()){
    printf("There is no edge between %d and %d vertex.\n",src,dest);
    return;
  }
  printf("There is a edge between %d and %d.\n",src,dest);
  return;
}

int main(){
  int V=5;
  struct Graph* graph = create_graph(V);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 4);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  
  print_graph(graph);
  search_edge(graph, 2, 1);
  search_edge(graph, 0, 3);
return 0;
}
