const int sensorPin = A0;
const int delayMins = 1;
const int maxLoop = 5;
int loopAmount = 0;
float tempTmp = 0;
void setup() {
  Serial.begin(9600);
  delay(5000);

}

void loop() {
  for( ; loopAmount < maxLoop; loopAmount ++) {
    tempTmp += getTempFromSensor()/5.0;
  }
  writeToPython();
  reset();
  delay(30000);
}

void reset(){
  tempTmp = 0.0;
  loopAmount = 0;
}

void writeToPython(){
  Serial.print("tempTmp,");
  Serial.println(tempTmp);
}

float getTempFromSensor(){
  int sensorVal = analogRead(sensorPin);
  delay(10);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  return temperature;
}
