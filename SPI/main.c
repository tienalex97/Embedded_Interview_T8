#include"stm32f10x_gpio.h"
#include"stm32f10x_rcc.h"
#include"stdio.h"

#define SCK GPIO_Pin_6
#define MOSI GPIO_Pin_7
#define SS GPIO_Pin_8

#define PORT GPIOB

// Prototypes
void spi_Init(); // Initizalize gpio port as SCK, MOSI, SS pin
void transmitData(uint8_t data); // Send data via  SPI
void transmitArray(uint8_t arr[10]);
void delay();	 
void clock();  // high-low
void startCondition(); // Speify which SS of slave pin to start transmit(by reset bit of this pin)
void stopCondition();	// Resit SS pin to stop transmit.

int main()
{
	//unsigned char msg= 'L';
	uint8_t arr[10] = {0,1,2,3,4,5,6,7,8,9};
	
	spi_Init();
	//transmitData(msg);
	
	transmitArray(arr);
	
	return 0;
}

void clock()
{
	GPIO_SetBits(PORT, SCK);
	delay();
	GPIO_ResetBits(PORT, SCK);
	delay();
}
void spi_Init()
{
	GPIO_InitTypeDef gpio_Spi; // It's just a structure used to pass params for GPIO_Init()
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// Set SCK and MOSI pin as OUTPUT-LOW, SS as OUTPUT-HIGH
	gpio_Spi.GPIO_Pin= SCK|MOSI|SS; 
	gpio_Spi.GPIO_Mode= GPIO_Mode_Out_PP;
	gpio_Spi.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio_Spi);
	
	GPIO_ResetBits(PORT, SCK); 
	GPIO_ResetBits(PORT, MOSI);
	GPIO_SetBits(PORT, SS);
}

void transmitArray(uint8_t arr[10])
{
	 uint8_t count=10;
	while(count>0) 
	{
		transmitData(arr[count-1]);
		count --;
		delay();
	}
}




// To transmit data, first set data to MOSI, then set clock (cPOL=0, cPHA=0)
void transmitData(uint8_t data)
{
	startCondition();
	for(uint8_t i=0; i<8; i++)
	{
		if((data & (0x80>>i))==0) GPIO_ResetBits(PORT, MOSI);
		else GPIO_SetBits(PORT,MOSI);
//		GPIO_SetBits(PORT, SCK);											
//		delay();
//		GPIO_ResetBits(PORT, SCK);
//		delay();
		clock();
	}
	stopCondition();
}

void delay()
{
	for(int i=0; i<1000000; i++)
	{}
}
 void startCondition()
 {
	 GPIO_ResetBits(PORT, SS);
 }
 void stopCondition()
 {	 
	 GPIO_SetBits(PORT, SS);
 }
