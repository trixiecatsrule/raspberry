#include <wiringPi.h>
#include <stdio.h>

#define Led 0 //pin 11
#define Button 29 //pin 40

void toggle(void) {
	int i;

	for (i = 1; i < 8; i=i+2) {
		digitalWrite(i - 1, 0); //turn on previous
		delay(25);
		digitalWrite(i, 0); //turn on current
		delay (50);
		digitalWrite(i - 1, 1); //turn off previous
		delay (25);
		digitalWrite(i, 1); //turn off current
		delay(50);
	}

	for (i = 8; i >= 0; i=i-2) {
		digitalWrite(i, 0); //turn on current
		delay(25);
		digitalWrite(i-1, 0); //turn on next
		delay(50);
		digitalWrite(i, 1); //turn off current
		delay(25);
		digitalWrite(i-1, 1); //turn off next
		delay(50);
	}
}

int main (void)
{
	int i;

	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed! \n");
		return -1;
	}

	for(i = 0; i < 8; i++) {
		pinMode(i, OUTPUT);
	}

	pinMode(Button, INPUT);

	pullUpDnControl(Button, PUD_UP);

	wiringPiISR(Button, INT_EDGE_FALLING, &toggle);

	while(1){}

	return 0;
}
