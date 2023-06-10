/* You may have noticed in Tasks 3 & 4 that, depending on the values you chose, the result is not quite right. 
For example in Task 4, if distance=22 and time=5, speed is calculated to be 4 not 4.4 as expected. 
That's because integer variables can only store numbers, not ones with fractional parts.
Modify your solution to Task 4 by defining distance, time and speed as float variables and check the output. */

# include <stdio.h>

int main(void) {

	float distance = 22, time = 5, speed;

	printf("This code is calcator for the speed in float");
	printf("distance = %f m\n", distance);
	printf("time = %f s\n", time);
	
	speed = distance / time;

	printf("Speed is Distance over time which is %f m\n", speed);

	return 0;
}
