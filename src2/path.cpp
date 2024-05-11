#include "path.h"
#include "priority_queue.h"
#include "town.h"

void input_map(char* map, const uint32_t vertices) {
    for (uint32_t i = 0; i < vertices; i++){
        char c = char(getchar());
        while ( isspace(c) ) {
            c = char(getchar());
        }
        map[i] = c;
    }
    map[vertices] = '\0';
}

void input_graph(vector<vector<vertex_t>>* graph, char* map, const int32_t w, const int32_t h){
    static const pos_t paths_offset[4] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };
    for (uint32_t i = 0; i < uint32_t(w * h); i++){
        if ( (map[i] == '#') || (map[i] == '*') ){
            int32_t x = (i / w);
            int32_t y = (i % w);
            for (uint8_t j = 0; j < 4; j++){
                if (is_bound(paths_offset[j].x + x, w) && is_bound(paths_offset[j].y + y, w)){
                    int32_t temp = ((paths_offset[j].x + x) * w + (paths_offset[j].y + y));
                    if (is_bound(temp, w, h)){
                        if ( (map[ temp ] == '#') || (map[ temp ] == '*') ){
                            graph->at(i).push_back({ temp, 1});
                        }
                    }
                }
            }
        }
    }
}

void search_path(vector<vector<vertex_t>>& graph, path_t* distance_table, const uint32_t vertices, const int32_t from, const int32_t where){
    for (uint32_t i = 0; i < vertices; i++){
        distance_table[i] = {INT_MAX, -1, false};
    }
    distance_table[from].weight = 0;
    priority_queue Q;
    Q.emplace({from, 0});
    while ( !Q.empty() ){
        int32_t u = Q.top().vertex;
        if (u == where) return;
        Q.pop();
        if (distance_table[u].visited) continue;
        distance_table[u].visited = true;
        for (uint32_t i = 0; i < uint32_t(graph[u].size()); i++){
            int32_t v = graph[u][i].vertex;
            int32_t l = graph[u][i].weight;

            if ((distance_table[u].weight + l) < distance_table[v].weight){
                distance_table[v].weight = distance_table[u].weight + l;
                distance_table[v].previous = u;
                Q.emplace({v, distance_table[v].weight});
            }
        }
    }
}

vector<int32_t> get_path(path_t* distance_table, const int32_t from_vertex, int32_t where_vertex){
    vector<int32_t> path;
    if (distance_table[where_vertex].previous == -1) return path;
    while (where_vertex != from_vertex){
        path.push_back(where_vertex);
        where_vertex = distance_table[where_vertex].previous;
    }
    return path;
}

void print_answer(path_t* distance_table, char* towns, const uint32_t longest_town_name, const int32_t from_vertex, const int32_t where_vertex, const bool option){
    cout << distance_table[where_vertex].weight << " ";
    if (option == true){
        vector<int32_t> path = get_path(distance_table, from_vertex, where_vertex);
        for (int32_t i = int32_t(path.size()-1); i > 0; i--){
            if (towns[path[i] * longest_town_name] != 0){
                cout << &towns[path[i] * longest_town_name] << " ";
            }
        }
    }
    cout << "\n";
}