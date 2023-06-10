# include <stdio.h>
# define N 5

void min(int a[], int n, int *min);
void max(int a[], int n, int *max);

int main(void) {
	/* Declare array, smallest, largest variables before read and analyse the values */
	int b[N], smallest, largest; 

	/* Read the values */
	printf("Enter five values to analyse: ");
	
	/* Read values for i=0-4 and store in array of b */
	for (int i = 0; i < N; i++){
		scanf("%d", &b[i]);
	}

	/* Set functions for analyse maximum and minimum values */
	min(b, N, &smallest);
	max (b, N, &largest);
	
	/* Print the smallest and largest value respectively.*/
	printf("\n The smallest value is %d.", smallest);
	printf("\n The largest value is %d.", largest);
}

/* Minimum */
void max(int a[], int n, int *min) {
	*min = a[0];
	for (int i = 0; i < N; i++) {
		if (a[i] < *min) {
			*min = a[i];
		}
	}
}

/* Maximum */
void min(int a[], int n, int *max) {
	*max = a[0];
	for (int i = 0; i < N; i++) {
		if (a[i] > *max) {
			*max = a[i];
		}
	}
}
