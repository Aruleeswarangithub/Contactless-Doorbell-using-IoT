#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
// Ultrasonic sensor pins
const int trigPin = 6;
const int echoPin = 8;
const int buzzerPin = 11;
const int greenLedPin = 13;
// Temperature sensor pin
const int tempPin = A0;
// Threshold temperatures for LEDs
const float highTempThreshold = 100.0;
// defines variables
long duration;
int distance;
int safetyDistance;
// LCD setup
LiquidCrystal lcd(12, 7, 5, 4, 3, 2); // LCD pins
// GSM setup
SoftwareSerial mySerial(9, 10); // Define the pins for SoftwareSerial
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(greenLedPin, OUTPUT);
pinMode(tempPin, INPUT);
lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
Serial.begin(9600);
mySerial.begin(9600); // Setting the baud rate of GSM Module
delay(1000); // Add a slight delay for stability
}
void loop() {
// Ultrasonic sensor
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
safetyDistance = 20; // Set a threshold distance of 20 cm
// Temperature sensor (LM35)
int sensorValue = analogRead(tempPin);
float voltage = sensorValue * (5.0 / 1023.0);
float tempC = voltage * 100.0;
// Control LEDs and buzzer based on distance and temperature
if (distance <= safetyDistance && tempC < highTempThreshold) {
digitalWrite(buzzerPin, HIGH);
digitalWrite(greenLedPin, HIGH); // Turn on the green LED
} else {
digitalWrite(buzzerPin, LOW);
digitalWrite(greenLedPin, LOW); // Turn off the green LED
}
// Display distance and temperature on LCD
lcd.clear();
lcd.print("Distance: ");
lcd.print(distance);
lcd.print(" cm"); // Display the unit
lcd.setCursor(0, 1);
if (tempC < highTempThreshold) {
lcd.print("Temp: Low, welcome!");
} else {
lcd.print("Temp: High");
}
// Send SMS with temperature and distance information
if (distance > 0 && tempC > 0) { // Check if valid readings
mySerial.println("AT+CMGF=1"); // Set SMS mode to text
delay(1000);
mySerial.println("AT+CMGS=\"REPLACE NUMBER\""); // Replace with your mobile number
delay(1000);
mySerial.print("Temperature: ");
mySerial.print(tempC);
mySerial.print(" C, Distance: ");
mySerial.print(distance);
mySerial.println(" cm");
delay(100);
mySerial.write(0x1A); // Send Ctrl+Z to indicate end of message
delay(1000);
Serial.println("Message sent.");
} else {
Serial.println("Invalid readings. Message not sent.");
}
// Print distance and temperature to Serial monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.print(" cm, Temperature: ");
Serial.print(tempC);
Serial.println("°C");
delay(1000); // Delay for stability
}