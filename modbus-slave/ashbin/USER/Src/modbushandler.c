#include "modbushandler.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "defines.h"
// input register initialize
USHORT usRegInputStart = REG_INPUT_START;
USHORT usRegInputBuf[REG_INPUT_NREGS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

/**
 * @name    : eMBRegInputCB
 * @brief   : input register process function,the input register is READOONLY
 * @param   : pucRegBuffer  return value pointer for read operation
 *            usAddress     register start address
 *            usNRegs       register length
 * @retval  : eStatus       register status
 **/
eMBErrorCode
eMBRegInputCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
    // status
    eMBErrorCode eStatus = MB_ENOERR;
    // operation register index
    int iRegIndex;
    if ((usAddress >= REG_INPUT_START) && (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS))
    {
        // calculate the offset
        iRegIndex = (int)(usAddress - usRegInputStart);
        while (usNRegs > 0)
        {
            // read high bits
            *pucRegBuffer++ =
                (unsigned char)(usRegInputBuf[iRegIndex] >> 8);
            // read low bits
            *pucRegBuffer++ =
                (unsigned char)(usRegInputBuf[iRegIndex] & 0xFF);
            iRegIndex++;
            usNRegs--;
        }
    }
    // address in wrong range
    else
    {
        // no such register
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/**
 * @name    : eMBRegHoldingCB
 * @brief   : holding register process function,the holding register is readable & writeable
 * @param   : pucRegBuffer  return value pointer for read operation and input value pointer for write operation
 *            usAddress     register start address
 *            usNRegs       register length
 *            eMode         read or write mode
 * @retval  : eStatus       register status
 **/
eMBErrorCode
eMBRegHoldingCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                eMBRegisterMode eMode)
{
    // no holding register needed
    return MB_ENOREG;
}

/**
 * @name    : eMBRegCoilsCB
 * @brief   : Coil register process function,the coil register is readable & writeable
 * @param   : pucRegBuffer  return value pointer for read operation and input value pointer for write operation
 *            usAddress     register start address
 *            usNRegs       register length
 *            eMode         read or write mode
 * @retval  : eStatus       register status
 **/
eMBErrorCode
eMBRegCoilsCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNCoils,
              eMBRegisterMode eMode)
{
    return MB_ENOREG;
}

/**
 * @name    : eMBRegDiscreteCB
 * @brief   : Coil register process function,the coil register is readable & writeable
 * @param   : pucRegBuffer  return value pointer for read operation and input value pointer for write operation
 *            usAddress     register start address
 *            usNRegs       register length
 *            eMode         read or write mode
 * @retval  : eStatus       register status
 **/
eMBErrorCode
eMBRegDiscreteCB(UCHAR *pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
    return MB_ENOREG;
}

