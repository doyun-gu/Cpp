/*
Consider the following structure:

struct timestamp {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
}

Using this structure, write a C program adding two timestamps and displaying the result on the standard output. 
The program takes 6 command line parameters corresponding to the two timestamps. 
The addition is realized in a function named add_timestamps that takes 2 timestamp parameters and return the sum as a timestamp. 
Here are some output examples:

# 5h11m44s + 12h30m3s = 17h41m47s
./timestamp 5 11 44 12 30 3
17 41 47

# 10h30m50s + 1h5m15s = 11h36m5s
./timestamp 10 30 50 1 5 15
11 36 5

# 14h12m5s + 22h5m0s = 36h17m5s
./timestamp 14 12 5 22 5 0
36 17 5
*/

# include <stdio.h>
# include <stdlib.h>

struct timestamp {
    unsigned int hour;
    unsigned int minute;
    unsigned int second; };

struct timestamp sum_ts(struct timestamp a, struct timestamp b) {

    /* Declare new structure for the result of sum */
    struct timestamp sum;

    sum.hour = a.hour + b.hour;
    sum.minute = a.minute + b.minute;
    sum.second = a.second + b.second;

    if (sum.second > 59) {
        sum.minute ++;
        sum.second = sum.second - 60;
    }

    if (sum.minute > 59) {
        sum.hour ++;
        sum.minute = sum.minute - 60;
    }

    return sum;
}

int main (int argc, char **argv) {

    if (argc != 7) {
        printf("Error: Number of Arguments must be 6!");

        return 1;
    }

    struct timestamp part1, part2;

    part1.hour = atoi(argv[1]);
    part1.minute = atoi(argv[2]);
    part1.second = atoi(argv[3]);

    part2.hour = atoi(argv[4]);
    part2.minute = atoi(argv[5]);
    part2.second = atoi(argv[6]);

    struct timestamp sum = sum_ts(part1, part2);

    printf("%d %d %d\n", sum.hour, sum.minute, sum.second);

    return 0;

}
