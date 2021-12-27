// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include "pitches.h"
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int button1 = 8;
int button2 = 9;
int button3 = 10;
int button4 = 11;
int button5 = 12;
static int score = 0;
int keyValue = 0;

unsigned long endtime = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4 , OUTPUT);
  pinMode(led5 , OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  initial();
  bibibi();
  randomSeed(analogRead(0));
}
void initial() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  Serial.println("-----Welcome to Whack-a-mole Game!-----");
}
void bibibi() { //起始聲音
  tone(7, FS5, 100);
  delay(500);
  tone(7, FS4, 100);
  delay(500);
  tone(7, FS4, 100);
}

// the loop routine runs over and over again forever:
void loop() {
  //Serial.print(millis());//測試用
  //Serial.print("+");//測試用
  //Serial.println(endtime);//測試用
  
  int ran = random(2, 7);     //隨機選取五個LED之一發亮
  digitalWrite(ran, HIGH);

  unsigned long time = millis();
  while ( millis() - time < 3000) { // 三秒換一次LED發亮
    keyValue = digitalRead(ran + 6);
    if (keyValue) {
      break;
    }
    //Serial.println(keyValue);//測試用
    delay(10);
  }

  if (keyValue) {
    score++;
    delay(10);
    tone(7, C5, 150);//得分的聲音
    delay(200);
    tone(7, G5, 200);
  }
  else {
    score--;
  }

  
  digitalWrite(ran, LOW);
  Serial.print("Score: ");
  Serial.println(score);
 if(millis() - endtime >= 30000){//要玩幾秒
  endtime = millis()+7500;
  //Serial.print(millis());//測試用
    Serial.println("game over");//結束程式
    tone(7, C5, 100);//結束的聲音
    delay(200);
    tone(7, CS5, 100);
    delay(200);
    tone(7, D5, 200);
    delay(200);
    tone(7, DS5, 200);
    delay(200);
    delay(1000);
    Serial.print("Your score:");//顯示分數
    Serial.println(score);
    Serial.println("下一場遊戲於5秒後開始");
    delay(5000);
   
    score = 0;
    bibibi();
  }
  
 }
