#include <Arduino.h>

static const int PWM_BITS = 11;
static const int PWM_FREQ = 19500;

static const int ledPins[] = {2, 1, 3, 7};
static const int ledPinsLen = sizeof(ledPins)/sizeof(ledPins[0]);

static const int PIN_NTC = 0;
static const int PIN_VCC = 4;

void setup() {
    Serial.begin(115200);
    for (int i = 0; i < ledPinsLen; i++) {
        pinMode(ledPins[i], OUTPUT);
        analogWrite(ledPins[i], 0);
        analogWriteResolution(ledPins[i], PWM_BITS);
        analogWriteFrequency(ledPins[i], PWM_FREQ);
    }


    // turn on at minimum brightness (empirically determined, min. brightness when they stop flickering on test board)
    analogWrite(ledPins[0], 25);
    analogWrite(ledPins[1], 11);
    analogWrite(ledPins[2], 25);
    analogWrite(ledPins[3], 20);

    // delay(1000);
}

static const int FADE_MAX = (1 << PWM_BITS) - 1;
static const int FADE_TIME = 5000000; // us
// // fade steps for 10ms each
// static const int FADE_MAX = 31;
// static const int FADE_TIME = 10000 * FADE_MAX; // us

void loop() {

    // // fade up/down channels after each other
    // for (int i = 3; i < ledPinsLen; i++) {
    //     for (int j = 0; j <= FADE_MAX; j++) {
    //         analogWrite(ledPins[i], j);
    //         delayMicroseconds(FADE_TIME/FADE_MAX);
    //         Serial.printf("%d: %4d\n", i, j);
    //     }
    //     // analogWrite(ledPins[i], 0);
    //     for (int j = FADE_MAX; j >= 0; j--) {
    //         analogWrite(ledPins[i], j);
    //         delayMicroseconds(FADE_TIME/FADE_MAX);
    //         Serial.printf("%d: %4d\n", i, j);
    //     }
    //     // delay(100);
    // }



    // // fade all channels together
    // for (int j = 0; j <= FADE_MAX; j++) {
    //     for (int i = 0; i < ledPinsLen; i++) {
    //         analogWrite(ledPins[i], j);
    //         Serial.printf("%d: %4d\n", i, j);
    //     }
    //     delayMicroseconds(FADE_TIME/FADE_MAX);
    // }
}
