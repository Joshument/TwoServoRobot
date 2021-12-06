#ifndef WHEELS_H
#define WHEELS_H

#include <Servo.h>

class Wheels {
private:
  // Offset for Movement Commands
  static constexpr int _servoNeutral{90};

  // Servos (initialized in Constructor)
  Servo _servoLeft;
  Servo _servoRight;
public:
  // Initializes Servos
  Wheels(int leftPin, int Rightpin);

  // Movement Commands
  void moveLeft(int moveTime, int force);
  void moveRight(int moveTime, int force);
  void moveForwards(int moveTIme, int force);
};

#endif
