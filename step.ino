#include <Unistep2.h>

Unistep2 stepper1(4, 5, 6, 7, 4096, 1000);// IN1, IN2, IN3, IN4, 總step數, 每步的延遲(in micros)
void setup() {
  Serial.begin(9600);
}

void loop() {
  stepper1.run();  //步進機啟動
    stepper2.move(-4096 * 2);
}
