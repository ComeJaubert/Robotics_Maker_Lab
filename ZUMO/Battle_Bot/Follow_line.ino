#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>
#include <ZumoBuzzer.h>
#include <Pushbutton.h>


ZumoBuzzer buzzer;
ZumoReflectanceSensorArray reflectanceSensors;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

#define REVERSE_SPEED 300 // 0 est stoppé, 400 à pleine vitesse
#define TURN_SPEED 400
#define FORWARD_SPEED 400
#define REVERSE_DURATION 300 // ms
#define TURN_DURATION 400 // ms
#define LINE_THRESHOLD 3000 // microseconds
#define BASAL_SPEED 250

const long interval = 1500;
const long interval2 = 3000;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);

  // Initialize the reflectance sensors module
  reflectanceSensors.init();

  // Wait for the user button to be pressed and released
  button.waitForButton();

  // Turn on LED to indicate we are in calibration mode
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  int i;
  for(i = 0; i < 80; i++)
  {
    if (i <= 40)
      motors.setSpeeds(-150, 150);
    else
      motors.setSpeeds(110, -110);
      
    reflectanceSensors.calibrate(); // check whats in it !    
    Serial.println("CALIBRATING");
    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(150, 150);
  delay(1000);
  motors.setSpeeds(0,0);
  button.waitForButton();
  // Turn off LED to indicate we are through with calibration
  digitalWrite(13, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  unsigned int sensors[6];

  int position = reflectanceSensors.readLine(sensors);

  Serial.print("Position :");
  Serial.print(" ");
  Serial.print(position);
  Serial.print(" ");
 
  if (position > LINE_THRESHOLD){
    previousMillis = currentMillis;
    
    motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
    delay(REVERSE_DURATION);
    motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
    delay(TURN_DURATION);
    int k;
    for(k = 0; k < 50; k++){Serial.println("LOOP FOR -- K"); motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);}
    Serial.println("start");
    motors.setSpeeds(0, 0);
  }
  else if ((currentMillis - previousMillis > interval) and (currentMillis - previousMillis < interval2)){
    Serial.print(currentMillis);
    Serial.print(previousMillis);
    Serial.print(" ");
    Serial.println("interval-1");
    motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  }
   else if ((currentMillis - previousMillis > interval2) and (currentMillis - previousMillis < 3400)){ // TRY FOR 1 SECONDS
      Serial.print(currentMillis);
      Serial.print(" ");
      Serial.println("PUSH");
      motors.setSpeeds(-FORWARD_SPEED, -FORWARD_SPEED);
      delay(100);
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
      delay(200);
      motors.setSpeeds(-FORWARD_SPEED, -FORWARD_SPEED);
      delay(100);
      int j;
      for(j = 0; j < 50; j++){Serial.println("LOOP FOR -- J"); motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);}
  
      
    }
    else if ((currentMillis - previousMillis > 5000) and (currentMillis - previousMillis < 5600)){  
      Serial.println("GO--AWAY");    
      motors.setSpeeds(-FORWARD_SPEED, -FORWARD_SPEED);
      delay(200); 
      motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
      delay(400);
      }

  else {
  motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  Serial.println(currentMillis);
  Serial.println("Basal-speed");
  }
  }
