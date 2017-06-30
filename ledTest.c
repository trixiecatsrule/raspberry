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
			printf("Testing pin.\n");
			digitalWrite(i, LOW); //on
			delay(500);
			digitalWrite(i, HIGH); //off
		}
	}

	return 0;
}
