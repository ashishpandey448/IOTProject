#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "FDOeaN_ON3xv-JmkoW-k8EX7Eqsb4tq1";

char ssid[] = "l";
char pass[] = "12345678";

int buzzer = D2;
int LED1 = D3;
int LED2 = D4;
int smokeA0 = A0;
 
int sensorThres = 200;

void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);

pinMode(buzzer, OUTPUT);
pinMode(smokeA0, INPUT);
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);

}
void loop() {
digitalWrite(LED2, HIGH);
digitalWrite(LED1, LOW);

int analogSensor = analogRead(smokeA0);

Serial.print("Pin A0: ");
Serial.println(analogSensor);

if (analogSensor > sensorThres)
{
tone(buzzer, 1000, 200);

digitalWrite(LED2, LOW);
digitalWrite(LED1, HIGH);

Blynk.run();
Blynk.notify("Alert: Gas leaked");
}
else
{
noTone(buzzer);
}
delay(100);
}
