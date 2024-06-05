#include <TM1637Display.h>
#define CLK_PIN 2
#define DIO_PIN 3

TM1637Display clock(CLK_PIN, DIO_PIN);
const uint8_t on[] = { 0xff, 0xff, 0xff, 0xff };
const uint8_t off[] = { 0x00, 0x00, 0x00, 0x00 };
// MAKE A TIMER FOR 7 MINUTES , LEADING ZEROS HAVE TO BE THERE AT ALL TIMES
// the brightness decreases as we reach 0.
void setup() {
  clock.setBrightness(7);
  clock.setSegments(on);
}

    int timer = 5;  // time in seconds
void loop() {
  if (timer > 0) {
    uint8_t min = timer / 60;
    uint8_t sec = timer % 60;
    uint8_t display[4];
    display[3] = clock.encodeDigit(sec % 10);
    display[2] = clock.encodeDigit(sec / 10);
    display[1] = clock.encodeDigit(min % 10);
    display[0] = clock.encodeDigit(min / 10);
    clock.setSegments(display);
    delay(1000);
    timer -= 1;
  } else {
    clock.setSegments(on);
    clock.setBrightness(1);
  }
}
