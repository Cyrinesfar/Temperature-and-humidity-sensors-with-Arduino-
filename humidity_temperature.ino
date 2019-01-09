#include <dht11.h>

dht11 DHT11;

#define DHT11_PIN 2
void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT11.read(DHT11_PIN);
  Serial.print("T=");
  Serial.print(DHT11.temperature);
  Serial.print(" H=");
  Serial.println(DHT11.humidity);
  delay(1000);
}                               
