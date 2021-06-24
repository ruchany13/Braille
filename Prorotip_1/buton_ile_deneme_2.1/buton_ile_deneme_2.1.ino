#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
#define a 300 
#define k 150 
TMRpcm tmrpcm;


int durum_yukari; 
int durum_asagi ;
int durum_menu ;
int sayac = 0 ;


void setup()
{
  pinMode(22 , INPUT);
  pinMode(23  , INPUT);
  pinMode(24   , INPUT);
  Serial.begin(9600); 
  srituhobby.begin();
  srituhobby.setPWMFreq(60);
  
  tmrpcm.speakerPin = 11;
  if (!SD.begin(53)) {        
    Serial.println("Hafıza kartı hatası"); 
    return; } 
}


void loop() {

  durum_menu = digitalRead(24); 
  while (durum_menu == LOW) 
  {
    durum_yukari = digitalRead(22);
    durum_asagi  = digitalRead(23);
    
    if (durum_yukari == HIGH and sayac < 29)
    {
      int alfabe [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29} ;
      String ses;
      ses = String(alfabe[sayac-1])+ ".wav";
      char *ses2;
      ses.toCharArray(ses2, 6);
      tmrpcm.setVolume(6);              
      tmrpcm.play(ses2);
      delay(300);
      sayac++; 
    }
    
    else if ( durum_asagi == HIGH and sayac > 0)
    {
      sayac--; 
    }
    
    
    
    
  durum_menu = digitalRead(24); 
  }


  delay(200);

  int servo [] = {a,k,k,k,k,k, a,a,k,k,k,k, a,k,k,a,k,k, a,k,k,k,k,a, a,k,k,a,a,k, a,k,k,k,a,k, a,a,k,a,k,k, a,a,k,a,a,k, a,a,k,k,k,a, 
  a,a,k,k,a,k, k,k,a,k,a,k, k,a,k,a,k,k, k,a,k,a,a,k, a,k,a,k,k,k, a,a,a,k,k,k, a,k,a,a,k,k, a,k,a,a,a,k, a,k,a,k,a,k, 
  k,a,k,a,k,a, a,a,a,a,k,k, a,a,a,k,a,k, k,a,a,a,k,k, a,k,k,a,k,a, k,a,a,a,a,k, a,k,a,k,k,a,  a,a,k,k,a,a, a,a,a,k,k,a, a,k,a,a,a,a, a,k,a,k,a,a};
  
  sayac = (sayac-1) * 6;
  srituhobby.setPWM(0, 0, servo[sayac]);
  srituhobby.setPWM(1, 0, servo[sayac+1]);
  srituhobby.setPWM(2, 0, servo[sayac+2]);
  srituhobby.setPWM(3, 0, servo[sayac+3]);
  srituhobby.setPWM(4, 0, servo[sayac+4]);
  srituhobby.setPWM(5, 0, servo[sayac+5]);
  sayac = (sayac+1)/6;
  Serial.print("After Servo: ");
  Serial.println(sayac);
  delay(200);
}
