#include <Servo.h>

Servo servo;

//Comunications
int SW1state = 0;
int SW2state = 0;
int LEDstate = 0;

//Main motor pins

const int motorPin1 = 2;

const int motorPin2 = 3;

const int motorPin3 = 4;

const int motorPin4 = 5;

const int motorPin5 = 6;

//Servo pins

const int servoPin1 = 7;

const int servoPin2 = 8;

const int servoPin3 = 9;

const int servoPin4 = 10;

const int servoPin5 = 11;

 const int servoPin6 = 12;

//Motor Servo data

byte MotorE1;

byte MotorE2;

byte MotorE3;

byte MotorE4;

byte MotorE5;

byte ServoL1 = 10;

byte ServoL2 = 690;

byte ServoL3 = 30;

byte ServoL4 = 70;

byte ServoL5 = 0;

//Data Collection Byte

int incomingByte = 0;

String incomingSByte;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  delay(2000);
  Serial.println();
  Serial.println("!RSET");
  Serial.println("!SPAN 0,1000");
  Serial.println("!TMAX180");
  Serial.println("!PLOT ON");
  Serial.println("@TEXT 35A, 105A, 1.5,(RED), Colonial Robotics");

}

void loop() {
        delay(50);
        Serial.println();
        Serial.write("Waiting");
        Serial.println();
       
        digitalWrite(13, HIGH);
        delay(250);    
        digitalWrite(13, LOW);
}



int Send(){

  bool sending = true;

  bool sent = false;

  while (sending == true){

      Serial.write(40);

      Serial.write("sending");

      Serial.write(41);

      incomingSByte = "";

      return(sent == true);

  }

}

int Recieve(){

  bool recieved = false;

  

  return(recieved = true);

}



void MotorC1(int directional){

  if(directional == 1){

    servo.attach(motorPin1);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else if(directional == 2){

    servo.attach(motorPin1);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

  }

}

void MotorC2(int directional){

  if(directional == 1){

    servo.attach(motorPin2);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else if(directional == 2){

    servo.attach(motorPin2);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

  }

}

void MotorC3(int directional){

  if(directional == 1){

    servo.attach(motorPin3);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else if(directional == 3){

    servo.attach(motorPin1);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

  }

}

void MotorC4(int directional){

  if(directional == 1){

    servo.attach(motorPin4);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1700; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else if(directional == 2){

    servo.attach(motorPin4);

    servo.writeMicroseconds(1500); // send "stop" signal to ESC.

    delay(1000);// delay to allow the ESC to recognize the stopped signal

  

    int signal = 1100; // Set signal value, which should be between 1100 and 1900



    servo.writeMicroseconds(signal); // Send signal to ESC.

  }

  else{

    Serial.println("Error 11");

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

void ServoC6(int directional){

    if(directional == 1){

      

    }

    else if(directional ==2){

      

    }

    else{

      Serial.println("Error 11");

    }

  

}
