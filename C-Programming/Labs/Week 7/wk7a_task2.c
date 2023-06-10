/*
Write a program that prompts the user for two numbers (integers) and stores them in variables called 'first' and 'second'. 
It then calls a function called swap that exchanges the values of 'first' and 'second'. 
The prototype for swap is shown below:
void swap (int *p, int *q);

When passed the addresses of two variables swap should exchange their values:
swap (&first, &second);  exchanges the values of i and j 

An example of the output expected is shown below :
Enter the value of the first number : 12
Enter the value of the second number : 6

(after swap is called)

The value of the first number is now : 6
The value of the second number is now : 12
*/

# include <stdio.h>

void swap(int* p, int* q);

int main(void) {
	int first, second;

	/* Read the value for the first and second */
	printf("Enter the value of the first number: ");
	scanf("%d", &first);

	printf("Enter the value of the second number: ");
	scanf("%d", &second);

	/* Check the values */
	printf("\nYou Entered: (first) %d and (second) %d\n", first, second);

	swap(&first, &second);

	printf("\nThe value of the first number is now %d\n", first);
	printf("\nThe value of the second number is now %d\n", second);

	return 0;
}

void swap(int* p, int* q) {

	/* Save the value pointed to by p in a temporary variable: */
	int temp = *p;

	/* Replace the value pointed to by p with that pointed to by q: */
	*p = *q;

	/* replace the value pointed to by q by that saved in the temporary variable: */
	*q = temp;
}
