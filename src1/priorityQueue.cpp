#include "priorityQueue.h"

int priorityQueue::getSize() const {
    return prQueue.size();
}

int priorityQueue::deleteElement() {
    if (getSize() == 0) {
        return -1;
    }
    int min = prQueue[0].vertex;
    prQueue[0] = prQueue[getSize() - 1];
    prQueue.pop_back();
    rebuildPrQueue(0);
    return min;
}

bool priorityQueue::empty() const {
    return getSize() == 0;
}

void priorityQueue::add(Vertex item) {
    prQueue.push_back(item);
    int i = getSize() - 1;
    while (i > 0 && prQueue[i].weight < prQueue[i / 2].weight)
    {
        Vertex temp = prQueue[i];
        prQueue[i] = prQueue[i / 2];
        prQueue[i / 2] = temp;
        i = (i / 2);
    }
}

Vertex priorityQueue::front() const {
    return prQueue[0];
}

void priorityQueue::rebuildPrQueue(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < getSize() && left > 0 && prQueue[left].weight < prQueue[smallest].weight) {
        smallest = left;
    }
    if (right < getSize() && right > 0 && prQueue[right].weight < prQueue[smallest].weight) {
        smallest = right;
    }
    if (smallest != i) {
        Vertex temp = prQueue[i];
        prQueue[i] = prQueue[smallest];
        prQueue[smallest] = temp;
        rebuildPrQueue(smallest);
    }
}


