void Servo0()
 {

  if(CPS.Analog(PSS_LY) < 120) {

    POS = map(CPS.Analog(PSS_LY), 129, 255, 0, 255);

  angle = angle + angleStep;  
  writeServos(0, angle);  
  }  
     
else if(CPS.Analog(PSS_LY) > 128) {
  
   angle = angle - angleStep;  
   writeServos(0, angle);  }

   delay(1);
 }

void Servo1()
 {

  if(CPS.Analog(PSS_LX) < 120) {

    POS = map(CPS.Analog(PSS_LX), 129, 255, 0, 255);

  angle1 = angle1 + angleStep;  
  writeServos(1, angle1);  
  }  
     
else if(CPS.Analog(PSS_LX) > 128) {
  
   angle1 = angle1 - angleStep;  
   writeServos(1, angle1);  }
 }

void Servo2()
 {

  if(CPS.Analog(PSS_RY) < 120) {

    POS = map(CPS.Analog(PSS_LY), 129, 255, 0, 255);

  angle2 = angle2 + angleStep;  
  writeServos(2, angle2);  
  }  
     
else if(CPS.Analog(PSS_RY) > 128) {
  
   angle2 = angle2 - angleStep;  
   writeServos(2, angle2);  }
 }

void Servo3()
 {

  if(CPS.Analog(PSS_RX) < 120) {

    POS = map(CPS.Analog(PSS_RX), 129, 255, 0, 255);

  angle3 = angle3 + angleStep;  
  writeServos(3, angle3);  
  }  
     
else if(CPS.Analog(PSS_RX) > 128) {
  
   angle3 = angle3 - angleStep;  
   writeServos(3, angle3);  }
 }

void Servo4()
 {
    
if(CPS.Button(PSB_PINK)) {   
  
  angle4 = angle4 + angleStep;  
  writeServos(4, angle4); }

else if(CPS.Button(PSB_BLUE)) { 
  
  angle4 = angle4 - angleStep;  
  writeServos(4, angle4); }
 }   



void Servo5()
 {
    
if(CPS.Button(PSB_L3)) {   
  
  angle5 = angle5 + angleStep;  
  writeServos(5, angle5); }

else if(CPS.Button(PSB_R3)) { 
  
  angle5 = angle5 - angleStep;  
  writeServos(5, angle5); }
 }  

 
//============ Void Setup ================//


void writeServos(int nServo, int posicao) {
#define SERVOMIN  205 
#define SERVOMAX  409 

  int pos = map ( posicao , 0 , 180 , SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo , 0, pos);
}

void beginServos() {

#define Frequencia 50 

  pwm.begin(); 
  pwm.setPWMFreq(Frequencia); 
}  
