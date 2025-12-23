#ifndef HEAP_H
#define HEAP_H

typedef struct {
    double time;
    void (*callback)(void*);
    void* data;
} Event;

typedef struct {
    Event** data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity);
void push_heap(MinHeap* heap, Event* event);
Event* pop_heap(MinHeap* heap);
void free_heap(MinHeap* heap);

#endif