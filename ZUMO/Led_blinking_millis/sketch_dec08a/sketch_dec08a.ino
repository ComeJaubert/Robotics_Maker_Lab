const int ledPin_1 =  13;

int ledState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store

unsigned long previousMillis = 0;        // will store last time LED was updated
// constants won't change:
const long interval_1 = 10000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin_1, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval_1) {
  previousMillis = currentMillis;

    if (ledState == LOW){ledState = HIGH;}
    else {ledState = LOW;}   
    digitalWrite(ledPin_1, ledState);  
    }
}
