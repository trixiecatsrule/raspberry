#include <wiringPi.h>
#include <stdio.h>

int main (void)
{
	int i;

	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed! \n");
		return -1;
	}

	for(i = 0; i < 40; i++) {
		if (getAlt(i) == OUTPUT) {
			digitalWrite(i, HIGH);
		}
	}

	return 0;
}
