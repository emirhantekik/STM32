#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

/*
	We use external button and connect PB1
	When we press button, counter++
*/

static int count = 0;

void GPIO_Config();
void Delay(uint32_t time);

GPIO_InitTypeDef GPIO_InitStruct;

int main(void)
{
	GPIO_Config();
  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))
	  {
		  while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)); // while içi true olduðu sürece bekle
		  Delay(336000);

		  count++;
	  }

	  if(count == 1)
	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_12);
	  }
	  else if(count == 2)
	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_13);
	  }
	  else if(count == 3)
	  {
	  	  GPIO_SetBits(GPIOD, GPIO_Pin_14);
	  }
	  else if(count == 4)
	  {
	  	  GPIO_SetBits(GPIOD, GPIO_Pin_15);
	  }
	  else
	  {
		  GPIO_ResetBits(GPIOD,GPIO_Pin_15);
		  Delay(1680000);
		  GPIO_ResetBits(GPIOD,GPIO_Pin_14);
		  Delay(1680000);
		  GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		  Delay(1680000);
		  GPIO_ResetBits(GPIOD,GPIO_Pin_12);
	  }
  }//end of while
}

void GPIO_Config()
{
	/*Enable clock B port for external button*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	/*Enable clock D port for LEDs on button*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	/*Connect external button to PB1*/
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN; /* input mode */
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOB,&GPIO_InitStruct);

	/*Configurate LEDs*/
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void Delay(uint32_t time)
{
	while(time--);
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
