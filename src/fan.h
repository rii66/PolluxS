#ifndef FAN_H
#define FAN_H

#include <Arduino.h>
#include "PolluxGlobals.h"

class Fan {
public:
  void begin() {
    ledcAttach(polluxConfig.pinFan, polluxConfig.fanPwmFreq, polluxConfig.fanPwmRes);
    ledcWrite(polluxConfig.pinFan, 0);
    current_speed = 0;
  }

  void setSpeed(uint8_t speed) {
    speed = constrain(speed, 0, 255);

    if (speed > 0 && speed < polluxConfig.fanMinSpeed) {
      speed = polluxConfig.fanMinSpeed;
    }

    ledcWrite(polluxConfig.pinFan, speed);
    current_speed = speed;
  }

  void off() {
    ledcWrite(polluxConfig.pinFan, 0);
    current_speed = 0;
  }

  uint8_t getSpeed() const { return current_speed; }

  bool isRunning() const {
    return current_speed >= polluxConfig.fanMinSpeed;
  }

private:
  uint8_t current_speed = 0;
};

#endif
