#include "USB.h"
#include "USBHIDMouse.h"

USBHIDMouse Mouse;

const int radius = 100;               // Circle radius in pixels
const int steps = 120;                // More = smoother
const int delayMs = 20;               // Delay between moves

void setup() {
  USB.begin();
  Mouse.begin();
  delay(3000); // Allow host to enumerate device

  // Move in circle centered at current cursor position
  for (int i = 0; i < steps; i++) {
    float theta = 2 * PI * i / steps;
    float x = radius * cos(theta);
    float y = radius * sin(theta);

    // Compute relative movement from last step
    static float lastX = 0, lastY = 0;
    int dx = round(x - lastX);
    int dy = round(y - lastY);

    Mouse.move(dx, dy);
    lastX = x;
    lastY = y;
    delay(delayMs);
  }

  // Optionally release and stop
  Mouse.end();
}

void loop() { }
