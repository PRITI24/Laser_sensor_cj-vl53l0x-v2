#include<Wire.h>
#include<VL53L0X.h>

VL53L0X sensor1;

void setup() {
  // put your setup code here, to run once:
//  pinMode(12, INPUT_PULLUP);
//  digitalWrite(12, HIGH);
  Serial.begin(9600);
  Wire.begin();

  sensor1.init();
  sensor1.setTimeout(500);

  sensor1.startContinuous();

}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = sensor1.readRangeContinuousMillimeters();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");
  if(sensor1.timeoutOccurred())
  {
    Serial.print("TimeOut");
  }
  Serial.println();
  delay(100);
}
