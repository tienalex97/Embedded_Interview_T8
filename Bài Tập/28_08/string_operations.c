/*
* File: string_operations.c
* Author: Tien Alex
* Date: 28/08/2023
* Description:
     1. Write all chars after '.' (ASCII lowercut - 32= uppercut)
     2. Find out where is the phrase "around the world" and what is first index.
     3. Find the phrase "around the world" and replace it by "learn about".
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>


// Declare prototype of utility functions.

uint8_t getLength(const char* string) ;
void displayArr(const char* arr);
/* 
* Function: getLength
* Description: returns length of a string.
* Input: source string
* Output: length
*/
uint8_t getLength(const char* string)
{
    uint8_t count= 0;
    while(string[count] != '\0')
    {
        count++;
    }
    return count;
}
/* 
* Function: displayArr
* Description: Displays all members of an array.
* Input: source string
* Output : void
*/
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

/* 
* Function: upperCaseAfterChar
* Description: Changes all characeters of a string after particular character to uppercase.
* Input:  source array, particular char
* Output: source array
*/
char* uppercaseAfterChar( char* arr, char const c)  
{
    uint8_t i=0;
    i=0;
    while(arr[i] != '\0')
    {
        if(arr[i] == c)
        {
            uint8_t j=i+1;
            while(arr[j]!= '\0')
            {
                if(arr[j]!= ' ')    
                    arr[j] -= 32;
                j++;
            }
        }
        i++;
    }
    return arr;
}

/* 
* Function: getIndexOfStringInArr
* Description: returns the index of a string that appeared in an char array.
Just use in case that phrase is appeared only once in string.
* Input: source array, string that need to find index
* Output:   index
*/  
uint8_t getIndexOfStringInArr(const char* arr, const char* str)         
{
    bool bEqual= false;
    uint8_t phraseLength= getLength(str);
    uint8_t i=0; 
    uint8_t index;                          
    while(arr[i] != '\0')
    {
        if(arr[i] ==*str)
        {
            uint8_t countEqual=0;
            for(int n=0; n<phraseLength; n++)
            {
                if(arr[i+n]== str[n])
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

/* 
* Function: replaceStringInArray
* Description: Finds a string in array and replaces it by another string.
* Input: source array, string to remove, string to replace
* Output: source array
*/


char* replaceString(char* string, char* str1, char* str2)
{
    uint8_t indexStr1= getIndexOfStringInArr(string, str1);
    uint8_t lenStr1= getLength(str1);
    uint8_t lenStr= getLength(string);
    uint8_t lenStr2= getLength(str2);

    uint8_t lenNewStr= lenStr+lenStr2- lenStr1;
    // First case: new string is shorter than replaced string.
    if(lenNewStr<lenStr)
    {
        for(uint8_t i=0; i<lenStr2; i++)
        {
            string[indexStr1+i]= str2[i];
        }
        for(uint8_t i= 0; i<lenNewStr- indexStr1-lenStr2; i++)
        {
            string[i+ indexStr1+lenStr2] = string[i+indexStr1+lenStr1];
        }
        string[lenNewStr]= '\0';
    }
    else if(lenNewStr>lenStr)
    {
        for(uint8_t i=0; i< lenNewStr-indexStr1-lenStr2; i++)
        {
            string[lenNewStr-1-i]= string[lenStr-1-i];
        }
        for(uint8_t i=0; i<lenStr2; i++)
        {
            string[indexStr1+i]= str2[i];
        }
        string[lenNewStr]= '\0';

    }
    else{
        return "error 404 not found!\n";
    }
  
    
    return string;
}

// char* replaceStringInArray(char* arr, const char* str1, const char* str2 )  // Allow changing value of arr.
// {
//     uint8_t indexOfString1 = getIndexOfStringInArr(arr, str1);
//     printf("%d", indexOfString1);
//     if(indexOfString1 ==0)
//     {
//         printf("The string that need to be replaced has not found!\n");
//         return NULL ;
//     }
//     uint8_t lengthOfArr= getLength(arr);
//     uint8_t lengthOfStr1 = getLength(str1);
//     uint8_t lengthOfStr2= getLength(str2);
//     uint8_t lenghtOfTempString= lengthOfArr+lengthOfStr2-lengthOfStr1;
//     char* tempString= malloc(sizeof(char)*(lenghtOfTempString));
//     uint8_t i=0;
//     while(i<indexOfString1)
//     {
//         tempString[i]= arr[i];
//         i++;
//     }
//     uint8_t j=0;
//     while(j<lengthOfStr2)
//     {
//         tempString[i+j]= str2[j];
//         j++;
//     }
//     uint8_t k=0;
//     while(i+j+k<lenghtOfTempString)
//     {
//         tempString[i+j+k] = arr[indexOfString1+lengthOfStr1+k];
//         k++;
//     }

//     // Write back to original arr
//     i=0;
//     while(tempString[i]!='\0')
//     {
//         arr[i]= tempString[i]; 
//         i++;
//     }
//     arr[i]= '\0';
//     free(tempString);
//     return arr;
    
// }

int main()
{
    char array[]= "to help people around the world learn how to around the world everything. today we learn about that";
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
    
    char str2[]= "learn about real thing";
 //   displayArr(replaceStringInArray(array,str1, (str2));
    char str3[]= "everything";
    char str4[] ="1thing";
    displayArr(replaceString(array,str1, str2));
    displayArr(replaceString(array,str1, str2));
    

    // 1. Write all chars after '.' (ASCII lowercut - 32= uppercut)
    // 2. Find out where is the phrase "around the world" and what is first index.
    // 3. Find the phrase "around the world" and replace it by "learn about".


    return 0;
}
