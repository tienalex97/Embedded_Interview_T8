    /*
    * File: string_operations.c
    * Author: Tien Alex
    * Date: 28/08/2023
    * Description:
        Input dateTime(date, month, year)
        Return which is day?
    */

    #include<stdio.h>
    #include<stdint.h>
    #include<stdlib.h>
    #include<stdbool.h>




    typedef struct money{
        int day;
        int month;
        int year;
    } Date;

    // We need to declare a starting point of time.
    Date originalDatePoint= {1, 1, 2000};

    /* 
    * Function: getDayOfMonth
    * Description: Returns number of days in month.
    * Input:  month
    * Output: the number of days in month.
    */
    int getDayOfMonth(int i)
    {
        switch (i)
        {
        case 1: return 31;
        case 2:  return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        
        default:
            break;
        }
    }

    /* 
    * Function: getDayOfTheWeek
    * Description: Returns the day is which day of the week
    * Input:  date
    * Output: cn/t2/t3/.../t7
    */
    int getDayOfTheWeek(const Date* date)
    {

        // Count additional day of year
        int additionalDayCount= 0;
        for(int i= originalDatePoint.year; i<=date->year; i++ )
        {
            if(i%4==0)
                additionalDayCount++;
        }
        if(date->month<=2 && date->year%4 ==0) additionalDayCount --;
        
        int yearCount= (date->year-originalDatePoint.year)*365;
        int monthCount = 0;
        for(int i=1; i< date->month; i++)
        {
            monthCount+= getDayOfMonth(i);
        }
        if(date->month==1) monthCount= 0;

        int dayCount= additionalDayCount+ yearCount+monthCount+ date->day- 1;
        // 01/01/2000 la thu 7, assumme that chu nhat is 0, t7 is 6.
        return (dayCount+6)%7;
        
    }

    /* 
    * Function: displayDayOfTheWeek
    * Description: Print the day is which day
    * Input:  which day
    * Output: void, print out to the screen.
    */
    void displayDayOfTheWeek(int thu)
    {
        switch (thu)
        {
        case 0:
            printf(" is sunday\n");
            break;
        case 1:
            printf(" is monday\n");
            break;
        case 2:
            printf(" is tuesday\n");
            break;
        case 3:
            printf(" is wednesday\n");
            break;
        case 4:
            printf(" is thursday\n");
            break;
        case 5:
            printf(" is friday\n");
            break;
        case 6:
            printf(" is saturday\n");
            break;
        default:
            break;
        }
    }


    int main()
    {
    
        int d, m, y;
        while(1)
        {
            printf("Input current date(d/m/y) : ");
            scanf("%d",&d);
            scanf("%d", &m);
            scanf("%d",&y);
            Date currentDate= {d,m,y};
            printf("The day %d/%d/%d",d,m,y);
            displayDayOfTheWeek(getDayOfTheWeek(&currentDate));
        }
        return 0;
        
        
    }
