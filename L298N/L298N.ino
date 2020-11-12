const int enA = 9;
const int in1 = 3;
const int in2 = 4;

const int enB = 10;
const int in3 = 6;
const int in4 = 7;

const int pwmMotorSpeed = 70;

// One set of motor will rotate if its enable pins 
// are different, one is high and the other is low.
// To reverse it, just invert the high and low.

// The enable pin of each set is shorted to 
// 5V, it will run at max speed. If you want
// to control the speed, remove the short 
// and connect the enable pin to a PWM pin.


void setup()
{
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, pwmMotorSpeed);
  analogWrite(enB, pwmMotorSpeed);
}

void loop()
{
  forward();
  delay(3000);
  backward();
  delay(3000);


}

void stopMotor()
{

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forward()
{
  // Tested using two motors of robot car.
  // Motor of left and right robot are inverted so direction of forward of other motor is inverted as well.
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward()
{
  // Tested using two motors of robot car.
  // Motor of left and right robot are inverted so direction of backward  of other motor is inverted as well.
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
