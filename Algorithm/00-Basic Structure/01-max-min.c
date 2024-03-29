// Maximum and minimum value among 4 different inputs
// second minimum value
#include <stdio.h>
#include <limits.h>

int main(void) {
    int a, b, c, d;
    int i;

    // Take inputs
    printf("Find the maximum value among the three integer values \n");
    printf("Value a: "); scanf("%d", & a);
    printf("Value b: "); scanf("%d", & b);
    printf("Value c: "); scanf("%d", & c);
    printf("Value d: "); scanf("%d", & d);

    int array [4] = {a, b, c, d};
    int max = array[0];
    int min = array[0];
    int sec_min = INT_MAX;

    // Find Maximum and minimum value
    for (i = 0; i < 4; i++) {

        if (array[i] > max) {
            max = array[i];
        }

        if (array[i] < min) {
            min = array[i];
        }
    }

    // Find second minimum value
    for (i = 0; i < 4; i++) {

        if (array[i] != min & array[i] < sec_min) {
            sec_min = array[i];
        }

    }

    // In case second minimum value is INT_MAX
    if (sec_min == INT_MAX) {
        sec_min = min;
    }

    // Output
    printf("Maximum Value: %d, minimum value: %d, second smallest value: %d\n", max, min, sec_min);

    return 0;
}
