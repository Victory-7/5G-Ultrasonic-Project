#include <ESP8266WiFi.h>

// Define pins
#define TRIG D6
#define ECHO D7
#define LED D5

void setup() {
    Serial.begin(115200); // Higher baud rate for ESP8266
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    // Send ultrasonic pulse
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // Measure echo pulse duration
    long duration = pulseIn(ECHO, HIGH);
    
    // Convert duration to distance (in cm)
    int distance = duration * 0.034 / 2;

    // Send data via Serial
    Serial.println(distance);

    // LED control: Turn ON if object is too close (<10 cm)
    if (distance < 10) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }

    delay(100);
}
