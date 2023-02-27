#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_TimeInitStruct;
TIM_OCInitTypeDef TIM_OCInitStruct;

void GPIO_Config();
void TIM_Config();
void SysTick_Handler();
void Delay_ms(uint32_t time);
int SystemCounter;

int main(void)
{
	GPIO_Config();
	TIM_Config();

  while (1)
  {
	  for(int i = 0; i <= 100; i++)
	  {
		  /* for D12 led */
		  TIM_OCInitStruct.TIM_Pulse = i;
		  TIM_OC1Init(TIM4, &TIM_OCInitStruct);
		  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
		  Delay_ms(5);
		  /* for D13 led */
		  TIM_OCInitStruct.TIM_Pulse = i;
		  TIM_OC2Init(TIM4,&TIM_OCInitStruct);
		  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
		  Delay_ms(5);
		  /* for PD14 led*/
		  TIM_OCInitStruct.TIM_Pulse = i;
		  TIM_OC3Init(TIM4,&TIM_OCInitStruct);
		  TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
		  Delay_ms(5);
		  /* for PD15 led */
		  TIM_OCInitStruct.TIM_Pulse = i;
		  TIM_OC4Init(TIM4, &TIM_OCInitStruct);
		  TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
		  Delay_ms(5);
	  }
	  for(int i = 100; i >= 0; i--)
	  	  {
	  		  /* for D12 led */
	  		  TIM_OCInitStruct.TIM_Pulse = i;
	  		  TIM_OC1Init(TIM4, &TIM_OCInitStruct);
	  		  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	  		  Delay_ms(5);
	  		  /* for D13 led */
	  		  TIM_OCInitStruct.TIM_Pulse = i;
	  		  TIM_OC2Init(TIM4,&TIM_OCInitStruct);
	  		  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	  		  Delay_ms(5);
	  		  /* for PD14 led*/
	  		  TIM_OCInitStruct.TIM_Pulse = i;
	  		  TIM_OC3Init(TIM4,&TIM_OCInitStruct);
	  		  TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	  		  Delay_ms(5);
	  		  /* for PD15 led */
	  		  TIM_OCInitStruct.TIM_Pulse = i;
	  		  TIM_OC4Init(TIM4, &TIM_OCInitStruct);
	  		  TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	  		  Delay_ms(5);
	  	  }
  }
}


void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void TIM_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	/* PWM_Freq = 10KHz */
	TIM_TimeInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeInitStruct.TIM_Period = 99;
	TIM_TimeInitStruct.TIM_Prescaler = 83;
	TIM_TimeInitStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM4,&TIM_TimeInitStruct);
	TIM_Cmd(TIM4, ENABLE);

	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;

	SysTick_Config(SystemCoreClock / 1000); // 1 sn'de bir kesmeye girer
}

void SysTick_Handler()
{
	if(SystemCounter > 0)
		SystemCounter--;
}

void Delay_ms(uint32_t time)
{
	SystemCounter = time;
	while(SystemCounter);
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
