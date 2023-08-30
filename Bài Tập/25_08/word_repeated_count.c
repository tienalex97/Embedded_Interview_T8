#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    char* w;
    uint8_t length;
    uint8_t repeat;
    bool bDisplay;
} Words;

Words *getWord(char* arr)
{
    static int nArrSize ;
    nArrSize=1;
    int i=0;
    while(arr[i]!= '\0')
    {   
        if(arr[i]== ' ')
            nArrSize++;
        i++;
    }
    printf("Arr size is: %d\n", nArrSize);
    
    int index= 0;
    int count=0;
    Words *word= malloc(sizeof(Words)*nArrSize);
    word[index].w= arr;
    
    i= 0;
    while(arr[i]!= '\0')
    {
        if(arr[i] == ' ')
        {
            word[index].length= count;
            word[++index].w= arr+i+1;
            count= 0;
        }
        else if(arr[i]==',')
        {
            word[index].length= count;
            i++;
            word[++index].w= arr+i +1;
            count =0;
        } 
        else
        {
            count ++;
        }

        i++;
    }
    word[index].length= count;


    return word;
}

void displayWord(Words *word)
{
    for(int i=0; i<word->length; i++)
    {
        printf("%c", word->w[i]);
        //printf(".");
    }
    //printf("\n");
}

bool bIsEqual(Words* word1, Words* word2)
{   
    if(word1->length == word2->length && *word1->w== *word2->w)
        return true;
    return false;
}

int main()
{
    
    char array[]= "mot hai ba, mot hai hai mot, ba bon, bon ba";
    Words* word= getWord(array);
    
    for(int i=0; i<11; i++)
    {   
        uint8_t count=0;
        for(int j=0; j<11; j++)
        {
            if(bIsEqual(word+i, word+j))
            {
                count++;
                if(count >= 2) (word+j)->bDisplay = false;
                else (word+j)->bDisplay= true;
            }

        }
        (word+i)->repeat= count;
        
    }

    for(int i=0; i<11; i++)
    {
        if((word+i)->bDisplay )
        {
            printf("tu ");
            displayWord(word+i);
            printf(" xuat hien %d lan", (word+i)->repeat);
            printf("\n");
        }
    }
    return 0;
}
