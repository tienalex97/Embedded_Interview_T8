#include"stm32f10x_gpio.h"
#include"stm32f10x_rcc.h"
#include"stdio.h"

#define SCK GPIO_Pin_6
#define MISO GPIO_Pin_7
#define SS GPIO_Pin_8

#define PORT GPIOB

// Prototypes
void spi_Init(); // Initizalize gpio port as SCK, MOSI, SS pin
uint8_t receiveData(); // Read data via  SPI
void receiveArr(uint8_t* arr);
void waitToReceive(); // Speify which SS of slave pin to start transmit(by reset bit of this pin)
unsigned char msg=1;

int main()
{
	uint8_t arr[10];
	spi_Init();
	
	while(1)
	{
		//for(uint8_t i=0; i<10; i++)
		//{
		//	arr[i] = receiveData();
		//}
		//msg= receiveData();
		receiveArr(arr);
	}
	
	return 0;
}


void spi_Init()
{
	GPIO_InitTypeDef gpio_Spi; // It's just a structure used to pass params for GPIO_Init()
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // Provide clock for GPIO_PORTB
	
	// Set SCK and MOSI pin as INPUT-DOWN(default is LOW)
	gpio_Spi.GPIO_Pin= SCK|MISO;
	gpio_Spi.GPIO_Mode= GPIO_Mode_IPD;
	gpio_Spi.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio_Spi);
	
	// Set SS pin as INPUT-UP (defautl is HIGH)
	gpio_Spi.GPIO_Pin= SS;
	gpio_Spi.GPIO_Mode= GPIO_Mode_IPU;
	gpio_Spi.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio_Spi);
	
}

// To transmit data, first set data to MOSI, then set clock (cPOL=0, cPHA=0)
unsigned char receiveData()
{
	unsigned char data= 0;
	waitToReceive();
	
	for( uint8_t i=0; i<8; i++)
	{
		while(GPIO_ReadInputDataBit(PORT, SCK) ==0){} // Wait for clock change to HIGH
		// Once clock is HIGH, Start to read data
		if(GPIO_ReadInputDataBit(PORT, MISO) ==1) data = data | (0x80>>i);
		while(GPIO_ReadInputDataBit(PORT, SCK)==1) {} // Wait for clock change to LOW.
	}
	return data;
}

void receiveArr(uint8_t* arr)
{
	
	for(int i=0 ; i<10; i++)
	{
		arr[i] = receiveData();
	}
	
}


 void waitToReceive()
 {
	 while(GPIO_ReadInputDataBit(PORT, SS)== 1);
 }
