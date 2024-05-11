#pragma once
#include "vector.h"
#include "myString.h"
#include "consts.h"
#include <iostream>

extern int w;
extern int h;

typedef struct {
    int vertex;
    int weight; 
    int prev;
    bool visited;
} Dijkstra;

void dijkstraSearch(vector<vector<Vertex>> &graph, vector<Dijkstra>& shortestPath, int source);
void printOutput(vector<Dijkstra>& shortestPath, vector<String>& cities, int source, int dest, bool withPath);
