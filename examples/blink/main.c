/**
 * @file main.c
 * @author TsMax (QinYUN575@Foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-03
 * 
 * @copyright Copyright (c) 2021 - 2023  shenzhen tisilicon co., ltd.
 * 
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef PUINT8V
typedef volatile unsigned char  *PUINT8V;
#endif
#ifndef PUINT16V
typedef volatile unsigned short *PUINT16V;
#endif
#ifndef PUINT32V
typedef volatile unsigned long  *PUINT32V;
#endif

typedef unsigned int       uint32_t;
/* GPIO PA register */
#define R32_PA_DIR          (*((PUINT32V)0x400010A0)) // RW, GPIO PA I/O direction: 0=in, 1=out
#define R8_PA_DIR_0         (*((PUINT8V)0x400010A0))  // RW, GPIO PA I/O direction byte 0
#define R8_PA_DIR_1         (*((PUINT8V)0x400010A1))  // RW, GPIO PA I/O direction byte 1
#define R32_PA_PIN          (*((PUINT32V)0x400010A4)) // RO, GPIO PA input
#define R8_PA_PIN_0         (*((PUINT8V)0x400010A4))  // RO, GPIO PA input byte 0
#define R8_PA_PIN_1         (*((PUINT8V)0x400010A5))  // RO, GPIO PA input byte 1
#define R32_PA_OUT          (*((PUINT32V)0x400010A8)) // RW, GPIO PA output
#define R8_PA_OUT_0         (*((PUINT8V)0x400010A8))  // RW, GPIO PA output byte 0
#define R8_PA_OUT_1         (*((PUINT8V)0x400010A9))  // RW, GPIO PA output byte 1
#define R32_PA_CLR          (*((PUINT32V)0x400010AC)) // WZ, GPIO PA clear output: 0=keep, 1=clear
#define R8_PA_CLR_0         (*((PUINT8V)0x400010AC))  // WZ, GPIO PA clear output byte 0
#define R8_PA_CLR_1         (*((PUINT8V)0x400010AD))  // WZ, GPIO PA clear output byte 1
#define R32_PA_PU           (*((PUINT32V)0x400010B0)) // RW, GPIO PA pullup resistance enable
#define R8_PA_PU_0          (*((PUINT8V)0x400010B0))  // RW, GPIO PA pullup resistance enable byte 0
#define R8_PA_PU_1          (*((PUINT8V)0x400010B1))  // RW, GPIO PA pullup resistance enable byte 1
#define R32_PA_PD_DRV       (*((PUINT32V)0x400010B4)) // RW, PA pulldown for input or PA driving capability for output
#define R8_PA_PD_DRV_0      (*((PUINT8V)0x400010B4))  // RW, PA pulldown for input or PA driving capability for output byte 0
#define R8_PA_PD_DRV_1      (*((PUINT8V)0x400010B5))  // RW, PA pulldown for input or PA driving capability for output byte 1
#define __nop()                 __asm__ volatile("nop")
#define HAL_GPIO_Pin_8      (0x00000100) /*!< Pin 8 selected */
#define HAL_GPIOA_ResetBits(pin)      (R32_PA_CLR |= pin)
#define HAL_GPIOA_SetBits(pin)        (R32_PA_OUT |= pin)


void delay_nop()
{
    uint32_t i=0;
    i=10000;
    do
    {
        __nop();
    } while(--i);
}

void GPIOA_ModeConfig(uint32_t pin)
{
    R32_PA_PD_DRV |= pin;
    R32_PA_DIR |= pin;
}

int main()
{
    GPIOA_ModeConfig(HAL_GPIO_Pin_8); // TXD-配置推挽输出，注意先让IO口输出高电平

    while(1)
    {
        delay_nop();
        HAL_GPIOA_SetBits(HAL_GPIO_Pin_8);
        delay_nop();
        HAL_GPIOA_ResetBits(HAL_GPIO_Pin_8);
    }
}
