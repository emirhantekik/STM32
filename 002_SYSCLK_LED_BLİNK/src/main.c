#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_CONFIG();
void delay(uint32_t time);
int main(void)
{
	GPIO_CONFIG();
  while (1)
  {
	  GPIOD->ODR = 0x0000F000; // LEDs turn on
	  delay(16800000);
	  GPIOD->ODR = 0x00000000; // LEDs turn off
	  delay(16800000);
  }
}

void GPIO_CONFIG()
{
	//Enable D port
	RCC-> AHB1ENR = 0x00000008;

	//Config GPIOD 12-13-14-15
	GPIOD-> MODER = 0x55000000;
	GPIOD->OTYPER = 0x00000000;
	GPIOD->OSPEEDR = 0xFF000000;
	GPIOD->PUPDR = 0x00000000;
}

void delay(uint32_t time)
{
	while(time--);
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
