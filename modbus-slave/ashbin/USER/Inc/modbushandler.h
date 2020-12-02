#ifndef _MODBUSHANDLER_H
#define _MODBUSHANDLER_H
#include <stdint.h>

/* modbus includes */
#include "mb.h"
//#include "mbport.h"
// input register start address
#define REG_INPUT_START 0
// input register length
#define REG_INPUT_NREGS 20

extern USHORT usRegInputStart;
extern USHORT usRegInputBuf[REG_INPUT_NREGS];


#endif