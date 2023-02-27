#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

TIM_TimeBaseInitTypeDef TIM_InitStruct;
GPIO_InitTypeDef GPIO_InitStruct;

void Delay(uint16_t time);
void TIMER_Config();
void GPIO_Config();
int count = 0;


int main(void)
{
	TIMER_Config();
	GPIO_Config();
  while (1)
  {
	  count = TIM_GetCounter(TIM2);

	  if(count == 3999)
		  GPIO_SetBits(GPIOD,GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	  else if(count == 7999)
		  GPIO_ResetBits(GPIOD, GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
  }
}

void Delay(uint16_t time)
{
	while(time--);
}

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_InitStruct);
}

void TIMER_Config()
{
	/*Enable APB1 for TIM2*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	/*If set TIM period to 1999 and set TIM prescaler 41999, every 1 second program count 2000*/
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up; /* For Example : 0 to 100 */
	TIM_InitStruct.TIM_Period = 7999; /*Auto-Reload deðerini periyoda yazarýz. Yani ne yazarsak oraya kadar sayacak*/
	TIM_InitStruct.TIM_Prescaler = 41999; /* 2^16 deðeri kadar alabilir.*/
	TIM_InitStruct.TIM_RepetitionCounter = 0; /*kaç defa da bir tekrarlanacaðýný söyler +1 deðerine göre hareket eder*/

	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);

	TIM_Cmd(TIM2, ENABLE);
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
