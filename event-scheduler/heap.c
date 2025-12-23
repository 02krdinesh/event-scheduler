#include <stdlib.h>
#include "heap.h"

MinHeap* create_heap(int capacity) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->data = malloc(sizeof(Event*) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void push_heap(MinHeap* heap, Event* event) {
    int i = heap->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap->data[p]->time <= event->time) break;
        heap->data[i] = heap->data[p];
        i = p;
    }
    heap->data[i] = event;
}

Event* pop_heap(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    Event* res = heap->data[0];
    Event* last = heap->data[--heap->size];
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int child = i * 2 + 1;
        if (child + 1 < heap->size && heap->data[child+1]->time < heap->data[child]->time) 
            child++;
        if (last->time <= heap->data[child]->time) break;
        heap->data[i] = heap->data[child];
        i = child;
    }
    heap->data[i] = last;
    return res;
}

void free_heap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}