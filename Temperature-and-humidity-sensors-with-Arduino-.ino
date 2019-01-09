
#include <dht11.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8   // ds18b20 with pin 8
#define DHT11_PIN 2    //  dht11 with 2

int lumierePin = A1; // LDR sensor with A1
int humiditypin = A0; // soil humidity sensor with A0

dht11 DHT11;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float Celsius = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
}

void loop() {

  // capteur lumiere LDR
  int lumiereValue = analogRead(lumierePin);
  Serial.print("Lumière = ");
  Serial.println(lumiereValue); 
  
  // capteur température du sol ds18b20
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Serial.print(" S.T = ");
  Serial.print(Celsius);
  Serial.println(" °C ");

 // capteur humidité et temperature air dht11 
 
  int chk = DHT11.read(DHT11_PIN);
  Serial.print(" A.T =");  //temperature 
  Serial.print(DHT11.temperature);
  Serial.print(" °C ,");
  Serial.print(" A.H =");   //humidité
  Serial.println(DHT11.humidity);

  
 // capteur d'humidité du sol 
 
 int sensorValue = analogRead(humiditypin);  
 // apply the calibration to the sensor reading
  sensorValue =map(sensorValue,0,1023,0,100);
  Serial.print(" S.H = ");
  Serial.println(sensorValue);

   delay(1000);
  }
