#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>

using namespace std;

typedef struct {
    int32_t vertex;
    int32_t weight;
} vertex_t;

typedef struct {
    int32_t weight; 
    int32_t previous;
    bool visited;
} path_t;

typedef struct {
    int32_t x;
    int32_t y;
} pos_t;

typedef struct {
    char* town;
    int32_t vertex;
} town_t;



#endif /* STRUCTS_H */