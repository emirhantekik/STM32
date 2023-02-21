#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void DAC2_Config();
void GPIO_Config();
void Delay(uint32_t time);

int i = 0;


/* This project you use GPIO and DAC so you pull two struct*/
GPIO_InitTypeDef GPIO_InitStruct;
DAC_InitTypeDef DAC_InitStruct;

int main(void)
{
	GPIO_Config();
	DAC2_Config();
  while (1)
  {
	  /*Read data 8-bit*/
	  for(i = 0; i < 255; i++)
	  {
		  DAC_SetChannel2Data(DAC_Align_8b_R,i);
		  Delay(100000);
	  }
	  i = 0;
  }
}

void Delay(uint32_t time)
{
	while(time--);
}

/* DAC_OUT1: PA4, DAC_OUT2: PA5 */
void GPIO_Config()
{
	/*Enable the GPIO AHB clock*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/*	DAC_OUT2: PA5	*/
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}


void DAC2_Config()
{
	/*	DAC APB clock must be enabled to get write access to DAC registers	*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;// Buffer ile gürültü engelleme çalýþtýrýlýr. Çýkýþta gürültü olmamasý için buffer aktif edilir.

	DAC_Init(DAC_Channel_2, &DAC_InitStruct);

	/*Çevresel birimleri çalýþtýrmak için çevresel birimleri aktif etmemiz gerekiyor.*/
	DAC_Cmd(DAC_Channel_2, ENABLE);
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
