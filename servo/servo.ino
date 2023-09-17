#include <Servo.h>
#include <IRremote.hpp>

Servo myservo;
int RECV_PIN = 2;
int IRpower = 4;
int IRGND = 3;
long timer;

void setup()
{
  Serial.begin(9600);
  pinMode(IRpower,OUTPUT);
  pinMode(IRGND,OUTPUT);
  digitalWrite(IRpower,HIGH);
  digitalWrite(IRGND,LOW);

  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
 
  myservo.attach(9); 
  myservo.write(90); // 一開始先置中90度
  delay(3000);
}

void loop()
{
  if (IrReceiver.decode()) { // 接收紅外線訊號並解碼
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    // USE NEW 3.x FUNCTIONS
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        // We have an unknown protocol here, print more info
        IrReceiver.printIRResultRawFormatted(&Serial, true);
    }else{
      myservo.write(0); 
      delay(500);
      myservo.write(90);
      delay(1000);
    }
    IrReceiver.resume();
  }
}
