#include "dijkstras.h"

int main() {
    Graph g;
    file_to_graph("src/small.txt", g);
    vector<int> previous;
    vector<int> path;
    extract_shortest_path(dijkstra_shortest_path(g, 0, previous), previous, 3);
    print_path(path, 1);
}