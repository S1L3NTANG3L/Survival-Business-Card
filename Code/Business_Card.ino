/*
 Name:		Business_Card.ino
 Created:	9/30/2021 4:29:15 PM
 Author:	Rechard
*/

#include <Adafruit_VEML6070.h>
#include <Wire.h>

const int S0= 9, S1 = 10, S2 = 11, S3 = 12;
const int temp_voltage = A0;
double temp;
Adafruit_VEML6070 uv = Adafruit_VEML6070();

void setup() {
	Serial.begin(9600);
	uv.begin(VEML6070_HALF_T);
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
}


void loop() {
	switch (uv.readUV())
	{
	case 1:		
		digitalWrite(S0, LOW);
		digitalWrite(S1, LOW);
		digitalWrite(S2, LOW);
		digitalWrite(S3, LOW);
		break;
	case 2:
		digitalWrite(S0, HIGH);
		digitalWrite(S1, LOW);
		digitalWrite(S2, LOW);
		digitalWrite(S3, LOW);
		break;
	case 3:
		digitalWrite(S0, LOW);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, LOW);
		digitalWrite(S3, LOW);
		break;
	case 4:
		digitalWrite(S0, HIGH);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, LOW);
		digitalWrite(S3, LOW);
		break;
	case 5:
		digitalWrite(S0, LOW);
		digitalWrite(S1, LOW);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, LOW);
		break;
	case 6:
		digitalWrite(S0, HIGH);
		digitalWrite(S1, LOW);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, LOW);
		break;
	case 7:
		digitalWrite(S0, LOW);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, LOW);
		break;
	}
	if (uv.readUV() >= 8)
	{
		digitalWrite(S0, HIGH);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, LOW);
	}
	temp = 85.543 * (1.8663 - (analogRead(temp_voltage)));//Test
	if (temp <= -20)
	{
		digitalWrite(S0, LOW);
		digitalWrite(S1, LOW);
		digitalWrite(S2, LOW);
		digitalWrite(S3, HIGH);
	}
	if (temp > -20 && temp <= -15)
	{
		digitalWrite(S0, HIGH);
		digitalWrite(S1, LOW);
		digitalWrite(S2, LOW);
		digitalWrite(S3, HIGH);
	}
	if (temp < 0 && temp >= -10)
	{
		digitalWrite(S0, LOW);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, LOW);
		digitalWrite(S3, HIGH);
	}
	if (temp < 10 && temp >= 0)
	{
		digitalWrite(S0, HIGH);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, LOW);
		digitalWrite(S3, HIGH);
	}
	if (temp < 20 && temp >= 10)
	{
		digitalWrite(S0, LOW);
		digitalWrite(S1, LOW);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, HIGH);
	}
	if (temp < 30 && temp >= 20)
	{
		digitalWrite(S0, HIGH);
		digitalWrite(S1, LOW);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, HIGH);
	}
	if (temp < 40 && temp >= 30)
	{
		digitalWrite(S0, LOW);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, HIGH);
	}
	if (temp > 40)
	{
		digitalWrite(S0, HIGH);
		digitalWrite(S1, HIGH);
		digitalWrite(S2, HIGH);
		digitalWrite(S3, HIGH);
	}
}