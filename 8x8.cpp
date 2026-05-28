#include <Arduino.h>

int PINS[] = {A0, A1, A2, A3, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int MAP[] = {0, 5, 8, 3, 15, 9, 14, 11, 4, 13, 12, 1, 10, 2, 6, 7};

void setup(){
  for(int i = 0; i<16; i++){
    pinMode(PINS[i], OUTPUT);
  };
  for (int i = 0; i<8; i++){
    digitalWrite(PINS[MAP[i]], LOW);
  }
}

int arr[8] = {
  0b10011001,
  0b01000010,
  0b00100100,
  0b10011001,
  0b10011001,
  0b00100100,
  0b01000010,
  0b10011001
};

int D = 800;
void loop(){
  for (int i = 0; i<8; i++){
    digitalWrite(PINS[MAP[(i+7)%8]], LOW);
    for (int j = 0; j<8; j++){
      digitalWrite(PINS[MAP[j+8]], ((arr[i]&(1<<j))==0) ? HIGH : LOW);
    }
    digitalWrite(PINS[MAP[i%8]], HIGH);
    delayMicroseconds(D);
  }
}
