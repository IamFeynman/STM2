#ifndef __COUNT_SENSOR_H
#define __COUNT_SENSOR_H

void CountSensor_Init(void);
uint16_t CountSensor_Get(void);
void EXTI15_10_IRQHandler(void);//Interrupt

#endif
