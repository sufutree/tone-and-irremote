#include <IRremote.h>
int IR_RECEIVE_PIN = 9;
#define OPEN = 0xEAB7BACD
void setup() {
  Serial.begin(9600);
  Serial.println("正在啟動紅外線");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println(("啟動完成"));
  pinMode(3, OUTPUT);
}
void loop()
{
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);

    if (IrReceiver.decodedIRData.address == 0x46) {
      if (IrReceiver.decodedIRData.command == 0x1) {
        IrReceiver.stop();
        tone(3, 262, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x2) {
        IrReceiver.stop();
        tone(3, 294, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x3) {
        IrReceiver.stop();
        tone(3, 330, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x4) {
        IrReceiver.stop();
        tone(3, 349, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x5) {
        IrReceiver.stop();
        tone(3, 392, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x6) {
        IrReceiver.stop();
        tone(3, 440, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x7) {
        IrReceiver.stop();
        tone(3, 494, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
      else if (IrReceiver.decodedIRData.command == 0x8) {
        IrReceiver.stop();
        tone(3, 523, 1000);
        delay(1000);
        IrReceiver.start(8000);
      }
    }
    IrReceiver.resume();
  }
  delay(100);
}
