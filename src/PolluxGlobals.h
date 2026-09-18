#ifndef POLLUX_GLOBALS_H
#define POLLUX_GLOBALS_H

#include <Arduino.h>

struct PolluxConfig {
  uint8_t  pinFan;
  uint8_t  pinHotgun;
  uint8_t  pinZero;
  uint8_t  pinTemp;

  uint16_t tempAmbient;
  uint16_t tempTip[3];
  uint16_t tempMin;
  uint16_t tempMax;

  uint8_t  heaterMaxPower;
  uint16_t powerPeriod;

  uint32_t fanPwmFreq;
  uint8_t  fanPwmRes;
  uint8_t  fanMinSpeed;
};

struct PolluxState {
  uint16_t currentTemp;
  uint16_t targetTemp;
  uint8_t  pwmOut;
  bool     overHeat;
};

extern PolluxConfig polluxConfig;
extern PolluxState polluxState;

#endif
