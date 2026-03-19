#include <Arduino.h>

int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int arr[10][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 0, 0}
};

void setup() {
  for (int i = 0; i < 8; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void set(int n){
  for (int i = 0; i < 8; i++){
    digitalWrite(pins[i], arr[n][i]);
  }
}

void loop() {
  for (int i = 0; i < 10; i++){
    set(i);
    delay(200);
  }  
}
