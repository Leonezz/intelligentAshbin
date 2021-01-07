#include "putter.h"
#include "main.h"
void turnPutter()
{
    usRegCoilsBuf[REG_PUTTER_ADDR] = !(usRegCoilsBuf[REG_PUTTER_ADDR]);
    uint8_t putterStatus = usRegCoilsBuf[REG_PUTTER_ADDR];
    HAL_GPIO_WritePin(putterControll_GPIO_Port, putterControll_Pin, putterStatus);
}

void keyScan()
{
    GPIO_PinState keyStatus = HAL_GPIO_ReadPin(triggerPutterKey_GPIO_Port, triggerPutterKey_Pin);
    if (keyStatus == GPIO_PIN_SET)
    {
        HAL_Delay(100);
        if (keyStatus == HAL_GPIO_ReadPin(triggerPutterKey_GPIO_Port, triggerPutterKey_Pin))
        {
            turnPutter();
        }
    }
}