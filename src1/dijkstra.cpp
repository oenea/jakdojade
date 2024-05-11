#include "dijkstra.h"
#include "priorityQueue.h"
#include "vector.h"

vector<int> getPath(vector<Dijkstra>& shortestPath, int source, int dest);

void dijkstraSearch(vector<vector<Vertex>>& graph, vector<Dijkstra>& shortestPath, int source) {
    for (int i = 0; i < (int)shortestPath.size(); i++) {
        shortestPath[i] = {-1, 10000000, -1, false};
    }
    shortestPath[source].weight = 0;
    priorityQueue Q;
    Q.add({source, 0});
    while ( !Q.empty() ) {
        int u = Q.front().vertex;
        Q.deleteElement();
        if (shortestPath[u].visited) {
            continue;
        }
        shortestPath[u].visited = true;
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].vertex;
            int l = graph[u][i].weight;
            if(shortestPath[u].weight + l < shortestPath[v].weight) {
                shortestPath[v].weight = shortestPath[u].weight + l;
                shortestPath[v].prev = u;
                Q.add({v, shortestPath[v].weight});
            }
        }
    }
}

vector<int> getPath(vector<Dijkstra>& shortestPath, int source, int dest) {
    vector<int> path;
    if (shortestPath[dest].prev == -1) {
        return path;
    }

    while (dest != source) {
        path.push_back(dest);
        dest = shortestPath[dest].prev;
    }
    return path;
}

void printOutput(vector<Dijkstra>& shortestPath, vector<String>& cities, int source, int dest, bool withPath) {
    if (withPath == false) {
        cout << shortestPath[dest].weight << '\n';
    } else if (withPath == true){
        vector<int> path = getPath(shortestPath, source, dest);
        cout << shortestPath[dest].weight << " ";
        for (int i = (int)(path.size()-1); i > 0; i--) {
            if (cities[path[i]][0] != 0) {
                cout << cities[path[i]] << ' ';
            }
        }
        cout << '\n';
    }
}
