#include <stdbool.h>
#include <stm8s.h>
#include <stdio.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
#include "../inc/uart1.h"

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    init_milis();
    init_uart1();
}


int main(void)
{
  
    uint32_t time = 0;
    uint32_t xdd = 0;
    init();

    while (1) {

        if (milis() - time > 1000 ) {

            REVERSE(LED);
            printf("%u\n", xdd);
            time = milis();
            //printf("%ld\n", time);
        }
        //delay_ms(333);
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
