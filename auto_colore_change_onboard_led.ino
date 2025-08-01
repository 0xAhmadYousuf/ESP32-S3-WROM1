#include <Adafruit_NeoPixel.h>

#define LED_PIN     48
#define LED_COUNT   1

Adafruit_NeoPixel led(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Delay between updates (smaller = smoother/faster)
#define FADE_DELAY  20

void setup() {
  led.begin();
  led.show(); // Turn off initially
}

void loop() {
  // Cycle through hues from 0 to 255 (rainbow)
  for (int hue = 0; hue < 256; hue++) {
    uint32_t color = led.ColorHSV(hue * 256); // ColorHSV uses 0–65535 range
    color = led.gamma32(color); // Optional: smooth brightness perception

    led.setPixelColor(0, color);
    led.show();
    delay(FADE_DELAY);
  }
}
