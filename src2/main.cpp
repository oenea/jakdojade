#include <iostream>
#include <stdio.h>
#include <string.h>
#include <climits>
#include <stdint.h>
#include "vector.h"
#include "structs.h"
#include "town.h"
#include "priority_queue.h"
#include "path.h"

using namespace std;

const uint32_t HASH_TABLE_SIZE = 10000;
const uint32_t BUFFER_STRING_SIZE = 20;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    uint32_t w, h, town_count, longest_town_name;
    cin >> w >> h;
    const uint32_t VERTICES = uint32_t(w * h);

    char* map = new char[VERTICES + 1];
    input_map(map, VERTICES);

    get_town_info(map, VERTICES, town_count, longest_town_name);

    const uint32_t TOWN_COUNT = town_count;
    const uint32_t LONGEST_TOWN_NAME = (longest_town_name + 1);

    char* towns = new char[VERTICES * LONGEST_TOWN_NAME];
    input_town(map, towns, TOWN_COUNT, LONGEST_TOWN_NAME, w, h);

    
    vector<vector<vertex_t>> graph(VERTICES);

    input_graph(&graph, map, w, h);
    delete[] map;
   
    vector<vector<town_t>> hash_table(HASH_TABLE_SIZE);

    for (uint32_t i = 0; i < VERTICES; i++) {
        uint32_t temp = hashed(&towns[i * LONGEST_TOWN_NAME], HASH_TABLE_SIZE);
        town_t temp_town = {&towns[i * LONGEST_TOWN_NAME], int32_t(i)};
        hash_table[temp].push_back(temp_town);
    }

    char* buffer = new char[BUFFER_STRING_SIZE];
    char* where;
    char* from;
    fgets(buffer, BUFFER_STRING_SIZE, stdin);
    fgets(buffer, BUFFER_STRING_SIZE, stdin);
    uint32_t n = uint32_t(atoi(buffer));

    for (uint32_t i = 0; i < n; i++){
        uint32_t from_vertex = 0, where_vertex = 0;
        fgets(buffer, BUFFER_STRING_SIZE, stdin);
        int32_t weight = atoi(&buffer[strrchr(buffer, ' ') - buffer]);  
        buffer[strrchr(buffer, ' ') - buffer] = '\0';
        from = buffer;
        where = (strrchr(buffer, ' ') + 1);
        buffer[strrchr(buffer, ' ') - buffer] = '\0';

        uint32_t hash = hashed(from, HASH_TABLE_SIZE);
        for (uint32_t j = 0; j < hash_table[hash].size(); j++) {
            if(strcmp(from, hash_table[hash][j].town) == 0) {
                from_vertex = hash_table[hash][j].vertex;
            }
        }
        hash = hashed(where, HASH_TABLE_SIZE);
        for (uint32_t j = 0; j < hash_table[hash].size(); j++) {
            if(strcmp(where, hash_table[hash][j].town) == 0) {
                where_vertex = hash_table[hash][j].vertex;
            }
        }
        vertex_t temp = { int32_t(where_vertex), weight };
        graph[from_vertex].push_back(temp);
    }
    path_t* distance_table = new path_t[VERTICES];

    fgets(buffer, BUFFER_STRING_SIZE, stdin);

    n = uint32_t(atoi(buffer));

    for (uint32_t i = 0; i < n; i++) {
        uint32_t from_vertex = 0, where_vertex = 0;
        
        fgets(buffer, BUFFER_STRING_SIZE, stdin);

        bool option = bool(atoi(&buffer[strrchr(buffer, ' ') - buffer]));  

        buffer[strrchr(buffer, ' ') - buffer] = '\0';
        from = buffer;
        where = (strrchr(buffer, ' ') + 1);
        buffer[strrchr(buffer, ' ') - buffer] = '\0';  

        uint32_t hash = hashed(from, HASH_TABLE_SIZE);
        for (uint32_t j = 0; j < hash_table[hash].size(); j++) {
            if(strcmp(from, hash_table[hash][j].town) == 0) {
                from_vertex = hash_table[hash][j].vertex;
            }
        }
        hash = hashed(where, HASH_TABLE_SIZE);
        for (uint32_t j = 0; j < hash_table[hash].size(); j++) {
            if(strcmp(where, hash_table[hash][j].town) == 0) {
                where_vertex = hash_table[hash][j].vertex;
            }
        }
        search_path(graph, distance_table, VERTICES, from_vertex, where_vertex);
        print_answer(distance_table, towns, LONGEST_TOWN_NAME, from_vertex, where_vertex, option);
    }
    delete[] distance_table;
    delete[] towns;
    delete[] buffer;
}

