/* 
The following function splits the total number of seconds (entered by say, a user)
elapsed since the start of the day, into hours, minutes and seconds:
struct time splitTime (long totalSeconds)
The function returns the 'time' structure that contains three members: hours,
minutes and seconds (all of type int). Write a program that includes and calls this
function printing out the time in the format hh:mm:ss.
*/

/* Lab 9a Task4 Solution */

#include <stdio.h>

/* function prototype */
struct time splitTime(long total_seconds);

struct time {
   int seconds, minutes, hours;
};

int main(void)  {
   long num;
   printf("Enter the total number of second elapsed today: ");
   scanf("%ld", &num);

   struct time theTime = splitTime (num);
   printf("The time is %02d:", theTime.hours);
   printf("%02d:", theTime.minutes);
   printf("%02d\n", theTime.seconds);

   return 0;
}

struct time splitTime(long totalSeconds)  {
    struct time t;
    t.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    t.minutes = totalSeconds / 60;
    t.seconds = totalSeconds % 60;
    return t;
}
