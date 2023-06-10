/*
Write a program that sets a variable to an amount in Euros and then calculates
how to pay that amount in the smallest number of 50, 20, 10, 5 Euro notes and 1
Euro coins. Example output:

Amount in euros: 93
50 Euro notes: 1
20 Euro notes: 2
10 Euro notes: 0
5 Euro notes: 0
1 Euro coins: 3
*/

# include <stdio.h>
int main(void) {
	int EuroT=93, Euro50, Euro20, Euro10, Euro5, Euro1;

	Euro50 = 93 / 50;
	Euro20 = (93 - Euro50 * 50) / 20;
	Euro10 = (93 - Euro50 * 50 - Euro20 * 20) / 10;
	Euro5 = (93 - Euro50 * 50 - Euro20 * 20 - Euro10 * 10) / 5;
	Euro1 = (93 - Euro50 * 50 - Euro20 * 20 - Euro10 * 10 - Euro5 * 5) / 1;

	printf("Amount in Euros: %d\n", EuroT);
	printf("50 Euro notes: %d\n", Euro50);
	printf("20 Euro notes: %d\n", Euro20);
	printf("10 Euro notes: %d\n", Euro10);
	printf("5 Euro notes: %d\n", Euro5);
	printf("1 Euro notes: %d\n", Euro1);

	return 0;
}
