#define trigPin 9
#define echoPin 10
#define ledPin 7

void setup() {
    Serial.begin(9600); 
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    long duration;
    int distance;
    
    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Receive echo
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Convert to cm

    // Send distance to Python script
    Serial.println(distance);

    // Control LED based on distance
    if (distance < 10) {
        digitalWrite(ledPin, HIGH); // Turn LED on
    } else {
        digitalWrite(ledPin, LOW);  // Turn LED off
    }

    delay(100);
}
