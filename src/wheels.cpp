#include "wheels.hpp"
#include "oled.hpp"
#include <Arduino.h>

// Constructor, runs when the class is initialized.
Wheels::Wheels(int leftPin, int rightPin)  {
  _servoLeft.attach(leftPin);
  _servoRight.attach(rightPin);
}

void Wheels::moveLeft(int moveTime, int force) {
  // Since I moved this to a class (and therefore cannot specify the servo in the function call), this is the alternative.
  // Simple if statement to use _servoRight if the force is negative (or 0, but 0 does nothing).
  Servo* servoPtr{&_servoLeft};
  if(force < 0) servoPtr = &_servoRight;

  // Adding or subtracting a "force" value (-90 to 90) from the _servoNeutral value helps readability
  // It also makes it easier to control a left and right servo, as seen in the moveForwards() function.
  // Also, pointers use "->" to point to a child of the address, so that's what's going on here.
  servoPtr->write(_servoNeutral + force);

  // Uses an if statement to check if it's moving Right, since moveRight also calls this function.
  if(force > 0) {
      drawString("Current Action:\nMoving Right\n Left Force: " + static_cast<String>(_servoNeutral + force) );
  } else {
      drawString("Current Action:\nMoving Left\n Right Force: " + static_cast<String>(_servoNeutral + force) );
  }

  // Don't do anything for the time specified in the function call and then stop the servo
  delay(moveTime);
  drawString("Current Action:\nNone");

  servoPtr->write(_servoNeutral);
}

void Wheels::moveRight(int moveTime, int force) {
    // moveLeft already does what I want, so I just have to do a small modification (DRY), therefore not having to copy-paste my code.
    // This involves the 2 lines at the top of the moveLeft() function and giving moveLeft a negative Force.
    // We use a negative force because the right servo is mirrored.
    moveLeft(moveTime, -force);
}

void Wheels::moveForwards(int moveTime, int force) {

    // Since the 2 servos are mirrored, they also have to move in opposite directions.
    // This is where using the _servoNeutral approach is helpful.
    _servoLeft.write(_servoNeutral + force);
    _servoRight.write(_servoNeutral - force);

    drawString("Current Action:\nMoving Forwards\nLeft Force: " + static_cast<String>(_servoNeutral + force) + "\nRight Force: " + static_cast<String>(_servoNeutral - force)) ;

    delay(moveTime);
    drawString("Current Action:\nNone");

    _servoLeft.write(_servoNeutral);
    _servoRight.write(_servoNeutral);
}
