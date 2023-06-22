#include <stdlib.h>
#include <time.h> // used for gettimeofday
#include <Windows.h>   // used when sleeps

int main (int argc, char **argv) {

    if (argc > 2) return -1;

    int n = atoi (argv[1])*1000; // convert into milliseconds for Sleep ()

    // record the time before sleep
    clock_t start = clock();
    // after n seconds, the the codes carry on
    Sleep(n);
    // record the time after sleep
    clock_t stop = clock ();

    // time_after - time_before
    double elapsed = ((double)(stop-start)/1000);

    printf("Sleep duration: %.6lf seconds\n", elapsed);


    return 0;
}
