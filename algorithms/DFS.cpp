#include <bits/stdc++.h>
#include <iostream>

class Graph
{
public:
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj;

    void addEdge(int v, int w);

    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
    Graph g;
    g.addEdge(6, 4);
    g.addEdge(5, 4);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(4, 6);
    g.addEdge(4, 5);
    g.addEdge(4, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 5);

    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    std::cout << "El camino comenzando por el nodo 6 es:" << std::endl;

    g.DFS(6);

    return 0;
}