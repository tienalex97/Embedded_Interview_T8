#include"stdio.h"
#include"stdint.h"
#include"math.h"

typedef enum {
    MU= 1<<0,
    QUAN = 1<<1,
    AO = 1<<2,
    GIAY = 1<<3,
    DEP= 1<<4,
    DONG_HO= 1<<5,
    KINH= 1<<6,
    THAT_LUNG= 1<<7
    
} DO_DUNG_CA_NHAN;

#define Get_String(X)  case X : return #X
#define call(X, Y)  \
    X(MU) Y \
    X(QUAN) Y\
    X(AO) Y\
    X(GIAY)  Y\
    X(DEP)  Y\
    X(DONG_HO) Y\
    X(KINH) Y\
    X(THAT_LUNG) Y

static char* const Get_Name(uint8_t value)
{
    switch (value)
    {
        call(Get_String, ;)
        default: return NULL;
    }
}
void AddToCart(uint8_t *Gio_hang, DO_DUNG_CA_NHAN ten)
{
    *Gio_hang|= ten;
}
void CheckItem(uint8_t *Gio_hang, DO_DUNG_CA_NHAN ten)
{
    printf("Check hang: \n");
    uint8_t check;
    for(int i=0; i<8;i++)
    {
        check = 1<<i;
        if(check& ten)
        {
            printf("%s ", Get_Name(check));
            if(check & *Gio_hang)   printf("da co.\n");
            else printf("chua co.\n");
        }
    }
}
void ShowItem(int *Gio_hang){
    printf("Show hang: \n");
    for(int i=0;i<8;i++){  
        uint8_t check=1<<i;      
        if(*Gio_hang & check)   printf("%s \n",Get_Name(check));
    }
}    

int main()
{
    uint8_t GIO_HANG=0;
    AddToCart(&GIO_HANG, QUAN|AO|GIAY|DEP|MU);
    ShowItem(&GIO_HANG);
    CheckItem(&GIO_HANG, DONG_HO|KINH|GIAY);
}
