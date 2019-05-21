
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor1;

VL53L0X sensor2;

int distance1;
int distance2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Wire.begin();

  //Sensor 1
  pinMode(9, INPUT_PULLUP);
  sensor1.init();
  sensor1.setTimeout(500);

  //Sensor 2
  sensor2.init();
  sensor2.setTimeout(500);

  //Start both the sensors to give data continuously
  sensor1.startContinuous();
  sensor2.startContinuous();

  sensor1.setTimeout(500);
  sensor2.setTimeout(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = sensor12();
  distance2 = sensor21();
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.print("mm");
  if (distance1 > 100 && distance2 > 100)
  {
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
  }
  Serial.println();
  Serial.print("pin 12");
  Serial.print(digitalRead(12));
}
int sensor12()
{
  long dist1 = (sensor1.readRangeContinuousMillimeters());
  return dist1;
}
int sensor21()
{
  long  dist2 = (sensor2.readRangeContinuousMillimeters());
  return dist2;
}
