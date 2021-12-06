#include "oled.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawString(String string) {
    display.clearDisplay();

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner
    display.cp437(true);         // Use full 256 char 'Code Page 437' font

    // Since display.write() only deals with characters, we have to loop through the string.
    for(int i = 0; i < static_cast<int>(string.length()); ++i) {
      display.write(string[i]);
    }

    // I figured that adding this would just be better since I don't have a need to delay the displaying.
    // This must be called to make the display update.
    display.display();
}
