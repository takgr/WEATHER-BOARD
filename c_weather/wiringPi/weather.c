#include <stdio.h>
#include "bme280-i2c.h"

static int pressure;
static int temperature;
static int humidity;


int main(int argc, char **argv)
{
	int status = 0;
	int WBVersion = 2;
	char *device = "/dev/i2c-1";

	if (argc == 2) {
		device = argv[1];
	} else if (argc > 2) {
		printf("Usage :\n");
		printf("sudo ./weather_board [i2c node](default \"/dev/i2c-1\")\n");
		return -1;
	}

	bme280_begin(device);

		bme280_read_pressure_temperature_humidity(
				&pressure, &temperature, &humidity);
		printf("======== bme280 ========\n");
		printf("temperature C: %.2lf \n", (double)temperature/100.0);
		printf("humidity %%: %.2lf \n",	(double)humidity/1024.0);
		printf("pressure (hPa): %.2lf \n", (double)pressure/100.0);
	return 0;
}
