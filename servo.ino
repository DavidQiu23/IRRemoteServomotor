#include <Servo.h>
#include <IRremote.h>

Servo myservo;
int RECV_PIN = 2;
int IRpower = 8;
long timer;
decode_results results;
IRrecv irrecv(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  pinMode(IRpower,OUTPUT);
  digitalWrite(IRpower,HIGH);
  //irrecv.blink13(true);
  irrecv.enableIRIn(); // Start the receiver
 
  myservo.attach(9,500,2400); 
  myservo.writeMicroseconds(500); // 一開始先置中0度
  delay(3000);
}

void loop()
{
  if (irrecv.decode(&results)) { // 接收紅外線訊號並解碼
    Serial.println(results.value, HEX);
    myservo.writeMicroseconds(1200); 
    delay(500);
    myservo.writeMicroseconds(500);
    irrecv.resume();
  }

}
