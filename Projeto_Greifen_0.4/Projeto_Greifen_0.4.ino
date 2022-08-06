 //================== Wesley Seven: Projeto Greifen ver:0.4  =======================//

#include <Adafruit_PWMServoDriver.h>
#include <PS2X_lib.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <NewPing.h>
#include "DFRobotDFPlayerMini.h"
#include <Adafruit_NeoPixel.h>

#define endereco 0x27
#define colunas 16
#define linhas 2
#define trigger 8 
#define echo 9 
#define distancia_max 100
#define volumeMP3 30
#define pinMatrizLED 7
#define SensorD 6
#define SensorE 5

SoftwareSerial BT (11,10);// RX, TX
SoftwareSerial MP3Serial(13, 12); //RX, TX
NewPing sonar (trigger, echo, distancia_max);
LiquidCrystal_I2C lcd (endereco, colunas, linhas);
PS2X CPS;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, pinMatrizLED, NEO_GBR + NEO_KHZ800);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
DFRobotDFPlayerMini playerMP3;

char texto;
float distancia;
int error = 0; 
byte type = 0;
byte vibrate = 0;
int mode = 0;   

void writeServos(int posicao, int tempo);
void beginServos();   

  int angle=90;
  int angle1=90;
  int angle2=90;
  int angle3=90;
  int angle4=90;
  int angle5=90;
  int angle6=90;

  int angleStep=2;

  int MT1 = 40;
  int MT2 = 42;
  int MT3 = 41;
  int MT4 = 43;
  int ENA = 44;
  int ENB = 45;
  int POS; 


void setup(){
  
  beginServos();
  MP3Serial.begin(9600);
  BT.begin(9600);
  delay(300);

  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);
 
  pinMode (MT1, OUTPUT);
  pinMode (MT2, OUTPUT);
  pinMode (MT3, OUTPUT);
  pinMode (MT4, OUTPUT);
  
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

 error = CPS.config_gamepad(24,23,25,22, true, true);

  strip.begin();
  strip.show();        
  strip.setBrightness(50);

  playerMP3.begin(MP3Serial);
  playerMP3.volume(volumeMP3);
  playerMP3.playFolder(2, 1);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(3, 0);
  lcd.print("iniciando");
  delay(1500);
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("Projeto");
  lcd.setCursor(1, 1);
  lcd.print("Greifen - 2021");
 
}  

void loop(){

      if(error == 1)
      return; 

      CPS.read_gamepad(false, vibrate); 


//============= controle sobre os motores ==============//

      Frente();   //L2

      Re();       //R2

      Direita();  //PSB PAD RIGHT

      Esquerda();  //PSB PAD LEFT


//============= Controle sobre o braço ==============//

      Servo0(); //PSS LY
      
      Servo1(); //PSS LX
      
      Servo2(); //PSS RY
      
      Servo3(); //PSS RX
      
      Servo4(); //PSB_PINK e PSB_BLUE
      
      Servo5(); //PSB L3

      delay(5);   

     
//==================== Bluetooth ===================//     

if (BT.available()) {
  
    texto = BT.read();
    lcd.print(texto);

      if(texto=='1'){
        lcd.clear();}

      if(texto=='2'){
        lcd.backlight();  
        lcd.clear();}

      if(texto=='3'){
        lcd.noBacklight();
        lcd.clear();}

      if(texto=='.'){
        lcd.setCursor(0, 1);}

      if(texto=='5'){
        playerMP3.playFolder(2, 2);
        RGB();   }

}

 //================== Ultrassonico =====================//

 else if(texto=='6'){
   ultrassonico();
 }

 //================ Seguidor de linha ===================//
 
  else if(texto=='7'){
    seguidor_de_linha();     
  }

 //====================== Impacto ======================// 

  else if(texto=='8'){
    impacto();
  }

}   
