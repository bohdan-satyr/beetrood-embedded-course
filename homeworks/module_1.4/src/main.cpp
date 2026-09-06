#include <Arduino.h>

#define PIN_BLUE_LED_OUT 15
#define PIN_RED_LED_OUT 16
#define BUTTON_PIN 21
#define BUTTON_IN_BUILT 0


enum SystemMode{
    MODE_1,
    MODE_2
};

SystemMode currentMode = MODE_1;
int delayTime = 200;

void checkButtons(){
    int currentButtonState = digitalRead(BUTTON_PIN);
    int currentButtonStateInBuilt = digitalRead(BUTTON_IN_BUILT);

    if (currentButtonStateInBuilt == LOW) {
        currentMode = MODE_2;
    } else if (currentButtonState == LOW){
        currentMode = MODE_1;
    }
}

void switchMode(SystemMode mode){
    if(mode == MODE_1){
        digitalWrite(PIN_RED_LED_OUT, HIGH);
        digitalWrite(PIN_BLUE_LED_OUT, HIGH);
        delay(delayTime);
        digitalWrite(PIN_RED_LED_OUT, LOW);
        digitalWrite(PIN_BLUE_LED_OUT, LOW);
        delay(delayTime);
    } else {
        digitalWrite(PIN_RED_LED_OUT, HIGH);
        digitalWrite(PIN_BLUE_LED_OUT, LOW);
        delay(delayTime * 5);
        digitalWrite(PIN_RED_LED_OUT, LOW);
        digitalWrite(PIN_BLUE_LED_OUT, HIGH);
        delay(delayTime * 5);
    }
}

void setup() {
    pinMode(PIN_BLUE_LED_OUT, OUTPUT);
    pinMode(PIN_RED_LED_OUT, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUTTON_IN_BUILT, INPUT);
}

void loop() {
    checkButtons();
    switchMode(currentMode);
}   