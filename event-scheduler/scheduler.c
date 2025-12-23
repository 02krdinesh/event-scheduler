#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

static MinHeap* event_queue;
static double current_time = 0.0;

void scheduler_init() {
    event_queue = create_heap(100);
    current_time = 0.0;
}

void schedule_event(double delay, void (*callback)(void*), void* data) {
    Event* ev = malloc(sizeof(Event));
    ev->time = current_time + delay;
    ev->callback = callback;
    ev->data = data;
    push_heap(event_queue, ev);
}

void scheduler_run() {
    while (event_queue->size > 0) {
        Event* ev = pop_heap(event_queue);
        current_time = ev->time;
        printf("[Time: %.2f] Executing event...\n", current_time);
        ev->callback(ev->data);
        free(ev);
    }
    free_heap(event_queue);
}