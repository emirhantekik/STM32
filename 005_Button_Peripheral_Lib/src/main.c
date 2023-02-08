#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

void Delay();
void GPIO_Config();

int main(void)
{

	GPIO_Config();
  while (1)
  {
	  /*Do I press the button?*/
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
	{
		/*Am I still press the button?*/
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
		Delay(1680000*2); // delay 2 second
		GPIO_ToggleBits(GPIOA,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_pin_14 | GPIO_Pin_15);
	}
  }
}
/*Own Delay function*/
void Delay(uint32_t time)
{
	while(time--);
}

/*
	We use user button and LEDs on board. We must activate the button on PA0.
	We must activate the LEDs on PD12,PD13,PD14,PD15.
 */
GPIO_Config()
{
	/*Activate A port for using button*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,Enable);
	/*Activate D port for using LEDs on board*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,Enable);

	/*Configuration A port for button*/
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configuration D port for LEDs on board*/
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);

}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
