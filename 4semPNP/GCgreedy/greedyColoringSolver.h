#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
//#define DEBUG
using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int>* adj;    // A dynamic array of adjacency lists
public:
    Graph(int V) { this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w);

    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}


void Graph::greedyColoring()
{
    int* result = new int[V];

    result[0] = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u

    bool* available = new bool[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr; // Assign the found color

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }

#ifdef DEBUG
    // print the result
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
        << result[u] << endl;
#endif
    //print the result
    int colors = 0;
    int* variety = new int[V];
    for (int i = 0; i < V; i++) variety[i] = result[0];
    colors++;

    for (int u = 1; u < V; u++) {
        //find the same color as result[u] in variety
        bool found = false;
        int k;
        for (k = 0; k < V && !found; k++) {
            if (variety[k] == result[u]) found = true;
        }
        if (!found) {
            colors++;
            variety[u] = result[u];
        }
    }
    cout << "Colors number: " << colors << endl;
}

