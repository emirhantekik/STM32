#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_Config();
void TIM_Config();
void NVIC_Config();
void TIM3_IRQHandler();
int count = 0;


GPIO_InitTypeDef GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_InitStruct;
NVIC_InitTypeDef NVIC_InitStruct;

int main(void)
{

	GPIO_Config();
	TIM_Config();
	NVIC_Config();
  while (1)
  {
	  count = TIM_GetCounter(TIM3);
  }
}

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void TIM_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = 1999;
	TIM_InitStruct.TIM_Prescaler = 41999;
	TIM_InitStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM_InitStruct);

	TIM_Cmd(TIM3, ENABLE);
}

void NVIC_Config()
{
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn; /* Interrupt tim3'?n de?erine g?re olu?acak */
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	/* This function do that connect Timer to interrupt*/
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	NVIC_Init(&NVIC_InitStruct);
}

void TIM3_IRQHandler()
{
	GPIO_ToggleBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

	/* FLAG kalkt? bir kere interrupt olu?tuktan sonra flag hep kalkm?? olmamal? bunun i?in FLAGi indirmemiz gerek */
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update); /* Clear Flag */


}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
