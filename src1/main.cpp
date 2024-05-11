#include <iostream>
#include "consts.h"
#include "vector.h"
#include "myString.h"
#include "city.h"
#include "dijkstra.h"
#include "input.h"

using namespace std;

int w, h;

int main(){
    int* hashTable = new int[2000000];
    int a, b;
    cin >> a >> b;
    w = a;
    h = b;
    char* map = new char[w*h];
    vector<City> citiesVector;
    vector<String> cities(w*h);
    City temp;
    bool isStringInput = false;
    for (int i = 0; i < w*h; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < w*h; i++) {
        if (isStringInput == true) {
            if ( !(isalnum(map[i])) ) {
                temp.last = i-1;
                if (temp.vertex == -1) {
                    temp.vertex = getCityVertex(map, i-1);
                }
                citiesVector.push_back(temp);
                temp.name.clear();
                temp.first = -1;
                isStringInput = false;
            } else {
                temp.name.push_back(map[i]);
            }
        }
        if (isStringInput == false) {
            if ( isalnum(map[i]) ) {
                temp.name.push_back(map[i]);
                temp.first = i;
                temp.vertex = getCityVertex(map, i);
                isStringInput = true;
            }
        }
    }
    if ( isalnum(map[w*h-1]) ) {
        citiesVector.push_back(temp);
    }

    vector<vector<Vertex>> graph(w*h);
    completeGraph(graph, map, citiesVector);
    delete[] map;

   
    addCities(cities, citiesVector);
    for (int i = 0; i < (int)citiesVector.size(); i++) {
        hashTable[hashing(citiesVector[i].name)] = citiesVector[i].vertex;
    }

    
    int n, source = -1, dest = -1;
    String sourceName, destName;
    vector<Dijkstra> shortestPath(graph.size());

    cin >> n;
   
    for (int i = 0; i < n; i++) {
        inputString(sourceName);
        inputString(destName);
        int length = inputInt();
        source = hashTable[hashing(sourceName)];
        dest = hashTable[hashing(destName)];
        graph[source].push_back({dest, length});
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        inputString(sourceName);
        inputString(destName);
        bool withPath = inputBool();
        source = hashTable[hashing(sourceName)];
        dest = hashTable[hashing(destName)];
        dijkstraSearch(graph, shortestPath, source);
        printOutput(shortestPath, cities, source, dest, withPath);
    }
    delete[] hashTable;
}

