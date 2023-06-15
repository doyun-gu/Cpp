/* Lab 9a Task3 Solution */

/* 
   Complete the following:
   (a) The declaration of the structure tag called 'date' that has
       three un-initialized int variables: day, month and year.
   (b) The scanf statement that stores the typed input.
   (c) The function dayOfYear.
   (d) The printf statement that calls dayOfYear.
*/

#include <stdio.h>

struct date {
       int day, month, year;
};

/* function prototype */
int dayOfYear(struct date d); /* returns the day of the year
                                 (an integer between 1 and 366)
                                 that corresponds to the date d */

int main(void)  {

    struct date theDate;
    printf ("Enter the date in the format dd/mm/yy: \n");
    scanf ("%d/%d/%d", &theDate.day, &theDate.month, &theDate.year);
    printf ("The number of days elapsed so far this year = %d\n", dayOfYear(theDate));

    return 0;
}

int dayOfYear(struct date d) {
    int day, month, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    /* optional leap year adjustment */
    if ((d.year % 4 == 0) && (d.year % 100 != 0 || d.year % 400 == 0)) {days[2]++;}

    day = d.day;
    for (month = 1; month < d.month; month++) {
       day += days[month];
    }
    return day;
}
