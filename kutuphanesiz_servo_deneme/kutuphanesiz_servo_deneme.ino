#define Derece 1500
#define Ry 0

// Deneme

void setup() {
  // put your setup code here, to run once:
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(12, OUTPUT);
 Serial.begin(9600);
  
  
  
  
  //servo(3, 750);

}

void loop() {
  // put your main code here, to run repeatedly:
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
