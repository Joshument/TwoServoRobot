#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SERVO_NEUTRAL 90 // Defines the "Neutral" position of the servo. Added for readability

void drawString(String string);
extern Adafruit_SSD1306 display;

#endif
