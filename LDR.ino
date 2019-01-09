int sensorPin = A0; // input pin for LDR
int sensorValue = 0; // 
void setup() {
Serial.begin(9600); //sets serial port for communication
}
void loop() {
sensorValue = analogRead(sensorPin); // read value from the sensor
Serial.println(sensorValue); //prints the values 
delay(100);

}
