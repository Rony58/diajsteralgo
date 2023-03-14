#include<bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=1e9;
struct edge_area{
    int s, dest, weight;
};
class Graph {
    int V, E;
    vector<edge_area> edges;
public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    void addEdge(int s, int dest, int weight) {
        edge_area edge = {s, dest, weight};
        edges.push_back(edge);
    }
    void bellmanFord(int s) {
        vector<int> dist(V, INT_MAX);
        dist[s] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (auto edge : edges) {
                int u = edge.s;
                int v = edge.dest;
                int w = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        for (auto edge : edges) {
            int u = edge.s;
            int v = edge.dest;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Graph contains negative cycle\n";
                return;
            }
        }
        for (int i = 0; i < V; i++)
            cout << i << ": " << dist[i] << endl;
    }
};
int main() {
    int V, E, s;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph graph(V, E);
    for (int i = 0; i < E; i++) {
        int s, dest, weight;
        cout << "Enter edge " << i + 1 << " source, destination, weight: ";
        cin >> s >> dest >> weight;
        graph.addEdge(s, dest, weight);
    }
    cout << "Enter source vertex: ";
    cin >> s;
    graph.bellmanFord(s);
    return 0;
}
