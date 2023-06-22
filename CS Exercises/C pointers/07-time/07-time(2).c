/*
Write a C program taking an integer n as command line parameter and sleeping for n seconds. 
The execution time of the sleep function is measured and displayed. 

Examples output:
./time 3
sleep duration: 3.000082 seconds

./time 5
sleep duration: 5.000108 seconds
*/

// This code is only able with Linux
#include <sys/time.h>  // needed for gettimeofday
#include <unistd.h> // needed for sleep
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc > 2) return -1;

    struct timeval start, stop, elapsed;

    int n = atoi(argv[1]);

    // record time before sleeping
    gettimeofday(&start, NULL);
    // sleep for n seconds
    sleep(n);
    // record time after sleeping
    gettimeofday(&stop, NULL);

    // calculation
    timersub(&stop, &start, &elapsed);

    printf("sleep duration: %lu.%06lu seconds\n", elapsed.tv_sec, elapsed.tv_usec);

    return 0;
}
