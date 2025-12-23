#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "heap.h"

void scheduler_init();
void schedule_event(double delay, void (*callback)(void*), void* data);
void scheduler_run();

#endif