#include "indicator.h"
#define TEMPREATURE_THRESHOLD 8000
#define GASCONCENTRATION_THRESHOLD 2500
#define WEIGHT_THRESHOLD 5000
typedef enum FullStatus
{
    Full = 1,
    NOT_FULL
} FullStatusTypeDef;

/**  
* indicators BITs
* the lowest bit indicates Tempreature
* the upper bit indicates Weight
* the third bit indicates Full
* ! for example:
* ! 0000 0001 means tempreature too high
* ! 0000 0010 means overweight
* ! 0000 0100 means ash bin is full
* ! multiple bits are set to 1 means multiple status
*/ 
uint8_t indicatorStatus = 0x00;

void updateTempreatureIndicator()
{
    const uint16_t tempreatureValue =
        getTempreatureValue();
    GPIO_PinState indicator =
        (GPIO_PinState)(tempreatureValue > TEMPREATURE_THRESHOLD);
    HAL_GPIO_WritePin(tempreatureIndicator_GPIO_Port,
                      tempreatureIndicator_Pin,
                      indicator);
    if (indicator)
    {
        indicatorStatus |= 0x01;
    }
    else
    {
        indicatorStatus &= 0xFE;
    }
}

void updateWeightIndicator()
{
    const uint32_t weightValue =
        getWeightValue();
    GPIO_PinState indicator =
        (GPIO_PinState)(weightValue > WEIGHT_THRESHOLD);
    HAL_GPIO_WritePin(weightIndicator_GPIO_Port,
                      weightIndicator_Pin,
                      indicator);
    if (indicator)
    {
        indicatorStatus |= 0x02;
    }
    else
    {
        indicatorStatus &= 0xFD;
    }
}

void updateFullIndicator()
{
    const uint8_t full = getInfraredValue();
    HAL_GPIO_WritePin(fullIndicator_GPIO_Port,
                      fullIndicator_Pin,
                      full);
    if (full)
    {
        indicatorStatus |= 0x04;
    }
    else
    {
        indicatorStatus &= 0xFB;
    }
}