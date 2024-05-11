#ifndef PATH_H
#define PATH_H

#include "vector.h"
#include "structs.h"

void input_map(char* map, const uint32_t vertices);
void input_graph(vector<vector<vertex_t>>* graph, char* map, const int32_t w, const int32_t h);
void search_path(vector<vector<vertex_t>>& graph, path_t* distance_table, const uint32_t vertices, const int32_t from, const int32_t where);
vector<int32_t> get_path(path_t* distance_table, const int32_t from_vertex, const int32_t where_vertex);
void print_answer(path_t* distance_table, char* towns, const uint32_t longest_town_name, const int32_t from_vertex, int32_t where_vertex, const bool option);

#endif /* PATH_H */