#include "priority_queue.h"


void swap(vertex_t* lhs, vertex_t* rhs){
    vertex_t temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int32_t priority_queue::get_right_child(int32_t index) const {
    if( ( ( ( 2 * index ) + 1 ) <= int32_t(queue.size()) ) && (index >= 0) ){
        return ((2 * index) + 1);
    }
    return -1;
}

int32_t priority_queue::get_left_child(int32_t index) const {
    if( ( ( ( 2 * index ) + 2 ) <= int32_t(queue.size()) ) && (index >= 0 ) ){
        return ((2 * index) + 2);
    }
    return -1;
}

int32_t priority_queue::get_parent(int32_t index) const {
    if( (index > 0) && (index <= int32_t(queue.size())) ){
        return (index/2);
    }
    return -1;
}

void priority_queue::min_heapify(int32_t index){
    int left_child_index = get_left_child(index);
    int right_child_index = get_right_child(index);
    int smallest = index;
    if( (left_child_index < int32_t(queue.size())) && (left_child_index > 0) ){
        if(queue[left_child_index].weight < queue[smallest].weight){
            smallest = left_child_index;
        }
    }
    if( (right_child_index < int32_t(queue.size())) && (right_child_index > 0) ){
        if(queue[right_child_index].weight < queue[smallest].weight){
            smallest = right_child_index;
        }
    }
    if(smallest != index){
        swap(queue[index], queue[smallest]);
        min_heapify(smallest);
    }
}

void priority_queue::emplace(vertex_t element){
    queue.push_back(element);
    int32_t temp = int32_t((queue.size()-1));
    while( (temp > 0) && (queue[get_parent(temp)].weight > queue[temp].weight) ){
        swap(queue[get_parent(temp)], queue[temp]);
        temp = get_parent(temp);
    }
}

bool priority_queue::empty() const {
    return queue.empty();
}

int priority_queue::size() const {
    return int32_t(queue.size());
}

vertex_t priority_queue::top() const {
    return queue[0];
}
    
void priority_queue::pop(){
    queue[0] = queue[queue.size()-1];
    queue.pop_back();
    min_heapify(0);
}
/*
void priority_queue::print_heap(){
    for(int32_t i = 0; i < int32_t(queue.size()); i++){
        cout << "(" << queue[i].vertex << " " << queue[i].weight << " ) "; 
    }
    cout << '\n';
}*/
/*
int main(){
    priority_queue a;
    a.emplace({213, 4});
    a.emplace({2, 1});
    a.emplace({13, 2});
    a.emplace({13, 3});
    a.emplace({13, 6});
    a.emplace({13, 7});
    a.emplace({13, 5});
    cout << a.top().weight << '\n';
    a.pop();
    //cout << a.top().vertex << '\n';
     cout << a.top().weight << '\n';
    a.pop();
     cout << a.top().weight << '\n';
    a.pop();
     cout << a.top().weight << '\n';

}*/