
#include <stdio.h>
#include <string.h>

#define MAX_EVENTS 100

struct Event {
    int day;
    int month;
    int priority;
    char description[256];
};

int cmp_event(const void* a, const void* b) {
    const struct Event* event_a = (const struct Event*)a;
    const struct Event* event_b = (const struct Event*)b;
    if (event_a->priority != event_b->priority) {
        return event_b->priority - event_a->priority;
    } else if (event_a->month != event_b->month) {
        return event_a->month - event_b->month;
    } else {
        return event_a->day - event_b->day;
    }
}

int main() {
    int year;
    scanf("%d", &year);
    struct Event events[MAX_EVENTS];
    int num_events = 0;
    while (1) {
        char type;
        scanf(" %c", &type);
        if (type == '#') {
            break;
        }
        int day, month, priority;
        scanf("%d %d", &day, &month);
        if (type == 'A') {
            scanf("%d", &priority);
            char description[256];
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';
                       struct Event event = {day, month, priority};
            strcpy(event.description, description);
            events[num_events++] = event;
        } else if (type == 'D') {
            printf("Today is: %d %d\n", day, month);
            qsort(events, num_events, sizeof(struct Event), cmp_event);
            int i, j;
            for (i = 0; i < num_events; i++) {
                int days_until_event = 0;
                if (events[i].month > month || (events[i].month == month && events[i].day >= day)) {
                    days_until_event = days_until_event + (events[i].day - day) + (events[i].month - month) * 30;
                } else {
                    days_until_event = days_until_event + (events[i].day - day) + (12 - month + events[i].month) * 30;
                }
                if (days_until_event == 0) {
                    printf("%3d %2d *TODAY* %s\n", events[i].day, events[i].month, events[i].description);
                } else if (days_until_event == 1) {
                    printf("%3d %2d %s", events[i].day, events[i].month, events[i].description);
                    for (j = 0; j < events[i].priority; j++) {
                        printf("*");
                    }
Continuation:

                printf("\n");
                } else if (days_until_event == 2) {
                    printf("%3d %2d %s", events[i].day, events[i].month, events[i].description);
                    for (j = 0; j < events[i].priority - 1; j++) {
                        printf("*");
                    }
                    printf("\n");
                } else if (days_until_event <= events[i].priority + 2) {
                    printf("%3d %2d %s", events[i].day, events[i].month, events[i].description);
                    for (j = 0; j < events[i].priority - days_until_event + 2; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
