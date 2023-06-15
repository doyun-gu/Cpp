
/* 
Write a program that declares a union called 'info' to store the following, un-initialized, data:
	char colour - 8 bits: 'B' for blue, 'G' for green, R for red, 'W' for white.
	short pressure -16 bits
	int counter -32 bits
	long time -64 bits; time in seconds
	float temperature -32 bits
	double acceleration -64 bits
*/

/* Lab 9b Task2 Solution */

#include <stdio.h>
#include <stdlib.h>   /* needed for rand() and srand() functions */
#include <time.h>  /* needed for time() function in getData() */

  union sensorInfo {
    char colour;
    short pressure;
    int counter;
    long time;
    float temperature;
    double acceleration;
  };
 
union sensorInfo getData(char c);

  int main(void)  {
    char ch;

  do {
     printf ("Menu:\n'a' (colour)\n'b' (pressure)\n'c' (counter)\n'd' (time)\n'e' (temperature)\n'f' (acceleration)\n'x' (exit)\n");
     printf ("\nEnter your choice: ");
     scanf("%c", &ch);
     switch (ch) {
       case 'a': printf("value = %c\n", (getData(ch)).colour); break;
       case 'b': printf("value = %d\n", (getData(ch)).pressure); break;
       case 'c': printf("value = %d\n", (getData(ch)).counter); break;
       case 'd': printf("value = %ld\n", (getData(ch)).time); break;
       case 'e': printf("value = %f\n", (getData(ch)).temperature); break;
       case 'f': printf("value = %f\n", (getData(ch)).acceleration); break;
       default: break;
     }
  } while (ch != 'x');


  return 0;
}

union sensorInfo getData(char c) {
    srand((unsigned) time(NULL));    /* "seed" the pseudo-random number generator */
    union sensorInfo sensorData;
    switch (c) {
      case 'a': sensorData.colour = rand(); break;
      case 'b': sensorData.pressure = rand(); break;
      case 'c': sensorData.counter = rand(); break;
      case 'd': sensorData.time = rand(); break;
      case 'e': sensorData.temperature = rand(); break;
      case 'f': sensorData.acceleration = rand(); break;
      default: break;
    }
    return sensorData;
}
