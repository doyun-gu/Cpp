/* Write a program called speed.c that
1. declares three int variables speed, distance, and time
2. assign any values you like to distance and time
3. prints out the chosen values for distance and time, and calculates and print out the speed.
An example of the expected output is shown below:
distance = 22, time = 5, speed = 4 */

# include <stdio.h>
int main(void) {

	int speed, distance = 22, time = 5;

	printf("This code is calaculating the value of speed\n");
	printf("distance is %d m\n", distance);
	printf("time is %d s\n", time);

	speed = distance / time;

	printf("Speed is distance over time which is %d m/s\n", speed);

	return 0;
}
