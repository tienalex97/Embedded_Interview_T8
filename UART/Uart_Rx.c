#include"stm32f10x_gpio.h"
#include"stm32f10x_rcc.h"

#include"stdio.h"
#include"stdint.h"
#include"stdbool.h"
#include"delay.h"

#define RX GPIO_Pin_9
#define PORT GPIOB

// Prototype
void waitToStart();
void waitToEnd();

void uartInit();
int receiveData();
void receiveArr(uint8_t *arr, uint8_t size);

int main()
{
	uartInit();
	TIM2_INT_Init();
	uint8_t arr[10];
	while(1)
	{
		
			receiveArr(arr,10);
	}
}

void uartInit()
{
	// Config clock
	GPIO_InitTypeDef gpio_Uart; // It's just a structure used to pass params for GPIO_Init()
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	// Config uart
	gpio_Uart.GPIO_Pin= RX;
	gpio_Uart.GPIO_Mode = GPIO_Mode_IPU;
	gpio_Uart.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio_Uart);
	
	//GPIO_SetBits(PORT, TX) ; // Default active high
}



int receiveData()
{
	int msg=0;
	int count=0;
	waitToStart();

	for(uint8_t i=0; i<9; i++)
	{
		if(GPIO_ReadInputDataBit(PORT, RX) == 1)
		{
			msg = msg|(0x100>>i);
			count++;
		}
		delayMs(10);
	}

	waitToEnd();
	if(count%2 != 0) msg=0x06;
	msg= msg>>1;
	return msg;
}
void receiveArr(uint8_t *arr, uint8_t size)
{
	for(uint8_t j=0;j<size; j++)
	{
		arr[j]= receiveData();
	}
}

void waitToStart()
{
	while(GPIO_ReadInputDataBit(PORT, RX)==1);
	delayMs(15); // Read data in the middle of pulse. 
}

void waitToEnd()
{
	while(GPIO_ReadInputDataBit(PORT, RX)==0);
	delayMs(15);
}



