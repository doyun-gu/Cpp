/*
Write a program that stores the following ten data items in an integer array and stores the squares of the items in a new array:
415 243 755 452 676 -210 -45 6 82 -73

Print out the data in both arrays to check they have been saved correctly
*/

# include <stdio.h>

int main(void) {
	int data[10] = { 415, 243, 755, 452, 676, -210, -45, 6, 82, -73 };
	int squares[10];

	for (int i = 0; i < 10; i++) {

		printf("%d", data[i]);
		squares[i] = data[i] * data[i];
	}

	printf("\n");

	for (int i = 0; i < 10; i++) {

		printf("%d", squares[i]);
	}
	printf("\n");

	return 0;
}
