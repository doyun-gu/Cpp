/*
Write a program that uses a function called avg_sum that calculates the sum and average of a set of five floating point numbers. 

The function has the following prototype:
void avg_sum (double data [ ], int n, double *a, double *s);

An example call to avg_sum might be as follows:
avg_sum (numbers, N, &avg, &sum); 
/*

/*
numbers is an array of doubles, N is the number of elements in numbers, and avg and sum are variables of type double
/*

/* The program first prompts the user for five numbers(doubles) and stores them in an array; 
the array is then passed to avg_sum from which it calculates the sumand average.

An example of the output expected is shown below :
Enter five numbers : 12.2 7.7 14.1 - 2.3 0.1

The sum is 31.80 and the average is 6.36 
*/

# include <stdio.h>
#define N 5

void avg_sum (double a[], int n, double *avg, double *sum);

int main(void) {

	/* Declare an array to store the numbers: */
	double b[N];

	/* Declare two variables to store the average and sum: */
	double avg = 0.0, sum = 0.0;

	printf("Enter %d numbers: ", N);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &b[i]);
	}

	/* callavg_sum, passing the array, N, and the two pointers: */
	avg_sum(b, N, &avg_sum);

	/* print out the results: */
	printf("\nThe sum is %.2lf and the average is %.f\n", sum, avg);
}

void avg_sum(double a[], int n, double *avg, double *sum) {
	*sum = 0.0, *avg = 0.0;

	for (int i = 0; i < N; i++); {
		*sum += a[i];
	}

	*avg = *sum / n;
}
