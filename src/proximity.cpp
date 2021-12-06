#include <Arduino.h>

constexpr int trigPin{11};
constexpr int echoPin{12};

int calculateDistance() {
  // Clear the condition of trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sends a pulse to trigPin to calculate distance
  // Acording to Google the pulse should be 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // pulseIn will give us the sound wave travel time in microSeconds
  // Speed of sound wave divided by 2 (since it has to travel to and back) will calculate the distance in cm
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}
