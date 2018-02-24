#include <Servo.h>

Servo servo;

//Comunications
bool function = true;

//Main motor pins

const int motorPin1 = 7;

const int motorPin2 = 8;

const int motorPin3 = 9;

const int motorPin4 = 10;

const int motorPin5 = 11;

const int motorPin6 = 12;

//Servo pins

const int servoPin1 = 2;

const int servoPin2 = 3;

const int servoPin3 = 4;

const int servoPin4 = 5;

const int ServoPin5 = 6;

//9 degrees of freedom orientation sensor
const int fSDA = 20;
const int fSCL = 21;

//Temperature Humidity Sensor 
const int THS = 22;

//Beepy Thingy (Active Low)
const int ByTy = 23;

//RGB Pins (Active Low)
const int RLed = 24;
const int GLed = 25;
const int BLed = 26;

//LED relays (Active High)
const int LedRelay1 = 27;
const int LedRelay2 = 28;

//Electromagnet relays (Active High)
const int EMagRelay1 = 29;
const int EMagRelay2 = 30;

float maxamp = 10.00;

//Motor Servo data

int MotorE1 = 150;

int MotorE2 = 150;

int MotorE3 = 150;

int MotorE4 = 150;

int MotorE5 = 150;

int MotorE6 = 150;

byte ServoL1 = 12;

byte ServoL2 = 45;

byte ServoL3 = 76;

byte ServoL4 = 24;

byte ServoL5 = 120;

int Vertical;

int X;
int Y;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 2; i <=12; i++){
    pinMode(i, OUTPUT);
  }
  for(int i = 20; i <= 30; i++){
    pinMode(i, INPUT);
  }
  
  digitalWrite(ByTy, HIGH);

  delay(2000);
  Serial.println();
  Serial.println("!RSET");
  Serial.println("!PPER 75,77");
  Serial.println("!SPAN 0,180");
  Serial.println("!TMAX600");
  Serial.println("!O Slider.Max=180");
  Serial.println("!O txtSW*= "); // Clear all switch text boxes
  Serial.println("!O txtLED*= "); // Clear all LED text boxes
  Serial.println("!0 txtLED=Main");
  Serial.println("!0 txtLED=Arm");
  Serial.println("!O txtSlider=Control"); // Label slider
  Serial.println("!PLOT ON");
  Serial.println("@TEXT 35A, 105A, 1.5,(RED), Colonial Robotics");

}

void loop() {
        Serial.println();
        Serial.write("Waiting");
        Serial.println();
        Serial.print(ServoL1);
        Serial.print(",");
        Serial.print(ServoL2);
        Serial.print(",");
        Serial.print(ServoL3);
        Serial.print(",");
        Serial.print(ServoL4);
        Serial.print(",");
        Serial.print(ServoL5);
        Serial.print(",");
        Serial.print(maxamp * 10);
        Serial.print(",");
        Serial.print(MotorE1);
        Serial.print(",");
        Serial.print(MotorE2);
        Serial.print(",");
        Serial.print(MotorE3);
        Serial.print(",");
        Serial.print(MotorE4);
        Serial.print(",");
        Serial.print(MotorE5);
        Serial.print(",");
        Serial.println(MotorE6);
        read_GUI();
    /*Serial.write("System Shutdown Initiated");
    digitalWrite(ByTy, LOW);
    delay(1000);
    exit(1);*/
}
int read_GUI()
{
    long x,y;
    long x2;
    flushBuffer();
    Serial.println("!READ (gamepad.curX)"); // read 0 to 65535 for joystick X position, 32767 center
    x = Serial.parseInt();
    flushBuffer();
    Serial.println("!READ (gamepad.curY)");
    y = Serial.parseInt();
    flushBuffer();
    Serial.println("!READ (gamepad.curX2)"); // read 0 to 65535 for joystick X position, 32767 center
    x2 = Serial.parseInt();
    Vertical = x2;
    flushBuffer(); // Ensure buffer empty
    Serial.println("!READ (Slider)"); // Request the slider's value
    ServoL1 = Serial.parseInt(); // Accept returned data

    if(x != 32767){
      if (x > 32767){
        MotorC3(1);
        MotorC4(1);
        X = x;
        return(x);
      }
      else {
        MotorC3(2);
        MotorC4(2);
        return(x);
        X = x;
      }
    }
    if(y != 32767){
      if (y > 32767){
        MotorC3(1);
        MotorC4(1);
        return(y);
        Y = y;
      }
      else {
        MotorC3(2);
        MotorC4(2);
        return(y);
        Y = y;
      }
    }
    if(Vertical <= (32767 - 6000) or Vertical >= (32767 + 6000)){
        if (Vertical <= 32767 - 6000){
            MotorC5(1);
            MotorC6(1);
            return(Vertical);
        }
        else {
            MotorC5(2);
            MotorC6(2);
            return(Vertical);
        }
    }
    else{
      return(0);
    }
}
void flushBuffer()
{
    Serial.flush(); // flush serial buffer (may not always flush?)
    while (Serial.available()) // manually empty as well, read as long as bytes are in there
    Serial.read();
}
void MotorC1(int directional){

  if(directional == 1){

    servo.attach(motorPin1);

    servo.writeMicroseconds(MotorE1 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE1 = map(X, 0, 32767, 1230, 1500);

    float usage = map(MotorE1, 1230, 1500, 4.82, 0.03);

    maxamp = maxamp - usage;
    
    int signal = MotorE1; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE1 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else if(directional == 2){

    servo.attach(motorPin1);

    servo.writeMicroseconds(MotorE1 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE1 = map(X, 32767, 65535, 1500, 1760);

    float usage = map(MotorE1, 1500, 1760, 0.03, 4.75);
    
    maxamp = maxamp - usage;

    int signal = MotorE1; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC. 

    MotorE1 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else{

     Serial.write("Error 11");
     Serial.println();

  }

}

void MotorC2(int directional){

  if(directional == 1){

    servo.attach(motorPin2);

    servo.writeMicroseconds(MotorE2 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE2 = map(X, 0, 32767, 1230, 1500);

    float usage = map(MotorE1, 1230, 1500, 4.82, 0.03);

    maxamp = maxamp - usage;
    
    int signal = MotorE2; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE2 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else if(directional == 2){

    servo.attach(motorPin2);

    servo.writeMicroseconds(MotorE2 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE2 = map(X, 32767, 65535, 1500, 1760);

    float usage = map(MotorE2, 1500, 1760, 0.03, 4.75);
    
    maxamp = maxamp - usage;

    int signal = MotorE2; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE2 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else{

    Serial.write("Error 11");
    Serial.println();

  }

}

void MotorC3(int directional){

  if(directional == 1){

    servo.attach(motorPin3);

    servo.writeMicroseconds(MotorE3 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE3 = map(Y, 0, 32767, 1230, 1500);

    float usage = map(MotorE3, 1230, 1500, 4.82, 0.03);

    maxamp = maxamp - usage;
    
    int signal = MotorE3; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE3 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else if(directional == 2){

    servo.attach(motorPin3);

    servo.writeMicroseconds(MotorE3 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE3 = map(Y, 32767, 65535, 1500, 1760);

    float usage = map(MotorE3, 1500, 1760, 0.03, 4.75);
    
    maxamp = maxamp - usage;

    int signal = MotorE3; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE3 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else{

    Serial.write("Error 11");
    Serial.println();

  }

}

void MotorC4(int directional){

  if(directional == 1){

    servo.attach(motorPin4);

    servo.writeMicroseconds(MotorE4 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE4 = map(Y, 0, 32767, 1230, 1500);

    float usage = map(MotorE4, 1230, 1500, 4.82, 0.03);

    maxamp = maxamp - usage;
    
    int signal = MotorE4; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE2 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else if(directional == 2){

    servo.attach(motorPin4);

    servo.writeMicroseconds(MotorE4 * 10); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

    MotorE4 = map(Y, 32767, 65535, 1500, 1760);

    float usage = map(MotorE4, 1500, 1760, 0.03, 4.75);
    
    maxamp = maxamp - usage;

    int signal = 1300; // Set signal value, which should be between 1100 and 1900

    servo.writeMicroseconds(signal); // Send signal to ESC.

    MotorE4 = 150;

    if (signal == 1500){
      maxamp = 10.00;
    }

  }

  else{

    Serial.write("Error 11");
    Serial.println();

  }

}

void MotorC5(int directional){

  if(directional == 1){

    servo.attach(motorPin5);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }
  

  else if(directional == 2){

    servo.attach(motorPin5);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

  }

}

void MotorC6(int directional){

  if(directional == 1){

    servo.attach(motorPin5);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else if(directional == 2){

    servo.attach(motorPin5);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

  }

}

void ServoC1(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}

void ServoC2(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}

void ServoC3(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}

void ServoC4(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}

void ServoC5(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}
