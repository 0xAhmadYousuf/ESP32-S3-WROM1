#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

// Press a keycode with optional modifier
void pressKeyRaw(uint8_t keycode, bool shift = false) {
  if (shift) {
    Keyboard.pressRaw(0xE1); // Left Shift
    delay(5);
  }
  Keyboard.pressRaw(keycode);
  delay(5);
  Keyboard.releaseAll();
  delay(5);
}

// Type a full string (with basic support for uppercase, space, Enter, period, slash)
void typeText(const char* text) {
  for (const char* p = text; *p; p++) {
    char c = *p;
    if (c >= 'a' && c <= 'z') {
      pressKeyRaw(c - 'a' + 0x04, false);
    } else if (c >= 'A' && c <= 'Z') {
      pressKeyRaw(c - 'A' + 0x04, true);
    } else if (c == ' ') {
      pressKeyRaw(0x2C, false);
    } else if (c == '\n') {
      pressKeyRaw(0x28, false); // Enter
    } else if (c == '.') {
      pressKeyRaw(0x37, false);
    } else if (c == '/') {
      pressKeyRaw(0x38, false);
    }
    // Extend with more symbols if needed
  }
}

void setup() {
  USB.begin();
  Keyboard.begin();
  delay(3000); // Wait for host to detect HID

  // Open Run dialog: Win + R
  Keyboard.pressRaw(0xE3); // Left GUI (Win)
  Keyboard.pressRaw(0x15); // 'r'
  delay(100);
  Keyboard.releaseAll();
  delay(700);

  // Type "WT"
  pressKeyRaw(0x1A, true); // Shift + 'w' → 'W'
  pressKeyRaw(0x17, true); // Shift + 't' → 'T'
  delay(200);

  // Press Enter
  pressKeyRaw(0x28, false); // Enter
  delay(1500);

  // Type command and newline
  typeText("echo HelloWorld\n");
}

void loop() { }
