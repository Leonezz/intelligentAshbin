#include "putter.h"
#include "main.h"
void turnPutter()
{
    const GPIO_PinState status = (getPutterStatus() == 0)
                                     ? GPIO_PIN_SET
                                     : GPIO_PIN_RESET;
    if (status)
    {
        setPutterOpen();
    }
    else
    {
        setPutterClose();
    }
}
void stopperScan()
{
    const GPIO_PinState putterStatus = HAL_GPIO_ReadPin(stopper_GPIO_Port, stopper_Pin);
    setPutterStatus(putterStatus);
}
void keyScan()
{
    GPIO_PinState keyStatus = HAL_GPIO_ReadPin(triggerPutterKey_OFFBOARD_GPIO_Port, triggerPutterKey_OFFBOARD_Pin);
    if (keyStatus == GPIO_PIN_SET)
    {
        HAL_Delay(100);
        if (keyStatus == HAL_GPIO_ReadPin(triggerPutterKey_OFFBOARD_GPIO_Port, triggerPutterKey_OFFBOARD_Pin))
        {
            turnPutter();
        }
    }
}

void setPutterOpen()
{
    if (indicatorStatus != 0x00)
        return;
    if (!usRegCoilsBuf[REG_PUTTER_ADDR])
    {
        HAL_GPIO_WritePin(putterControll_GPIO_Port, putterControll_Pin, 1);
    }
}

void setPutterClose()
{
    if (usRegCoilsBuf[REG_PUTTER_ADDR])
    {
        HAL_GPIO_WritePin(putterControll_GPIO_Port, putterControll_Pin, 0);
    }
}