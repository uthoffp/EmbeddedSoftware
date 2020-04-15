/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stddef.h>
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define AHB1PERIPH_BASEADDR 0x40020000U
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00U)

typedef
struct {
    volatile uint32_t MODE_REG = 0x00U;          /* Address offset: 0x00 */
    volatile uint32_t TYPE_REG = 0x04U;          /* Address offset: 0x04 */
    volatile uint32_t SPEED_REG = 0x08U;         /* Address offset: 0x08 */
    volatile uint32_t PULL_REG = 0x0CU;          /* Address offset: 0x0C */
    volatile uint32_t INPUT_DATA_REG = 0x10U;    /* Address offset: 0x10 */
    volatile uint32_t OUTPUT_DATA_REG = 0x14U;   /* Address offset: 0x14 */
} GPIO_RegDef;

void delay(void) {
    for (volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    //activate clock for PortD
    *((volatile uint32_t*) (AHB1PERIPH_BASEADDR + 0x30U)) |= (1 << 3);

    //set PortD's I/O Direction (off.val. 0x00) to Output on Pin 12-15
    *((volatile uint32_t*) (GPIOD_BASEADDR)) |= ((1 << 30));
    *((volatile uint32_t*) (GPIOD_BASEADDR)) |= ((1 << 28));
    *((volatile uint32_t*) (GPIOD_BASEADDR)) |= ((1 << 26));
    *((volatile uint32_t*) (GPIOD_BASEADDR)) |= ((1 << 24));

    for(;;) {
        //toggle PORTD's 13th pin/ User LED
        *((volatile uint32_t*) (GPIOD_BASEADDR + GPIO_RegDef.OUTPUT_DATA_REG)) ^= (1 << 15);
        *((volatile uint32_t*) (GPIOD_BASEADDR + GPIO_RegDef.OUTPUT_DATA_REG)) ^= (1 << 14);
        *((volatile uint32_t*) (GPIOD_BASEADDR + GPIO_RegDef.OUTPUT_DATA_REG)) ^= (1 << 13);
        *((volatile uint32_t*) (GPIOD_BASEADDR + GPIO_RegDef.OUTPUT_DATA_REG)) ^= (1 << 12);
        delay();
    }
}
