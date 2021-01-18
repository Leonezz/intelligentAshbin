#ifndef _MODBUSHANDLER_H
#define _MODBUSHANDLER_H
#include <stdint.h>

/* modbus includes */
#include "mb.h"
//#include "mbport.h"
// input register start address
#define REG_INPUT_START 0
// input register length
#define REG_INPUT_NREGS 21

#define REG_COILS_START 0
#define REG_COILS_NREGS 2
#define REG_PUTTER_ADDR 0

#define REG_TEMPREATURE_ADDR 0
#define REG_HUMITY_ADDR 1
#define REG_GAS_ADDR 2
#define REG_WEIGHT_ADDR 3
#define REG_WEIGHT_LENGTH 2

/** QRCode data stores at REG_SCANER_ADDR, length is 13,
/* the byte at REG_SCANER_VALID_ADDR determins the data is valid or not.
/* QRCode data if valid if usRegInputBuf[REG_SCANER_VALID_ADDR] == 1,
/* invalid if usRegInputBuf[REG_SCANER_VALID_ADDR] == 0
**/
#define REG_SCANER_VALID_ADDR 5
#define REG_SCANER_ADDR 6
#define REG_SCANER_LENGTH 14
typedef enum SCANER_DATA_VALID
{
    INVALID = 0,
    VALID = 1
} ScanerDataValidStatusTypeDef;

#define REG_ULTRASOUND_ADDR 19
#define REG_ULTRASOUND_LENGTH 1

#define REG_INFRARED_ADDR 20
#define REG_INFRARED_LENGTH 1

extern UCHAR usRegCoilsStart;
extern UCHAR usRegCoilsBuf[REG_COILS_NREGS];

extern USHORT usRegInputStart;
extern USHORT usRegInputBuf[REG_INPUT_NREGS];

inline UCHAR getPutterStatus()
{
    return usRegCoilsBuf[REG_PUTTER_ADDR];
}

inline void setPutterStatus(UCHAR putterStatus)
{
    usRegCoilsBuf[REG_PUTTER_ADDR] = putterStatus;
}

inline USHORT getTempreatureValue()
{
    return usRegInputBuf[REG_TEMPREATURE_ADDR];
}

inline void setTempreatureValue(USHORT value)
{
    usRegInputBuf[REG_TEMPREATURE_ADDR] = value;
}

inline USHORT getHumityValue()
{
    return usRegInputBuf[REG_HUMITY_ADDR];
}

inline void setHumityValue(USHORT value)
{
    usRegInputBuf[REG_HUMITY_ADDR] = value;
}

inline USHORT getGasConcentrationValue()
{
    return usRegInputBuf[REG_GAS_ADDR];
}

inline void setGasConcentrationValue(USHORT value)
{
    usRegInputBuf[REG_GAS_ADDR] = value;
}

inline uint32_t getWeightValue()
{
    return (usRegInputBuf[REG_WEIGHT_ADDR] << 16) +
           usRegInputBuf[REG_WEIGHT_ADDR + 1];
}

inline void setWeightValue(uint16_t high, uint16_t low)
{
    usRegInputBuf[REG_WEIGHT_ADDR] = high;
    usRegInputBuf[REG_WEIGHT_ADDR + 1] = low;
}

inline USHORT getUltraSoundValue()
{
    return usRegInputBuf[REG_ULTRASOUND_ADDR];
}

inline void setUltraSoundValue(uint16_t value)
{
    usRegInputBuf[REG_ULTRASOUND_ADDR] = value;
}

inline USHORT getInfraredValue()
{
    return usRegInputBuf[REG_INFRARED_ADDR];
}

inline void setInfraredValue(uint16_t value)
{
    usRegInputBuf[REG_INFRARED_ADDR] = value;
}

inline void setScanerData(uint16_t *bytes)
{
    for (uint8_t index = 0; index < REG_SCANER_LENGTH - 1; ++index)
    {
        usRegInputBuf[index + REG_SCANER_ADDR] = bytes[index];
    }
}

inline void setScanerDataValidStatus(ScanerDataValidStatusTypeDef valid)
{
    usRegInputBuf[REG_SCANER_VALID_ADDR] = valid;
}

#endif