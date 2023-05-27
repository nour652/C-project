#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define INCREMENT_FACTOR 0.001
#define DECREMENT_FACTOR -0.0001
#define TOLERANCE 0.1

int main() {
    float initial_temp, desired_temp;
    float upper_limit, lower_limit;
    bool oven_door_closed = false;

    // Get initial temperature and desired temperature from user
    printf("Enter current oven temperature: ");
    scanf("%f", &initial_temp);
    printf("Enter desired oven temperature: ");
    scanf("%f", &desired_temp);

    // Calculate temperature limits based on desired temperature and tolerance
    upper_limit = desired_temp + TOLERANCE * desired_temp;
    lower_limit = desired_temp - TOLERANCE * desired_temp;

    // Check if oven door is closed
    char answer[10];
    do {
        printf("Is the oven door closed? (y/n) ");
        scanf("%s", answer);
        if (answer[0] == 'y' || answer[0] == 'Y') {
            oven_door_closed = true;
        }
    } while (!oven_door_closed);

    // Increment temperature until upper limit is reached
    printf("OVEN ON\n");
    while (initial_temp < upper_limit) {
        printf("Temperature: %.2f\n", initial_temp);
        initial_temp += INCREMENT_FACTOR * desired_temp;
        sleep(1);
        if (initial_temp > upper_limit) {
            printf("OVEN OFF\n");
        }
    }

    // Decrement temperature until lower limit is reached
    printf("OVEN ON\n");
    while (initial_temp > lower_limit) {
        printf("Temperature: %.2f\n", initial_temp);
        initial_temp += DECREMENT_FACTOR * desired_temp;
        sleep(1);
        if (initial_temp < lower_limit) {
            printf("OVEN ON\n");
        }
    }

    // Restart electric heater when lower limit is reached
    while (true) {
        // Increment temperature until upper limit is reached
        printf("OVEN ON\n");
        while (initial_temp < upper_limit) {
            printf("Temperature: %.2f\n", initial_temp);
            initial_temp += INCREMENT_FACTOR * desired_temp;
            sleep(1);
            if (initial_temp > upper_limit) {
                printf("OVEN OFF\n");
            }
        }

        // Decrement temperature until lower limit is reached
        printf("OVEN ON\n");
        while (initial_temp > lower_limit) {
            printf("Temperature: %.2f\n", initial_temp);
            initial_temp += DECREMENT_FACTOR * desired_temp;
            sleep(1);
            if (initial_temp < lower_limit) {
                printf("OVEN ON\n");
            }
        }
    }

    return 0;
}
