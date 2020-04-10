#include <EEPROM.h>
#include <DigiMouse.h>

#define address 0
#define ledPin 1
#define left 0x00
#define right 0xFF

byte mode;

void setup() {
  DigiMouse.begin(); //start or reenumerate USB - BREAKING CHANGE from old versions that didn't require this
  pinMode(ledPin, OUTPUT);
  byte lastMode = EEPROM.read(address);
  if (lastMode == right) {
    EEPROM.write(address, left);
    mode = left;
  } else if (lastMode == left) {
    EEPROM.write(address, right);
    mode = right;
  } else {
    EEPROM.write(address, left);
    mode = left;
  }
  
}

void loop() {
  //or you can use these functions to click
  if(mode == right) {
    digitalWrite(ledPin, HIGH);
    DigiMouse.setButtons(1<<1);
    DigiMouse.delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
    DigiMouse.setButtons(1<<0);
    DigiMouse.delay(10);
    DigiMouse.setButtons(0);
    DigiMouse.delay(990);
  }
 //for compatability with other libraries you can also use DigiMouse.move(X, Y, scroll, buttons)
}
