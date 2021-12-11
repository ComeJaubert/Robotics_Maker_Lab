#include <ZumoMotors.h>

/*
 * This example uses the ZumoMotors library to drive each motor on the Zumo
 * forward, then backward. The yellow user LED is on when a motor should be
 * running forward and off when a motor should be running backward. If a
 * motor on your Zumo has been flipped, you can correct its direction by
 * uncommenting the call to flipLeftMotor() or flipRightMotor() in the setup()
 * function.
 */

#define LED_PIN 13

ZumoMotors motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop()
{
    Serial.println("go forward");
}
  delay(1000);
 
// MAKE IT TURN MAN -----------------

 for (int speed = 0; speed <= 200; speed++)
  {
    motors.setSpeeds(speed,-speed); 
    delay(2);
    Serial.println("turn");
  }
  

//--------------------------------------------------
}
