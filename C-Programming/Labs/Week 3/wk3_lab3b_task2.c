/*
Using a switch statement, write a program that converts a integer grade into a letter grade, for example:
Enter a numerical grade: 45
Letter Grade: F
Use the following grade scale: A=90-100, B=80-89, C=70-79, D=60-69, F=0-59.
Print an error message if the number entered is greater than 100 or less than 0.
Hint: divide the grade by ten, then use a switch statement to test the ten’s digit.
*/

#include <stdio.h>

int main(void) {
	int read_grade, grade_in_digit;

	printf("Enter a numerical grade: ");
	scanf("%d", &read_grade);

	grade_in_digit = read_grade / 10;

	if (read_grade > 100)
		printf("illegal grade\n");
	else
		switch (grade_in_digit) {
		case 10:
		case 9: printf("Letter grade: A\n");
			break;
		case 8: printf("Letter grade: B\n");
			break;
		case 7: printf("Letter grade: C\n");
			break;
		case 6: printf("Letter grade: D\n");
			break;
		default: printf("Letter grade: F\n");
		}
	return 0;
}
