#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Date {
    unsigned days;
    unsigned months;
    unsigned years;
} Date;

int getDMY(char* date, Date* dateNum) {
    char days[3];
    char months[3];
    char years[5];
    for(int i = 0; i < 2; i++) {
        days[i] = date[i];
    }
    days[2] = '\0';
    for(int i = 3; i < 5; i++) {
        months[i - 3] = date[i];
    }
    months[2] = '\0';
    for(int i = 6; date[i] != '\0'; i++) {
        years[i - 6] = date[i];
    }
    years[4] = '\0';
    dateNum -> days = atoi(days);
    dateNum -> months = atoi(months);
    dateNum -> years = atoi(years);
}

int isLeap(int years) {
    if(years % 4 == 0 && years % 100 != 0) {
        return 1;
    }
    if(years % 100 == 0 && years % 400 != 0) {
        return 0;
    }
    else if(years % 400 == 0) {
        return 1;
    }
    return 0;
}

int maxDaysCandidate(int months) {
    if(months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12) {
        return 1;
    }
    return 0;
}

void nextDay(Date* date) {
    if(date -> days == 31 && date -> days == 12) {
        date -> months = 1;
        date -> days = 1;
        date -> years++;
        return;
    }
    if(date -> days < 28) {
        date -> days++;
        return;
    }
    if(date -> days == 28 && date -> months == 2) {
        if(!isLeap(date -> years)) {
            date -> days = 1;
            date -> months++;
        }
        else {
            date -> days++;
        }
        return;
    }
    if(date -> days == 28 && date -> months != 2) {
        date -> days++;
        return;
    }
    if(date -> days == 29 && date -> months != 2) {
        date -> days++;
        return;
    }
    if(date -> days == 29 && date -> months == 2) {
        date -> days = 1;
        date -> months++;
    }
    if(date -> days == 30) {
        if(!maxDaysCandidate(date -> months)) {
            date -> days = 1;
            date -> months++;
        }
        else {
            date -> days++;
        }
        return;
    }
    if(date -> days == 31) {
        date -> days = 1;
        if(date -> months == 12) {
            date -> months = 1;
            date -> years++;
        }
        else {
            date -> months++;
        }
        return;
    }
}

int isEqual(Date date1Num, Date date2Num) {
    if(date1Num.months != date2Num.months || date1Num.days != date2Num.days || date1Num.years != date2Num.years) {
        return 0;
    }
    return 1;
}

int differenceDays(char* date1, char* date2) {

    Date date1Num, date2Num;
    getDMY(date1, &date1Num);
    getDMY(date2, &date2Num);
    int numOfDays = 0;

    while(!isEqual(date1Num, date2Num)) {
        numOfDays++;
        nextDay(&date1Num);
    }
    return numOfDays;
}
