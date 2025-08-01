#include <Adafruit_NeoPixel.h>

// Pin where RGB LED is connected (adjust if needed)
#define LED_PIN    48
#define LED_COUNT  1

Adafruit_NeoPixel led(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  led.begin();
  led.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Red x3
  blinkColor(255, 0, 0, 3);
  
  // Blue x1
  blinkColor(0, 0, 255, 1);

  // Green x2
  blinkColor(0, 255, 0, 2);
}

void blinkColor(uint8_t r, uint8_t g, uint8_t b, int times) {
  for (int i = 0; i < times; i++) {
    led.setPixelColor(0, led.Color(r, g, b));
    led.show();
    delay(700);

    led.setPixelColor(0, 0); // Turn off
    led.show();
    delay(700);
  }
}
