#include<stdio.h>

struct Date 
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *d)
{
    d->day = 25;
    d->month = 4;
    d->year = 1999;
}

void printDateOnConsole(struct Date d)
{
    printf("Date: %d\n", d.day);
    printf("Month: %d\n", d.month);
    printf("Year: %d\n", d.year);
}

void acceptDateFromConsole(struct Date *d)
{
    printf("Enter the Date, Month & Year: ");
    scanf("%d %d %d", &(d->day), &(d->month), &(d->year));
}

int main()
{
    struct Date d;
    int choice;

    do
    {
        printf("\n0. Exit\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date\n");
        printf("3. Print Date\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                break;
            case 1:
                initDate(&d);
            break;

            case 2:
                acceptDateFromConsole(&d);
            break;
            case 3:
                printDateOnConsole(d);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

