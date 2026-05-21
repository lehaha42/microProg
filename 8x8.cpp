#include <Arduino.h>

int PINS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};

void setup(){
  for(int i = 0; i<16; i++){
    pinMode(PINS[i], OUTPUT);
  };
  for (int i = 0; i<8; i++){
    digitalWrite(PINS[i], LOW);
  }
}

int arr[8] = {
  0b10000001,
  0b01000010,
  0b00100100,
  0b00011000,
  0b00011000,
  0b00100100,
  0b01000010,
  0b10000001
};

int D = 10;
void loop(){
  for (int i = 0; i<8; i++){
    delay(D);
    digitalWrite(PINS[(i-1)%8], HIGH);
    for (int j = 0; j<8; j++){
      digitalWrite(PINS[j+8], ((arr[i]&(1<<j))!=0) ? HIGH : LOW);
    }
    digitalWrite(PINS[i%8], LOW);
  }
}
