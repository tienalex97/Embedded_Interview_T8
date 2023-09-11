/*
* File: printNumberToWords.c
* Author: Tien Alex
* Date: 11/09/2023
* Description:
    Print out a string of number to words.
*/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

enum LOCATION {
    DONG, 
    NGHIN,
    TRIEU, 
    TY
};

enum UNIT{
    TRAM,
    DONVI,
    CHUC
} ;

/* 
    * Function: printNumber
    * Description: Print the char number to words with corresponding unit
    * Input: const char numberp[], uint8_t index, uint8_t unit
    * Output:
*/
void printNumber( const char number[], uint8_t index, uint8_t unit)
{
    const char c= number[index];
    switch (c)
    {
        case '0':
            if(unit==TRAM ) printf("khong tram ");
            else if(unit== CHUC && number[index+1] != '0') printf("le ");
            break;
        case '1':
            if(unit==TRAM ) printf("mot tram ");
            else if(unit== CHUC ) printf("muoi ");
            else if((unit== DONVI && number[index-1]=='0' )|| (unit== DONVI && number[index-1]=='1')) printf("mot ");
            else if(unit == DONVI) printf("mots ");
            break;
        case '2':
            if(unit==TRAM) printf("hai tram ");
            else if(unit== CHUC ) printf("hai muoi ");
            else if(unit== DONVI ) printf("hai ");
            break;

        case '3':
            if(unit==TRAM) printf("ba tram ");
            else if(unit== CHUC ) printf("ba muoi ");
            else if(unit== DONVI ) printf("ba ");
            break;
        case '4':
            if(unit==TRAM) printf("bon tram ");
            else if(unit== CHUC ) printf("bon muoi ");
            else if(unit== DONVI ) printf("bon ");
            break;
        case '5':
            if(unit==TRAM) printf("nam tram ");
            else if(unit== CHUC ) printf("nam muoi ");
            else if(unit== DONVI && number[index-1] !='0'  ) printf("lam ");
            else if(unit== DONVI) printf("nam ");
            break;
        case '6':
            if(unit==TRAM) printf("sau tram ");
            else if(unit== CHUC ) printf("sau muoi ");
            else if(unit== DONVI ) printf("sau ");
            break;
        case '7':
            if(unit==TRAM) printf("bay tram ");
            else if(unit== CHUC ) printf("bay muoi ");
            else if(unit== DONVI ) printf("bay ");
            break;
        case '8':
            if(unit==TRAM) printf("tam tram ");
            else if(unit== CHUC ) printf("tam muoi ");
            else if(unit== DONVI ) printf("tam ");
            break;
        case '9': 
            if(unit==TRAM) printf("chim tram ");
            else if(unit== CHUC ) printf("chin muoi ");
            else if(unit== DONVI ) printf("chin ");
            break;
    }
}

/* 
    * Function: bChecZero
    * Description: Check whether all characters after index is equal '0', then just print "dong." and break the loop.
    * Input:  const char number[], const uint8_t index
    * Output: boolean
*/

bool bCheckZero(const char number[], const uint8_t index)
{
    // Check if all number after this number =0, just print "dong." and break the for loop.
    uint8_t check =0;
    uint8_t j= index+1;
    while(number[j]!= '\0')
    {
        if(number[j]!='0')
            check++;
        j++;
    }
    if(check== 0)
    {
        printf("dong.");
        return true;
    }
    return false;
}

/* 
    * Function: printNumberToWords
    * Description: Print all char of string number to words.
    * Input:  const char number[]
    * Output: 
*/
void printNumberToWords(const char number[])
{
    // Get lenght of number
    uint8_t len = 0;
    uint8_t unit;
    uint8_t location=0;

    uint8_t i=0;
    while(number[i]!= 0)
    {
        len++;
        i++;
    }
    // Loop through in4puted string
    for(uint8_t i=0; i<len; i++)
    {
        unit= (len-i)%3;
        printNumber(number, i, unit);
        // After print number, if the number is in uint DONVI, check its location to display more info
        if(unit==DONVI)
        {
            location= (len-(i+1))/3;   
            switch(location)
            {
                case DONG:
                    printf("dong.");
                    break;
                case NGHIN:
                    printf("nghin ");
                    if(bCheckZero(number, i)) return 0;  // Return 0 to break the for loop.
                    break;
                case TRIEU:
                    printf("trieu ");
                    if(bCheckZero(number, i)) return 0;
                    break;
                case TY:
                    printf("ty ");
                    if(bCheckZero(number, i)) return 0;
                    break;
            }
        }
    }

}

int main()
{
    char number[] = "10696100969"; // 10 696 100 969
    char number1[] = "10001000021";
    char number2[]= "10450000";
    puts(number);
    printNumberToWords(number);
    printf("\n==========\n");
    puts(number1);
    printNumberToWords(number1);
    printf("\n==========\n");
    puts(number2);
    printNumberToWords(number2);

    return 0;
}
