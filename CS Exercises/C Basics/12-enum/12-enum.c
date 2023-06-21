/*
The program below uses integer to represent days of the week, 0 corresponding to Monday, 1 to Tuesday, etc.

#include <stdio.h>

int main(int argc, char **argv) {
    int d = 2;

    printf("Today is: ");
    switch(d) {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;

        default:
            printf("Unknown day...\n");
    }
    return 0;
}

Replace the use of integers with that of an enumeration named enum day, defining constants for days: MONDAY, TUESDAY, etc.

The expected output is:

./enum
Today is: Wednesday
*/

#include <stdio.h>

enum day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(int argc, char **argv) {
    enum day d = WEDNESDAY;

    printf("Today is: ");
    switch(d) {
        case MONDAY:
            printf("Monday\n");
            break;
        case TUESDAY:
            printf("Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Wednesday\n");
            break;
        case THURSDAY:
            printf("Thursday\n");
            break;
        case FRIDAY:
            printf("Friday\n");
            break;
        case SATURDAY:
            printf("Saturday\n");
            break;
        case SUNDAY:
            printf("Sunday\n");
            break;

        default:
            printf("Unknown day...\n");
    }
    return 0;
}
