#include "modbushandler.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "defines.h"
#include "putter.h"
// input register initialize
USHORT usRegInputStart = REG_INPUT_START;
USHORT usRegInputBuf[REG_INPUT_NREGS] = {0};

UCHAR usRegCoilsStart = REG_COILS_START;
UCHAR usRegCoilsBuf[REG_COILS_NREGS] = {0};

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
        // if the qrcode is read, set it invalid
        if(usAddress == REG_SCANER_VALID_ADDR)
        {
            setScanerDataValidStatus(INVALID);
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
    eMBErrorCode eStatus = MB_ENOERR;

    int coilsIndex;
    if ((usAddress >= REG_COILS_START) && ((usAddress + usNCoils) <= (REG_COILS_START + REG_COILS_NREGS)))
    {
        coilsIndex = (int)(usAddress - usRegCoilsStart);
        while (usNCoils > 0)
        {
            if (eMode == MB_REG_READ)
            {
                *pucRegBuffer++ = usRegCoilsBuf[coilsIndex];
            }
            else
            {
                turnPutter();
            }

            coilsIndex++;
            usNCoils--;
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
