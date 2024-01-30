// Find the Maximum values among the three integer values

#include <stdio.h>

int main (void) {
    int a, b, c;

    printf("Find the maximum value among the three integer values \n");
    printf("Value a: "); scanf("%d", & a);
    printf("Value b: "); scanf("%d", & b);
    printf("Value c: "); scanf("%d", & c);

    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    printf("Maximum value is %d \n", max);

    return 0;
}
