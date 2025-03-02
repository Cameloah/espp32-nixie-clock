#include "main.h"
#include "main_project_utils.h"
#include "ram_log.h"
#include "time_module.h"

// pins for shift register
#define PIN_SR_DIN  18
#define PIN_SR_CLK  19
#define PIN_SR_EN   21

// pins for leds
#define PIN_LED_VOLTMETER   13
#define PIN_LED_RGB         26





void nixie_display(int digit_1, int digit_2, int digit_3, int digit_4) {
  // display the digits on the nixie tubes
  int nixie_1[] = {10, 0, 1, 2, 3, 4, 5, 6, 7, 9};
  int nixie_2[] = {21, 11, 12, 13, 14, 15, 16, 17, 18, 20};
  int nixie_3[] = {34, 24, 25, 26, 27, 28, 29, 30, 31, 33};
  int nixie_4[] = {45, 35, 36, 37, 38, 39, 40, 41, 42, 44};
}

void setup() {
  DualSerial.begin(115200);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  // initialize the shift register
  pinMode(PIN_SR_DIN, OUTPUT);
  pinMode(PIN_SR_CLK, OUTPUT);
  pinMode(PIN_SR_EN, OUTPUT);

  digitalWrite(PIN_SR_EN, LOW);
  digitalWrite(PIN_SR_CLK, LOW);
  digitalWrite(PIN_SR_DIN, LOW);

  DualSerial.println("Starting Wifi...");
  project_utils_init("Nixie-Clock");

  ram_log_print_log();
}

void loop() {
  project_utils_update();

  // blink the led
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

  int hours = ntp.hours();
  int minutes = ntp.minutes();
  int seconds = ntp.seconds();
}