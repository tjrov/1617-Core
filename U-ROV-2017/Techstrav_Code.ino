#include <Servo.h>

Servo Arm1;
Servo Arm2;
Servo Arm3; 

bool lights = false;
const long LightsR1 = 27;
const long LightsR2 = 28;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Arm1.attach(2);
  Arm2.attach(3);
  Arm3.attach(4);

  Arm1.write(90);
  Arm2.write(90);
  Arm3.write(90);

  delay(2000);
  Serial.println();
  Serial.println("!RSET");
  Serial.println("!PPER 75,77");
  Serial.println("!SPAN 0,10.5");
  Serial.println("!TMAX600");
  Serial.println("!O Slider.Max=10");
  Serial.println("!O txtSW*= "); // Clear all switch text boxes
  Serial.println("!O txtSW3=Master"); //Rename Switch 0
  Serial.println("!O txtSW1=Lights"); //Rename Switch 1
  Serial.println("!O txtLED*= "); // Clear all LED text boxes
  Serial.println("!0 txtLED=Main");
  Serial.println("!0 txtLED=Arm");
  Serial.println("!O txtSlider=Control"); // Label slider
  Serial.println("!PLOT ON");
  Serial.println("@TEXT 35A, 105A, 1.5,(RED), Colonial Robotics");

}

void loop() {
  // put your main code here, to run repeatedly:
  ReadGUI();
  if (control == 0){
      Serial.println("Motor Control Disabled");
  }
  else if (control == 1){
      Serial.println("Tool control");
      Serial.println();
      ServoC1();
      ServoC2();
      ServoC3();
  }
  else{
      Serial.println("Error 404, Code not Found");
  }
}

void ReadGUI(){
  
}

void ServoC1(){
  
}
void ServoC2(){
  
}
void ServoC3(){
  
}

