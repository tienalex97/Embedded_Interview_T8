/*
* File: sort_words_alphabetically.c
* Author: Tien Alex
* Date: 08/09/2023
* Description:
    Sort all words of a string from a to z.
*/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


 /* 
    * Function: nCompareStr
    * Description: Returns less, equa or greater than 0.
    * Input:  const char* p1, const char* p2
    * Output: c1-c2
*/
int nCompareStr (const char *p1, const char *p2)
{
    const unsigned char *s1 = (const unsigned char *) p1;
    const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1, c2;
    do
    {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c1 == '\0') return c1 - c2;
    }
    while (c1 == c2);

    return c1 - c2;
}

 /* 
    * Function: countWords
    * Description: Returns number of words in a string.
    * Input:  const char* str
    * Output: the number of words in string.
    */
uint8_t countWords(const char* str)
{
    uint8_t nCount= 1;
    while(*str!= '\0')
    {
        if(*str == ' ')  nCount++;
        str++;
    }
    return nCount;
}

 /* 
    * Function: displayString
    * Description: Display string.
    * Input:  const char* str
    * Output:
*/
void displayString(const char* str)
{
    while(*str!= '\0')
    {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

 /* 
    * Function: sortAlphabeticaly
    * Description: Sort string a-z.
    * Input:  const char* str
    * Output: .
    */
void sortAlphabetically( const char* str)
{
    // How many words does string have?
    uint8_t words= countWords(str);

    // Create an array to store the first character of each word.
    char** ptr = malloc(sizeof(char)*words);      // ptr-address, *ptr = char
    
    uint8_t i=0;
    uint8_t j=0;
    *ptr= str;
    j++;
    while(str[i]!= '\0')
    {
        if(str[i] ==' ')
        {
            ptr[j]= str+i+1;
            j++;
        }
        i++;
    }

    // Then sort it from a to z
    for(uint8_t i=0; i<words; i++)
    {
        for(uint8_t j= 0; j<words; j++)
        {
            char* temp= NULL;
            
            //if((*ptr[i] <= *ptr[j] && getLen(ptr[i])<=getLen(ptr[j]) && *(ptr[i]+1)<= *(ptr[j]+1)))   -- getLen caused problems.
            if(nCompareStr(ptr[i], ptr[j])<0)
            {
                temp = ptr[i];
                ptr[i]= ptr[j];
                ptr[j] =temp;
            } 
        }
    }
    // Display them to screen
    for( uint8_t i =0; i<words; i++)
    {
        while(*ptr[i] != ' ' && *ptr[i] != 0 )
        {
            printf("%c", *ptr[i]);
            ptr[i]++;
        }
        printf(" ");
    }
    printf("\n");
}

int main()
{
    char* string ="s s s sau bay tam chin hai hai ba ba bon mot m m m  ";
    
    displayString(string);
    printf("sort a-z: ");
    sortAlphabetically(string);

    return 0;
}
