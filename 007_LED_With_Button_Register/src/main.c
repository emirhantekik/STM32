#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_Config();
void Delay(uint32_t time);

int count = 0;

int main(void)
{
	GPIO_Config();
  while (1)
  {
	  if(GPIOA->IDR & 0x00000001)
	  {
		  /*delay for arcs that may occur*/
		  while(GPIOA->IDR & 0x00000001); //Am I still push button ?
		  Delay(1680000);
		  count++;
	  }

	  if(count % 2 == 0)
	  {
		  GPIOD->ODR |= 0x0000F000; // LEDs turn on
	  }
	  else
		  GPIOD->ODR |= 0x00000000; // LEDs turn off
  }
}

void GPIO_Config()
{
	/*CLOCK Configuration*/
	RCC->CR |= 0x00030000; /*HSEON and HSEONRDY enable */
	while(!(RCC->CR & 0x00020000)) /*HSEON Ready flag wait*/
	RCC->CR |= 0x00080000; /*CSS Enable*/
	RCC->PLLCFGR |= 0x00400000; // PLL e HSE seçilir
	RCC->PLLCFGR |= 0x00000004; // PLL M = 4
	RCC->PLLCFGR |= 0x00005A00; // PLL N = 168
	RCC->PLLCFGR |= 0x00000000; //PLL P = 2

	RCC->CFGR |= 0x00000000; //AHB Prescaler = 1
	RCC->CFGR |= 0x00000004; //APB2 Prescaler = 2 //APB2 max çalýþma frekansý 84MHz
	RCC->CFGR |= 0x00001400; //APB1 Prescaler = 4 // APB1'in max çalýþma frekansý 42MHz
	RCC->CIR |= 0x00880000; //HSERDY and CSS Flag clear

	/*GPIO configuration*/
	RCC->AHB1ENR |= 0x00000009; // GPIOA and GPIOD port enable
	GPIOD->MODER |= 0x55000000; //Pin 12,13,14,15 digital output
	GPIOD->OTYPER |= 0x00000000;
	GPIOD->OSPEEDR |= 0xFF000000;
	GPIOD->PUPDR |= 0x00000000;

}

void Delay(uint32_t time)
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
