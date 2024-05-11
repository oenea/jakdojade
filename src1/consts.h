#pragma once

#include "myString.h"

using namespace std;

typedef struct {
    int vertex;
    int weight = 1;
} Vertex;

typedef struct {
    String name;
    int first = -1;
    int last = -1;
    int vertex = -1; 
    bool visited = false; 
} City;

