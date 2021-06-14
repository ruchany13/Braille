#include <Servo.h>
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>


#define Derece 1500
#define Derece1 750
#define SD_pin 53
TMRpcm tmrpcm;



Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

unsigned long ISR1_Zaman = 3000;  //ms
unsigned long ISR2_Zaman = 9000;  //ms
unsigned long ISR3_Zaman = 16000;  //ms
unsigned long ISR4_Zaman = 21000;


unsigned long ISR1_evvelkiMILLIS = 0;
unsigned long ISR2_evvelkiMILLIS = 0;
unsigned long ISR3_evvelkiMILLIS = 0;
unsigned long ISR4_evvelkiMILLIS = 0; 

void setup() {
  // put your setup code here, to run once:
  
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(9);
  servo4.attach(8);
  servo5.attach(10);
  servo6.attach(12);
  
/*
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  */  

    
  Serial.begin(9600); // seri haberleşme
  tmrpcm.speakerPin = 11;
  if (!SD.begin(SD_pin))         //see if the card is present and can be initialized
    Serial.println("Hafıza kartı hatası");  //Hafıza kartı için uyarı sesi oluşturulabilir
    return;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long CurrentMillis = millis(); // Başatan itiabren geçen süre
  
  
  

    
    
   if(CurrentMillis - ISR1_evvelkiMILLIS == ISR1_Zaman)
   {
      
      Serial.println("A sesi");
      tmrpcm.setVolume(6);                    //0 to 7. Set volume level
      tmrpcm.play("a.wav");
      CurrentMillis = millis();
      Serial.println(CurrentMillis);
       //the sound file "a" will play each time the arduino powers up, or is reset
      
      
   }

   if(CurrentMillis - ISR2_evvelkiMILLIS == ISR2_Zaman)
   {
    Serial.println("Servo 45");
    
    servo1.write(45);
    servo2.write(45);
    servo3.write(45);
    servo4.write(45);
    servo5.write(45);
    servo6.write(45);
    

    /*
    servo(2,Derece);
    delay(20);
    servo(3, Derece);
    delay(20);
    servo(8, Derece);
    delay(20);
    servo(9, Derece);
    delay(20);
    servo(10, Derece);
    delay(20);
    servo(12, Derece);
  */
    CurrentMillis = millis();
    Serial.println(CurrentMillis);

    
    
   }

   if(CurrentMillis - ISR3_evvelkiMILLIS == ISR3_Zaman)
   {
    
    Serial.println("Servo 90");
    
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    servo5.write(90);
    servo6.write(90);
   
   /*
    servo(2,Derece1);
    delay(20);
    servo(3, Derece1);
    delay(20);
    servo(8, Derece1);
    delay(20);
    servo(9, Derece1);
    delay(20);
    servo(10, Derece1);
    delay(20);
    servo(12, Derece1);
  */
    
    
    CurrentMillis = millis();
    Serial.println(CurrentMillis);
    
   }

   if(CurrentMillis - ISR4_evvelkiMILLIS == ISR4_Zaman)
   {
      
      Serial.println("B sesi");
      tmrpcm.setVolume(6);                    //0 to 7. Set volume level
      tmrpcm.play("b.wav");
      CurrentMillis = millis();
      Serial.println(CurrentMillis);
       //the sound file "a" will play each time the arduino powers up, or is reset
      
      
   }
}




void servo(int motor, int derece){

  for(int i = 0 ;i <=3 ;i++)
  {
    digitalWrite(motor, HIGH);
    delayMicroseconds(derece);
    digitalWrite(motor, LOW);
    delay(20);
  }
  return;
}
