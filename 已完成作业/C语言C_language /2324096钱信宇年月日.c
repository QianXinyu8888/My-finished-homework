#include <stdio.h>
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void day_of_year(int year, int month, int day, int *pday) {
    int k, leap;
    int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    leap = is_leap_year(year);
    if(month < 1 || month > 12) {
        *pday = -1;
        return;
    }
    if(day < 1 || day > daytab[leap][month]) {
        *pday = -1;
        return;
    }
    for(k = 1; k < month; k++) {
        day += daytab[leap][k];
    }
    *pday = day;
}
int main() {
    int year;
    printf("Enter year:");
    scanf("%d",&year);
    int month;
    printf("Enter month:");
    scanf("%d",&month);
    int day;
    printf("Enter day:");
    scanf("%d",&day);
    int pday;
    day_of_year(year, month, day, &pday);
    printf("The day of the year is: %d\n", pday);
    return 0;
}
