#include <SoftwareSerial.h>
#include <TinyGPS++.h>

int buttonpin = 6;
int distance1, distance2;
long duration1, duration2;
const int trigPin1 = A1;
const int echoPin1 = A0;
const int trigPin2 = A2;
const int echoPin2 = A3;
#define buzzer_pin 5

float latitude=27.689208;
float longitude=85.290054;

int RXPin = 2; //Connect to TX GPS
int TXPin = 3; //Connect to RX GPS

int GPSBaud = 9600; 

TinyGPSPlus gps;


SoftwareSerial gpsSerial(RXPin, TXPin);
SoftwareSerial gsmSerial(10, 11);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(A6, INPUT);
  gpsSerial.begin(GPSBaud);
  gsmSerial.begin(9600);
  delay(1000);
  Serial.println("Initializing...");
  delay(500);
  Serial.println("System Ready");
  delay(500);
}

void loop() {
  // Read GPS data
  while (gpsSerial.available() > 0){
    if (gps.encode(gpsSerial.read())){
      displayInfo();
      }
    break;
  }
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Distance1: ");
  Serial.println(distance1);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distance2);

  if (distance1 <= 40 || distance2 <= 40) {
    Serial.println("Close to obstacle");
    alert();
  } else {
    digitalWrite(buzzer_pin, LOW);
  }
  
  int sensorValue = analogRead(A6);
  if (sensorValue > 500) {
    alert();
    Serial.println("Water Alert");
  } else {
    digitalWrite(buzzer_pin, LOW);
  }

  if (gsmSerial.available() > 0) {
    Serial.write(gsmSerial.read());
  }

  while (gsmSerial.available()){
    gsmSerial.read();
    break;
  }
  while (Serial.available()){
    Serial.read();
  }

  if (digitalRead(buttonpin) == LOW) {
    Serial.println("Button pressed");
    delay(2000);
    SendMessage();
  }
  delay(500);  
}

void displayInfo() {
  Serial.print("Location: ");
  if (gps.location.isValid()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    Serial.print(latitude, 6);
    Serial.print(",");
    Serial.print(longitude, 6);
  } else {
    Serial.print("INVALID");
  }
  Serial.println();
}

void SendMessage() {
  gsmSerial.println("AT+CMGF=1");
  delay(900);
  gsmSerial.println("AT+CMGS=\"+9779808711811\"");
  delay(900);
  gsmSerial.println("I Am In Problem please be here ASAP location is :");
  delay(900);
  Serial.print("Your Position is : ");
  Serial.print("LATITUDE=");
  Serial.print(latitude, 6);
  gsmSerial.print("LATITUDE=");
  gsmSerial.print(latitude, 6);
  gsmSerial.print(",");
  Serial.print("LONGITUDE=");
  Serial.print(longitude, 6);
  gsmSerial.print("LONGITUDE=");
  gsmSerial.print(longitude, 6);
  delay(100);
  gsmSerial.println((char)26);
}

void alert() {
  digitalWrite(buzzer_pin, HIGH);
  delay(1000);
  digitalWrite(buzzer_pin, LOW);
  delay(500);
  
}
