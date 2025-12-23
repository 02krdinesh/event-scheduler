#include <stdio.h>
#include "scheduler.h"

void say_hello(void* data) {
    printf("Hello from %s!\n", (char*)data);
}

int main() {
    scheduler_init();

    schedule_event(5.0, say_hello, "Event A (Delay 5)");
    schedule_event(2.0, say_hello, "Event B (Delay 2)");
    schedule_event(10.0, say_hello, "Event C (Delay 10)");

    printf("Starting Scheduler...\n");
    scheduler_run();
    printf("Done.\n");

    return 0;
}