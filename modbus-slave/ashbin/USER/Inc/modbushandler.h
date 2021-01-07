#ifndef _MODBUSHANDLER_H
#define _MODBUSHANDLER_H
#include <stdint.h>

/* modbus includes */
#include "mb.h"
//#include "mbport.h"
// input register start address
#define REG_INPUT_START 0
// input register length
#define REG_INPUT_NREGS 5

#define REG_COILS_START 0
#define REG_COILS_NREGS 2
#define REG_PUTTER_ADDR 0

#define REG_TEMPREATURE_ADDR 0
#define REG_HUMITY_ADDR 1
#define REG_GAS_ADDR 2
#define REG_WEIGHT_ADDR 3
#define REG_WEIGHT_LENGTH 2

extern UCHAR usRegCoilsStart;
extern UCHAR usRegCoilsBuf[REG_COILS_NREGS];

extern USHORT usRegInputStart;
extern USHORT usRegInputBuf[REG_INPUT_NREGS];


#endif