/*
* File: printWordsOfStringInReverseOrder.c
* Author: Tien Alex
* Date: 02/9/2023
* Description:
    Print out all words of a string but in reverse order.
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>


/* 
* Function: printWordsInReverseOrder
* Description: Print all the words of string but in reverse order.
* Input:  source string
* Output: void, print out to the screen.
*/
void printWordsInReverseOrder(const char string[])
{
    // Count words
    uint8_t i=0;
    uint8_t countWords=1;
    while(string[i]!= '\0')
    {
        if(string[i] == ' ')
            countWords++;
        i++;
    }

    // Create new arr to store index of each word in string
    uint8_t* indexOfWord= malloc(sizeof(uint8_t)*countWords);
    i=0;
    uint8_t j=0;
    indexOfWord[j] =i;
    while(string[i] != '\0')
    {
        if(string[i] == ' ')
            indexOfWord[++j]=++i;
        i++;
    }

    // Use these indexes to print the word in reverse order.
    for(i=0; i<countWords; i++)
    {
        j= indexOfWord[countWords-i-1];
        while(*(string+j)!= ' ' && *(string+j)!= '\0')
        {
            printf("%c", *(string+j));
            j++;
        }
        printf(" ");                  
    }

    // Free dynamically allocation.
    free(indexOfWord);
}

int main()
{
    char string[] = "mot hai ba bon hai ba mot hinh nhu anh noi anh say roi";
    printWordsInReverseOrder(string);

    return 0;

 }
