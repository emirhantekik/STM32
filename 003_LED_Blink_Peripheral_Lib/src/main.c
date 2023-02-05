#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_Config();
void Delay();

GPIO_InitTypeDef GPIO_InitStruct;

int main(void)
{

	GPIO_Config();

  while (1)
  {
	  GPIO_SetBits(GPIOD,GPIO_Pin_12);
	  GPIO_SetBits(GPIOD,GPIO_Pin_13);
	  GPIO_SetBits(GPIOD,GPIO_Pin_14);
	  GPIO_SetBits(GPIOD,GPIO_Pin_15);
	  delay(16800000);
	  GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	  GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	  GPIO_ResetBits(GPIOD, GPIO_Pin_14);
	  GPIO_ResetBits(GPIOD, GPIO_Pin_15);
	  delay(16800000);
  }
}

void Delay(uint32_t time)
{
	while(time--);
}

void GPIO_Config()
{
	/*We want to use D-12,13,14,15, So enable clock of D port*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, Enable);

	/*We use LED on stm32f4 board*/
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	/*update that what we configurate D port*/
	GPIO_Init(GPIOD, &GPIO_InitStruct);

}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
