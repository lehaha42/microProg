#include <Arduino.h>
int R = 11;
int Y = 10;
int G = 9;
int B = 7;
int D = 1000;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, INPUT);
}

void loop() {
  digitalWrite(Y, LOW);
  digitalWrite(R, HIGH);
  int i = 5000;
  while (!digitalRead(B) && i > 0){
    delay(1);
    i--;
  }
  digitalWrite(R, LOW);
  delay(D);
  digitalWrite(R, HIGH);
  delay(D);
  digitalWrite(R, LOW);
  delay(D);
  digitalWrite(R, HIGH);
  delay(D);
  digitalWrite(R, LOW);
  digitalWrite(Y, HIGH);
  delay(D);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
  delay(D*5);
  digitalWrite(G, LOW);
  digitalWrite(Y, HIGH);
  delay(D);
}
