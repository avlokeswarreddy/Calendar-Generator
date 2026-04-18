//Calendar Generator: A console app that displays a monthly or yearly calendar. It teaches date-handling logic and leap-year checks.
#include<stdio.h>
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}
void printCalendar(int month, int year) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("     %s %d\n", months[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");
    int daysInMonth = getDaysInMonth(month, year);
    int firstDay = (1 + (month + 1) * 26 / 10 + year + year / 4 - year / 100 + year / 400) % 7; // Zeller's Congruence
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((firstDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
int main() {
    int month, year;
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);
    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return 1;
    }
    printCalendar(month, year);
    return 0;
}