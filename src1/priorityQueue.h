#pragma once

#include <iostream>
#include "vector.h"
#include "consts.h"

using namespace std;

class priorityQueue
{
public:
    int getSize() const;
    int deleteElement();  
    bool empty() const;
    void add(Vertex item); 
    Vertex front() const;
private:
    vector<Vertex> prQueue;
    void rebuildPrQueue(int i);
};
