/*
Joshua
Dual-Servo Robot w/ OLED Command Display
Current Revision: December 3nd, 2021:
  - Moved wheels to a class (it looks nicer)
  - Split code up into a couple of header and .cpp files. Readability!
*/

#include <SPI.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "wheels.hpp"
#include "oled.hpp"
#include "proximity.hpp"

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); // Don't proceed, loop forever
    }

    // Formatted as (pinLeft, pinRight)
    // This class automatically initializes the Servos.
    Wheels wheels(10, 9);

    drawString("If you see this message, something is probably wrong.");

    /*/ Commands for the Robot /*/

    /* Commands are written as (moveTime, force) */
    /* A near-perfect 90-degree turn has a movetime of 1900 (oddly) */
      // ( Why can't it be 2000? :( )

    wheels.moveLeft(1900, 90);
    delay(2000);
    wheels.moveForwards(4000, 90);
    wheels.moveRight(1900, 90);
    delay(1000);
    wheels.moveForwards(4000, 90);
}

void loop() {
}
