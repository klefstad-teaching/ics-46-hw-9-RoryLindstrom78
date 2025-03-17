#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INF);

    previous.resize(n, -1);
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curr_dist > distance[u]) continue;

        for (Edge neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (distances[destination] == INF) return path;
    stack<int> stk;
    
    for (int v = destination; v!= -1; v = previous[v]) {
        stk.push(v);
    }

    while (!stk.empty()) {
        path.push_back(stk.top());
        stk.pop();
    }

    return path;
}

void print_path(const vector<int>& v, int total) {
    for (int i=0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Total cost is: " << total << endl;
}

