/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

#include "port.h"
/* include stm32 ll file */
#include "stm32f4xx_ll_usart.h"
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
// modbus serial port is USART2
#include "defines.h"

#include "log.h"
/* ----------------------- static functions ---------------------------------*/
void prvvUARTTxReadyISR( void );
void prvvUARTRxISR( void );




/* ----------------------- Start implementation -----------------------------*/
void
vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
    /* 
     * If xRXEnable enable serial receive interrupts. If xTxENable enable
     * transmitter empty interrupts.
     */
    // enable serial receive interrupts or disable
    if(xRxEnable)
    {
        // enable the USART receive data reguster
        LL_USART_EnableIT_RXNE(MODBUS_USART);
    }
    else
    {
        // disable the USART receive data register
        LL_USART_DisableIT_RXNE(MODBUS_USART);
    }
    // enable serial transmit interrupts or disable
    if(xTxEnable)
    {
        // enable serial transmit data register
        LL_USART_EnableIT_TXE(MODBUS_USART);
    }
    else
    {
        // disable serial transmit data register
        LL_USART_DisableIT_TXE(MODBUS_USART);
    }
    
}

BOOL
xMBPortSerialInit( UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
    // serial will be initialized in the main function,pass
    return TRUE;
}

BOOL
xMBPortSerialPutByte( CHAR ucByte )
{
    /* 
     * Put a byte in the UARTs transmit buffer. This function is called
     * by the protocol stack if pxMBFrameCBTransmitterEmpty( ) has been
     * called. 
     * */
    // transmit a byte through LL
    LL_USART_TransmitData8(MODBUS_USART,(uint8_t)ucByte);
    LOGI("send char: %d",ucByte);
    return TRUE;
}

BOOL
xMBPortSerialGetByte( CHAR * pucByte )
{
    /* 
     * Return the byte in the UARTs receive buffer. This function is called
     * by the protocol stack after pxMBFrameCBByteReceived( ) has been called.
     */
    // receive bytes through LL
    *pucByte = LL_USART_ReceiveData8(MODBUS_USART);
    LOGI("get char: %d",*pucByte);
    return TRUE;
}

/* 
 * Create an interrupt handler for the transmit buffer empty interrupt
 * (or an equivalent) for your target processor. This function should then
 * call pxMBFrameCBTransmitterEmpty( ) which tells the protocol stack that
 * a new character can be sent. The protocol stack will then call 
 * xMBPortSerialPutByte( ) to send the character.
 */
void prvvUARTTxReadyISR( void )
{
    pxMBFrameCBTransmitterEmpty(  );
}

/* 
 * Create an interrupt handler for the receive interrupt for your target
 * processor. This function should then call pxMBFrameCBByteReceived( ). The
 * protocol stack will then call xMBPortSerialGetByte( ) to retrieve the
 * character.
 */
void prvvUARTRxISR( void )
{
    pxMBFrameCBByteReceived(  );
}
