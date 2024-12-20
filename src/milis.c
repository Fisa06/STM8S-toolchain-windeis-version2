#include "milis.h"

#if defined(STM8S003) || defined(STM8S103) || defined(STM8S105) || defined(STM8S208)



volatile uint32_t miliseconds = 0;      // global variable storing milis value


// return value of milisecond timestamp ("atomic" read)
MILIS_PROTOTYPE
{

    uint32_t tmp;
    TIM4_ITConfig(TIM4_IT_UPDATE, DISABLE);
    tmp = miliseconds;
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
    return tmp;
}

// init TIM4 as source for milis interrupt (low priority)
void init_milis(void)
{
    TIM4_TimeBaseInit(PRESCALER, PERIOD);       // (16MHz / 128) / 125 = 1000Hz
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
    ITC_SetSoftwarePriority(ITC_IRQ_TIM4_OVF, ITC_PRIORITYLEVEL_1);     // n�zk� priorita p�eru�en�
    enableInterrupts();
    TIM4_Cmd(ENABLE);
}


#else
#warning "millis not defined for this platform !"
#endif
