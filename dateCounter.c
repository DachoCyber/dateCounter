#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dates.h"

int main()
{
    char date1[12];
    char date2[12];
    printf("This program count the number of days between two days. Enter old date, then new date!\n");
    printf("Enter a date in format dd/mm/yyyy: ");
    scanf("%s", date1);
    printf("Enter second date in format dd/mm/yyyy: ");
    scanf("%s", date2);

    int numOfDays = differenceDays(date1, date2);
    printf("%d\n", numOfDays);

    return 0;
}
