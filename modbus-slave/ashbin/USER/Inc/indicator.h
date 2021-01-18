#ifndef INDICATOR_H
#define INDICATOR_H
#include "main.h"
#include "modbushandler.h"
inline void updateTempreatureIndicator();
inline void updateWeightIndicator();
inline void updateFullIndicator();

extern uint8_t indicatorStatus;

#endif