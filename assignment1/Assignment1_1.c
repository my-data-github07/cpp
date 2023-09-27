#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day =1;
    ptrDate->month=1;
    ptrDate->year=2000;
}

void printDateonConsole(struct Date *ptrDate)
{
    printf("Date-%d:%d:%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter a day:");
    scanf("%d",&ptrDate->day);

    printf("Enter a month:");
    scanf("%d",&ptrDate->month);

    printf("Enter a year:");
    scanf("%d",&ptrDate->year);
}

int menu()
{
    int choice;
    printf("*************************************\n");
    printf("0. EXIT\n");
    printf("1. INITDATE\n");
    printf("2. PRINT DATE ON CONSOLE\n");
    printf("3. ACCEPT DATE FROM CONSOLE\n");
    printf("*************************************");

    scanf("%d",&choice);
    return choice;
}

int main()
{
    int choice;
    struct Date d1;

    while((choice=menu()) != 0)
    {
        switch(choice)
        {
            case 1:
            initDate(&d1);
            break;

            case 2:
            printDateonConsole(&d1);
            break;

            case 3:
            acceptDateFromConsole(&d1);
            break;

            default:
            printf("Enter valid Choice:");
            break;
        }
    }
    printf("Thanks for using our App.....");
    return 0;
}