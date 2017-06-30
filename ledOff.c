#include <wiringPi.h>
#include <stdio.h>

#define Led 0 //wiringPi GPI0O, pin11

int main (void)
{
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed! \n");
		return -1;
	}

	pinMode(Led, OUTPUT);

	digitalWrite(Led, HIGH);
	printf("led off\n");

	return 0;
}
