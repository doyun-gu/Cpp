/*
Write a program that uses a function called min that finds the smallest element in an array. 
The function has the following prototype: void min (int a [ ], int n, int * minimum)

An example call to min might be as follows:
min (b, N, &smallest);  b is an array of integers, N is the number of elements in b, and smallest is an int variable 

The program first prompts the user for five numbers(integers) and stores them in an array; 
the array is then passed to min which then searches forand prints out the smallest number entered.

An example of the output expected is shown below :
Enter five numbers : 12 7 14 - 2 0
The smallest number entered was : -2
*/

# include <stdio.h>
# define N 5

void min(int a[], int n, int *min);

int main(void) {
	int b[N], smallest;

	printf("Enter %d numbers: ", N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}

	min(b, N, &smallest);

	printf("\nThe smallest number entered was: %d\n", smallest);
}

void min(int a[], int n, int *min) {

	*min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < *min)
			*min = a[i];
	}
}
