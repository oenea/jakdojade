#pragma once

#include "vector.h"
#include "consts.h"

using namespace std;

extern int w;
extern int h;

int getCityVertex(char* map, int vertex);
void addCities(vector<String>& cities, vector<City>& citiesVector);
int hashing(String input);
void completeGraph(vector<vector<Vertex>>& graph, char* map, vector<City>& citiesVector);

