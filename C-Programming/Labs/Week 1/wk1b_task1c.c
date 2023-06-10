/* 
c) power = (voltage)^2/resistance
*/

#include <stdio.h>
int main(void) {

	int power, voltage = 40, resistance = 200;

	power = voltage * voltage / resistance;

	printf("Power is %d\n", power);

	return 0;
}
