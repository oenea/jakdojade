#include "city.h"
#include "priorityQueue.h"
#include <iostream>


bool isNeighbor(int i);
bool isNeighbor(int i , int a);

int getCityVertex(char* map, int vertex){
    int x = vertex/w;
    int y = vertex%w;
    int adjX[8] = {x-1, x, x+1, x, x-1, x+1, x-1, x+1};
    int adjY[8] = {y, y-1, y, y+1, y+1, y-1, y-1, y+1};

    for (int i = 0; i < 8; i++) {
        if ( isNeighbor(adjX[i], w) ) {
            if ( isNeighbor(adjY[i], w) ) {
                int pos = (adjX[i] * w + adjY[i]);
                if ( isNeighbor(pos) ) {
                    if (map[pos] == '*') {
                        return pos;     
                    }
                }
            }
        }   
    }
    return -1;
}

void addCities(vector<String>& cities, vector<City>& citiesVector){
    for (int i = 0; i < (int)citiesVector.size(); i++) {
        cities[citiesVector[i].vertex] = citiesVector[i].name;
    }
}

bool isNeighbor(int i, int a){
    return ( (i >= 0) && (i < a) );
}

bool isNeighbor(int i) {
    return ( (i >= 0) && (i < w*h) );
}

int hashing(String input){
    int hash = 0;
    for (int i = 0; i < (int)input.length(); i++) {
    hash += input[i];
    hash *= 0x5bd1e995;
    hash ^= input[i] >> 15;
  }
  return (((unsigned int)hash) % 2000000);
}               

void completeGraph(vector<vector<Vertex>>& graph, char* map, vector<City>& citiesVector) {
    bool* mapVisited = new bool[w*h];
    for (int i = 0; i < w*h; i++) {
        mapVisited[i] = false;
    }
    priorityQueue Q;
    for (int i = 0; i < (int)citiesVector.size(); i++) {
        if (mapVisited[citiesVector[i].vertex] == false) {
            mapVisited[citiesVector[i].vertex] = true;
            Q.add({citiesVector[i].vertex});
            while ( !Q.empty() ) {
                int u = Q.front().vertex;
                Q.deleteElement();
                int x = u/w;
                int y = u%w;
                int adjX[4] = {x-1, x, x+1, x};
                int adjY[4] = {y, y-1, y, y+1};
                for (int j = 0; j < 4; j++) {
                    if ( isNeighbor(adjX[j], w) ) {
                        if ( isNeighbor(adjY[j], w) ) {
                            int pos = (adjX[j] * w + adjY[j]);
                            if ( isNeighbor(pos) ) {
                                if ( (map[pos] == '#') || (map[pos] == '*') ) {
                                    graph[u].push_back({pos});
                                    if(mapVisited[pos] == false) {
                                        mapVisited[pos] = true;
                                        Q.add({pos});
                                    }
                                }
                            } 
                        }
                    }
                }
            }               
        }
    }
    delete[] mapVisited;
}