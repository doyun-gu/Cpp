/* Write a simple program declaring two variables: int_var with type int and double_var with type double. Assign a value to each of them and print their values. 
The expected output is as follows:

int_var: 42
double_var: 24.000000
*/

# include <stdio.h>
int main (void) {
    int int_var = 42;
    double double_var = 24;


    printf("int_var: %d\n", int_var);
    printf("double_var: %lf", double_var);
}
