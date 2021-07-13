#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int V;
    unordered_set<int>* adjList;
};

Graph* createGraph(int V){
    Graph* graph = new Graph;
    graph->V=V;
    graph->adjList = new unordered_set<int>[V];
}

void addEdge(Graph* graph, int src, int dest){
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
}

void searchEdge(Graph* graph, int src, int dest){
    unordered_set<int>::iterator itr;
    itr = graph->adjList[src].find(dest);
    if(itr==graph->adjList[src].end()){
        printf("There is no edge between %d ad %d vertex.\n",src,dest);
        return;
    }
    else{
        printf("There is an edge between %d ad %d vertex.\n",src,dest);
        return;
    }
}

void printGraph(Graph* graph){
    for(int i=0; i<graph->V; i++){
        printf("The adjacency list for %d vertex is:\n",i);
        auto lst = graph->adjList[i];
        for(auto itr=lst.begin(); itr!=lst.end(); itr++) printf("%d ",*itr);
        printf("\n");
    }
}

int main(){
    int V=5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    searchEdge(graph, 4, 3);
    searchEdge(graph, 4, 2);
return 0;
}
