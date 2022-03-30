#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
#define servon  250
#define servoff 150 
#define SD_pin 4
TMRpcm tmrpcm;

const int yukari = 2;
const int asagi  = 3;
const int menu  = 6;
int durum_yukari; 
int durum_asagi ;
int durum_menu ;
int sayac = 0;

void setup()
{
  pinMode(yukari , INPUT);
  pinMode(asagi  , INPUT);
  pinMode(menu   , INPUT);
  Serial.begin(9600);
  srituhobby.begin();
  srituhobby.setPWMFreq(60);
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_pin)) 
  {        
    Serial.println("Hafıza kartı hatası"); 
    return; 
  }
}
void loop()
{
  durum_menu = digitalRead(menu); 
  while (durum_menu == LOW) 
  {
    durum_yukari = digitalRead(yukari);
    durum_asagi  = digitalRead(asagi);
    
    if (durum_yukari == HIGH and sayac < 29)
    {
      sayac++;
      Serial.println(sayac); 
      delay(200);
      ses(sayac);
    } 
    
    else if (sayac == 29)
    {
      sayac = 0;
    }

    else if (sayac == -1)
    {
      sayac = 28; 
    }

    else if ( durum_asagi == HIGH and sayac >= 0)
    {
      
      if (sayac == 0)
      {
        sayac--; 
      }
      else
      {
      sayac--; 
      delay(200);
      ses(sayac);
      }
    }
    
    durum_menu = digitalRead(menu);
  }
  
  delay(200);
  ses(sayac);
  
  switch(sayac)
  {
    case 1:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
     Serial.println("KOD Gidiyor");
      break;

    case 2:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
     Serial.println("KOD Gidiyor2");
      break;

    case 3:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 4:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 5:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 6:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 7:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 8:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 9:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 10:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 11:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 12:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 13:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 14:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 15:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 16:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 17:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 18:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 19:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 20:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 21:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 22:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 23:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 24:
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 25:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 26:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 27:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 28:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 29:
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break; 

    default: 
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
  }
  delay(200);
}


void ses(int sayi)
{
  switch (sayi) 
  {
    case 1:
    
    tmrpcm.setVolume(6);                    
    tmrpcm.play("a.wav");         
    break;

    case 2:
    tmrpcm.setVolume(6);
    tmrpcm.play("b.wav");
    break;

    case 3:
    tmrpcm.setVolume(6);
    tmrpcm.play("c.wav");
    break;

    case 4:
    tmrpcm.setVolume(7);
    tmrpcm.play("c2.wav");
    break;

    case 5:
    tmrpcm.setVolume(6);
    tmrpcm.play("d.wav");
    break;

    case 6:
    tmrpcm.setVolume(6);
    tmrpcm.play("e.wav");
    break;

    case 7:
    tmrpcm.setVolume(6);
    tmrpcm.play("f.wav");
    break;

    case 8:
    tmrpcm.setVolume(6);
    tmrpcm.play("g.wav");
    break;

    case 9:
    tmrpcm.setVolume(6);
    tmrpcm.play("g2.wav");
    break;

    case 10:
    tmrpcm.setVolume(6);
    tmrpcm.play("h.wav");
    break;

    case 11:
    tmrpcm.setVolume(6);
    tmrpcm.play("i2.wav");
    break;

    case 12:
    tmrpcm.setVolume(6);
    tmrpcm.play("i.wav");
    break;

    case 13:
    tmrpcm.setVolume(6);
    tmrpcm.play("j.wav");
    break;

    case 14:
    tmrpcm.setVolume(6);
    tmrpcm.play("k.wav");
    break;

    case 15:
    tmrpcm.setVolume(6);
    tmrpcm.play("l.wav");
    break;

    case 16:
    tmrpcm.setVolume(6);
    tmrpcm.play("m.wav");
    break;

    case 17:
    tmrpcm.setVolume(6);
    tmrpcm.play("n.wav");
    break;

    case 18:
    tmrpcm.setVolume(6);
    tmrpcm.play("o.wav");
    break;

    case 19:
    tmrpcm.setVolume(6);
    tmrpcm.play("o2.wav");
    break;

    case 20:
    tmrpcm.setVolume(6);
    tmrpcm.play("p.wav");
    break;

    case 21:
    tmrpcm.setVolume(6);
    tmrpcm.play("r.wav");
    break;

    case 22:
    tmrpcm.setVolume(6);
    tmrpcm.play("s.wav");
    break;

    case 23:
    tmrpcm.setVolume(6);
    tmrpcm.play("s2.wav");
    break;

    case 24:
    tmrpcm.setVolume(6);
    tmrpcm.play("t.wav");
    break;

    case 25:
    tmrpcm.setVolume(6);
    tmrpcm.play("u.wav");
    break;

    case 26:
    tmrpcm.setVolume(6);
    tmrpcm.play("u2.wav");
    break;

    case 27:
    tmrpcm.setVolume(6);
    tmrpcm.play("v.wav");
    break;

    case 28:
    tmrpcm.setVolume(6);
    tmrpcm.play("y.wav");
    break;

    case 29:
    tmrpcm.setVolume(6);
    tmrpcm.play("z.wav");
    break;
  }
}
