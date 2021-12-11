 
// Motor A
int enA = A4;
int in1 = 13;
int in2 = 12;
 
// Motor B
 
int enB = A5;
int in3 = 11;
int in4 = 10;

int c = 0 ;

void setup()
 
{
 
  // Set all the motor control pins to outputs
 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}

void demoOne()
{ 
  // This function will run the motors in both directions at a fixed speed
  // Turn on motor A
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enA, 150);
 
  // Turn on motor B
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enB, 150);
 
  delay(4200);

  // stop the 2 motors

  //digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);  
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);

   // Now turn off motor1
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  //digitalWrite(in3, LOW);
  // digitalWrite(in4, LOW);
  
  delay(1400);
  
  // make it stop longer 
//  delay(140000);

  // Now change motor directions
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, HIGH); 
  
 c += 1 ;
 
 if(c == 4){
  // Now turn off motor1
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 //delay(400);
 exit(0);
 }
 
}
 
void loop(){
  demoOne();
}
