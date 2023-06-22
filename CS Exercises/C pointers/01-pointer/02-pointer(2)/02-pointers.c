/* With a linked list, the programmer uses pointer chains to link together data structures. 
In the example program below, a simple linked list with 3 elements is constructed then the value of the last element is printed:

#include <stdio.h>

/* Typedef struct forward declaration for the pointer member */ 
/*
typedef struct s_list_member list_member;

typedef struct s_list_member {
    int value;
    list_member *next;
} list_member;

int main(int argc, char **argv) {
    list_member lm1, lm2, lm3;

    lm1.value = 1; lm1.next = &lm2;
    lm2.value = 2; lm2.next = &lm3;
    lm3.value = 3; lm3.next = 0x0;

    printf("third member value is: %d\n", lm3.value);

    return 0;
}

Modify the second parameter of the call to printf in order to print the value of the third element by using the first member lm1 
and following the pointer chain leading to the value of lm3. 

The expected output is:

./pointer2
third member value is: 3
*/

# include <stdio.h>

/* Forward Declaration */
typedef struct s_list_member list_member;

/* Actual Declaration */
typedef struct s_list_member {
    int value;
    list_member *next;
} list_member;

int main(int argc, char **argv) {
    list_member lm1, lm2, lm3;

    lm1.value = 1; lm1.next = &lm2;
    lm2.value = 2; lm2.next = &lm3;
    lm3.value = 3; lm3.next = 0x0;

    printf("third member value is: %d\n", lm1.next->next->value);

    return 0;
}
