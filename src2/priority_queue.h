#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <climits>
#include "vector.h"
#include "structs.h"

class priority_queue {
private:
    vector<vertex_t> queue;
    int32_t get_right_child(int32_t index) const;
    int32_t get_left_child(int32_t index) const;
    int32_t get_parent(int32_t index) const;
    void min_heapify(int32_t index);
public:
    //void print_heap();
    int32_t size() const;
    void emplace(vertex_t element);
    vertex_t top() const;
    void pop();
    bool empty() const;
};

#endif /* PRIORITY_QUEUE_H */