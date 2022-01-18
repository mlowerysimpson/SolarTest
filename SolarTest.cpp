//SolarTest.cpp
//this program polls the status of the solar panel

#include <stdio.h>
#include <wiringPi.h>
#include "../RemoteControlTest/DiagnosticsSensor.h"


#define NUM_SOLAR_SAMPLES 50 
#define SAMPLE_DELAY 500 //length of time (in ms) to pause between samples


int main(int argc, char** argv)
{
    DiagnosticsSensor diagSensor(nullptr);
	// GPIO Initialization
	if (wiringPiSetupGpio() == -1)
	{
		printf("[x_x] GPIO Initialization FAILED.\n");
		return -2;
	}
	for (int i = 0; i < NUM_SOLAR_SAMPLES; i++) {
		delay(SAMPLE_DELAY);
		if (diagSensor.IsSolarCharging()) {
			printf("Solar ON\n");
		}
		else {
			printf("Solar OFF\n");
		}
	}
	return 0;
}