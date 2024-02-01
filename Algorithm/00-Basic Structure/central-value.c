// Find central value when three inputs are read
#include <stdio.h>

int central(int a, int b, int c) {
    if (a >= b){
        if (b >= c) {
            return b;
        }

        else if (a <= c) {
            return a;
        }

        else {
            return c;
        }
    }

    else if (a > c) {
        return a;
    }

    else if (b > c) {
        return c;
    }

    else {
        return b;
    }
}

int main (void) {

    int a, b, c;

    printf("Find the central value\n");

    printf("Value a: "); scanf("%d", &a);
    printf("Value b: "); scanf("%d", &b);
    printf("Value c: "); scanf("%d", &c);

    printf("Central value is %d\n", central(a, b, c));

    return 0;
}
