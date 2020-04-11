#include <DigiMouse.h>

#define address 0
#define buttonOut 2
#define buttonIn 0
#define ledPin 1
#define leftState 0x00
#define rightState 0x01
#define idleState 0x02

#define clickInterval 1000
#define debounceDelay 50

byte mode = idleState;
unsigned long lastDebounce = 0;
unsigned long lastClick = 0;
int lastButtonState = HIGH;
int buttonState = HIGH;
bool idle = true;

void setup() {
  DigiMouse.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buttonOut, OUTPUT);
  digitalWrite(buttonOut, LOW);
  pinMode(buttonIn, INPUT_PULLUP); 
}

void loop() {
  DigiMouse.delay(5);
  // Check for a button press
  
  int reading = digitalRead(buttonIn);

  //If the button state has changed update the debounce timer
  if (reading != lastButtonState) {
    lastDebounce = millis();
  }

  if ((millis() - lastDebounce) > debounceDelay) {
    if (reading != buttonState){
      buttonState = reading;

      // Cycle to next mode
      switch(mode) {
        case idleState:
          mode = leftState;
          break;
        case leftState:
          mode = rightState;
          break;
        case rightState:
          mode = idleState;
          break;
      }
    }
  }

  lastButtonState = reading;
  
  if(mode == rightState) {
    digitalWrite(ledPin, HIGH);
    DigiMouse.setButtons(1<<1);
    idle = false;
  } else if (mode == leftState) {
    // only click every clickInterval
    if ((millis() - lastClick) >= clickInterval) {
      lastClick = millis();
      digitalWrite(ledPin, HIGH);
      DigiMouse.setButtons(1<<0);
      DigiMouse.delay(10);
      DigiMouse.setButtons(0);
      digitalWrite(ledPin, LOW);
      idle = true;
    }
  } else if (mode = idleState) {
    // Update LED (Sine wave)
    float something = millis()/5000.0;
    int value = 128.0 + 128 * sin( something * 2.0 * PI  );
    analogWrite(ledPin,value);
    
    if (!idle) {
      idle = true;
      DigiMouse.setButtons(0);
    }
  }
}
