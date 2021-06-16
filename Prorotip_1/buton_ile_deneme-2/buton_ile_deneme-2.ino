#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
#define servon 300
#define servoff 150 // 150-600 = 0-180
#define SD_pin 53
TMRpcm tmrpcm;

const int yukari = 22;
const int asagi  = 23;
const int menu  = 24;
int durum_yukari; 
int durum_asagi ;
int durum_menu ;
int sayac = 0;

unsigned long sure, sure2;

void setup()
{
  pinMode(yukari , INPUT);
  pinMode(asagi  , INPUT);
  pinMode(menu   , INPUT);
  Serial.begin(9600); // seri haberleşme
  srituhobby.begin();
  srituhobby.setPWMFreq(60);
  tmrpcm.speakerPin = 11;
  if (!SD.begin(SD_pin)) {        //see if the card is present and can be initialized
    Serial.println("Hafıza kartı hatası");  //Hafıza kartı için uyarı sesi oluşturulabilir
    return; 
  }
}
void loop()
{
  durum_menu = digitalRead(menu); 
  while (durum_menu == LOW) //menü LOW ise(menü tuşu basılı değilken) while döngüsüne gir
  {
    durum_yukari = digitalRead(yukari);
    durum_asagi  = digitalRead(asagi);
    
    if (durum_yukari == HIGH and sayac < 29)
    {
      // 29 ve sonrası için else
      sayac++; // sayacı arttır
      Serial.print("sayac = " );
      Serial.println(sayac); // ekrana sayacın değerini yaz
      delay(200);
      deneme(sayac);
      
    }
    else if ( durum_asagi == HIGH and sayac > 0)
    {
      sayac--; // sayacı azalt
      Serial.print("sayac = " );
      Serial.println(sayac); // ekrana sayacın değerini yaz
      delay(200);
      deneme(sayac);
    }
    
  durum_menu = digitalRead(menu); // menü switcini tekrar oku (aksi halde while döngüsü sonsuz döngü olur)
  }
  delay(200);
  deneme(sayac);
  Serial.println("attach");
  switch (sayac) // sayaca göre switch kodunu çalıştır
  {

    case 1:
     
     Serial.println("1. A");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
     Serial.println("servoya kod gidiyor");
      
      break;

    case 2: 
    
      Serial.println("2. B");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
     Serial.println("Servoya kod gidiyor.");
      break;

    case 3:
      Serial.println("3. C");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 4:
      Serial.println("4. Ç");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 5:
      Serial.println("5. D");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 6: 
      Serial.println("6. E");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 7: 
      Serial.println("7. F");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 8:
      Serial.println("8. G");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 9:
      Serial.println("9. Ğ");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 10:
      Serial.println("10. H");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 11: 
      Serial.println("11. I");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 12: 
      Serial.println("12. İ");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 13:
      Serial.println("13. J");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 14:
      Serial.println("14. K");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 15:
      Serial.println("15. L");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 16: 
      Serial.println("16. M");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 17: 
      Serial.println("17. N");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 18:
      Serial.println("18. O");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 19:
      Serial.println("19. Ö");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 20:
      Serial.println("20. P");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 21: 
      Serial.println("21. R");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 22: 
      Serial.println("2. S");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 23:
      Serial.println("23. Ş");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 24:
      Serial.println("24. T");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servoff);
      break;

    case 25:
      Serial.println("25. U");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 26: 
      Serial.println("26. Ü");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 27: 
      Serial.println("27. V");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servon);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 28:
      Serial.println("28. Y");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servon);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break;

    case 29:
      Serial.println("29. Z");
     srituhobby.setPWM(0, 0, servon);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servon);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servon);
     srituhobby.setPWM(5, 0, servon);
      break; 

    default: // sayaca başka bir değer ise
      Serial.println("bilinmeyen karakter ");
     srituhobby.setPWM(0, 0, servoff);
     srituhobby.setPWM(1, 0, servoff);
     srituhobby.setPWM(2, 0, servoff);
     srituhobby.setPWM(3, 0, servoff);
     srituhobby.setPWM(4, 0, servoff);
     srituhobby.setPWM(5, 0, servoff);
  }
  delay(200);
}


void deneme(int sayi){
  switch (sayi) {
    case 1:
    Serial.println("A sesi");
    tmrpcm.setVolume(6);                    //0 to 7. Set volume level
    tmrpcm.play("a.wav");         //the sound file "a" will play each time the arduino powers up, or is reset
    break;

    case 2:
    Serial.println("B sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("b.wav");
    break;

    case 3:
    Serial.println("C sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("c.wav");
    break;

    case 4:
    Serial.println("Ç sesi");
    tmrpcm.setVolume(7);
    tmrpcm.play("c2.wav");
    break;

    case 5:
    Serial.println("D sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("d.wav");
    break;

    case 6:
    Serial.println("E sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("e.wav");
    break;

    case 7:
    Serial.println("F sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("f.wav");
    break;

    case 8:
    Serial.println("G sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("g.wav");
    break;

    case 9:
    Serial.println("Ğ sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("g2.wav");
    break;

    case 10:
    Serial.println("H sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("h.wav");
    break;

    case 11:
    Serial.println("I sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("i2.wav");
    break;

    case 12:
    Serial.println("İ sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("i.wav");
    break;

    case 13:
    Serial.println("J sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("j.wav");
    break;

    case 14:
    Serial.println("K sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("k.wav");
    break;

    case 15:
    Serial.println("L sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("l.wav");
    break;

    case 16:
    Serial.println("M sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("m.wav");
    break;

    case 17:
    Serial.println("N sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("n.wav");
    break;

    case 18:
    Serial.println("O sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("o.wav");
    break;

    case 19:
    Serial.println("Ö sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("o2.wav");
    break;

    case 20:
    Serial.println("P sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("p.wav");
    break;

    case 21:
    Serial.println("R sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("r.wav");
    break;

    case 22:
    Serial.println("S sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("s.wav");
    break;

    case 23:
    Serial.println("Ş sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("s2.wav");
    break;

    case 24:
    Serial.println("T sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("t.wav");
    break;

    case 25:
    Serial.println("U sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("u.wav");
    break;

    case 26:
    Serial.println("Ü sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("u2.wav");
    break;

    case 27:
    Serial.println("V sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("v.wav");
    break;

    case 28:
    Serial.println("Y sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("y.wav");
    break;

    case 29:
    Serial.println("Z sesi");
    tmrpcm.setVolume(6);
    tmrpcm.play("z.wav");
    break;
  }
}
