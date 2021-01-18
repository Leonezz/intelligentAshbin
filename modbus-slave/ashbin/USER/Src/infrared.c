#include "infrared.h"
void updateFullStatus()
{
    uint8_t fullStatus = HAL_GPIO_ReadPin(full_GPIO_Port, full_Pin);
    setInfraredValue(!fullStatus);
}