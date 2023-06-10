/*
Write a program that uses a function called max that finds the largest element in an array. The function has the following prototype:
void max (int a [ ], int n, int * maximum);

Similar to a) above, the program prompts the user for five values which are stored in an array, and then prints out the largest number entered.
*/

# include <stdio.h>
# define N 5

/* Set the function for analyse the maximum value */
void max(int a[], int n, int *max);

int main(void) {
	int b[N], largest;

	/* Read the value of five to check*/
	printf("Enter five values to figure out the largest value: ");

	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}

	max(b, N, &largest);

	printf("\nThe largest number among the five values is %d", largest);
}

void max(int a[], int n, int *max) {

	*max = a[0];
	for (int i = 0; i < N; i++)
		if (a[i] > *max) {
			*max = a[i];
		}
}
