#include"stm32f10x_gpio.h"
#include"stm32f10x_rcc.h"

#include"stdio.h"
#include"stdint.h"
#include"delay.h"


#define TX GPIO_Pin_9
#define PORT GPIOB

// Prototype
//void delayBitTime();
void startBit();
void stopBit();
void parityCheck(uint8_t data);
void uartInit();
void transmitData(uint8_t data);
void transmitArr(uint8_t *arr, uint8_t size);

int main()
{
	TIM2_INT_Init();
	uartInit();
	uint8_t arr[10]={0,1,2,3,4,5,6,7,8,9};
	
	delayMs(1000);
	
	transmitArr(arr, 10);
	
}
void transmitArr(uint8_t *arr, uint8_t size)
{
	for(uint8_t i=0; i<size; i++)
	{
		transmitData(arr[i]);
	}
}


void startBit()
{
	GPIO_ResetBits(PORT, TX);
	delayMs(10);
}
void stopBit()
{
	GPIO_SetBits(PORT, TX);
	delayMs(20);
}
void uartInit()
{
	// Config clock
	GPIO_InitTypeDef gpio_Uart; // It's just a structure used to pass params for GPIO_Init()
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	// Config uart
	gpio_Uart.GPIO_Pin= TX;
	gpio_Uart.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_Uart.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio_Uart);
	
	GPIO_SetBits(PORT, TX) ; // Default active high
}

void transmitData(uint8_t data)
{
	uint8_t count= 0;
	
	// Set start bit
	startBit();
	// Set data bits
	for(uint8_t i=0; i<8; i++)
	{
		if((data & (0x80>>i))) 
		{
			GPIO_SetBits(PORT, TX);
			count++;
		}
		else 
		GPIO_ResetBits(PORT, TX);
		delayMs(10);
	}
	// Set parity bit
	if(count%2 !=0)GPIO_SetBits(PORT, TX);
	else GPIO_ResetBits(PORT, TX);
	
	delayMs(10);
	
	// Set stop bit
	stopBit();
}
