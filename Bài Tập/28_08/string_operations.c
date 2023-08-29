 // 1. Write all chars after '.' (ASCII lowercut - 32= uppercut)
// 2. Find out where is the string "around the world" and what is first index of this string.
// 3. Find the string "around the world" and replace it by "learn about".

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

uint8_t getLength(char* string) ;
void displayArr(const char* arr);
uint8_t getLength(char* string)
{
    uint8_t count= 0;
    while(string[count] != '\0')
    {
        count++;
    }
    return count;
}

void displayArr(const char* arr)
{
    uint8_t i=0; 
    while(arr[i]!= '\0')
    {   
        printf("%c", arr[i]);
        i++;
    }
    
    printf(".\n");
}

char* uppercaseAfterChar(char* string, char const c)
{
    uint8_t i=0;
    // Create a new array to keep in inputed string stay primative.
    char *arr= malloc(sizeof(char)*getLength(string));
    while(string[i]!= '\0')
    {
        arr[i]= string[i];
        i++;
    }
    i=0;
    while(arr[i] != '\0')
    {
        if(arr[i] == c)
        {
            uint8_t j=i+1;
            while(arr[j]!= '\0')
            {
                if(arr[j]!= ' ')    
                    arr[j] = arr[j] -32;
                j++;
            }
        }
        i++;
    }
    return arr;
}


uint8_t getIndexOfStringInArr(char* string, char* string1)         // Just use in case that phrase is appeared only once in string. 
{
    bool bEqual= false;
    uint8_t phraseLength= getLength(string1);
    uint8_t i=0; 
    uint8_t index;                          
    while(string[i] != '\0')
    {
        if(string[i] ==*string1)
        {
            uint8_t countEqual=0;
            for(int n=0; n<phraseLength; n++)
            {
                if(string[i+n]== string1[n])
                    countEqual++;
            }
            if(countEqual==phraseLength) 
            {
                index= i;
                bEqual= true;
            }
        }
        i++;
    }
    if(!bEqual) return 0;
    return index;
}


char* replaceStringInArray(char* arr, char* str1, char* str2 )
{
    // Crerate tww new temporary arrays to store remain parts of old arr
    uint8_t indexOfString1 = getIndexOfStringInArr(arr, str1);
    if(indexOfString1 ==0)
    {
        printf("The string that need to be replaced has not found!\n");
        return NULL ;
    }
    uint8_t lengthOfArr= getLength(arr);
    uint8_t lengthOfStr1 = getLength(str1);
    uint8_t lengthOfStr2= getLength(str2);
    uint8_t lenghtOfTempString= lengthOfArr+lengthOfStr2-lengthOfStr1;
    char* tempString= malloc(sizeof(char)*(lenghtOfTempString));
    uint8_t i=0;
    while(i<indexOfString1)
    {
        tempString[i]= arr[i];
        i++;
    }
    uint8_t j=0;
    while(j<lengthOfStr2)
    {
        tempString[i+j]= str2[j];
        j++;
    }
    uint8_t k=0;
    while(i+j+k<lenghtOfTempString)
    {
        tempString[i+j+k] = arr[indexOfString1+lengthOfStr1+k];
        k++;
    }

    // Write back to original arr
    i=0;
    while(tempString[i]!='\0')
    {
        arr[i]= tempString[i]; 
        i++;
    }
    arr[i]= '\0';
    free(tempString);
    return arr;
    
}

int main()
{
    char array[]= "to help people around the world learn how to do everything. today we learn about that";
    printf("String inputed is: \n");
    displayArr(array);
    printf("=============================\n");

    printf("Uppercase all character after '.' \n");
    displayArr(uppercaseAfterChar(array, '.'));
    printf("=========================\n");
    printf("Finding the phrase : around the world \n");
    char str1[]= "around the world";
    if(getIndexOfStringInArr(array, str1)!=0)
        printf("Tu khoa around the world xuat hien o vi tri %d \n", getIndexOfStringInArr(array, str1));
    else    printf("Khong phat hien tu khoa can tim \n");

    printf("============================\n");
    printf("After replaced 'around the world' by 'learn about', the arr now is: \n");
    char str2[]= "learn about";
    displayArr(replaceStringInArray(array,str1, str2));

   
    return 0;
}
