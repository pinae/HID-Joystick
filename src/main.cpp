#include <Arduino.h>
#include <HID-Project.h>

#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define JOYSTICK_SWITCH_PIN 5
#define JOYSTICK_X_PIN A0
#define JOYSTICK_Y_PIN A1

uint8_t b1o = 0;
uint8_t b2o = 0;
uint8_t jso = 0;

void setup() {
  Serial.begin(115200);
  Gamepad.begin();
}

void loop() {
  uint8_t b1 = digitalRead(BUTTON_1_PIN);
  uint8_t b2 = digitalRead(BUTTON_2_PIN);
  uint8_t js = !digitalRead(JOYSTICK_SWITCH_PIN);
  int16_t x = (analogRead(JOYSTICK_X_PIN) - 510) * 32;
  int16_t y = (analogRead(JOYSTICK_Y_PIN) - 510) * 32;
  Gamepad.xAxis(x);
  Gamepad.yAxis(y);
  if (b1 > b1o) Gamepad.press(8);
  else if (b1 < b1o) Gamepad.release(8);
  if (b2 > b2o) Gamepad.press(9);
  else if (b2 < b2o) Gamepad.release(9);
  if (js > jso) Gamepad.press(10);
  else if (js < jso) Gamepad.release(10);
  Gamepad.write();
  b1o = b1;
  b2o = b2;
  jso = js;
  delay(3);
}
