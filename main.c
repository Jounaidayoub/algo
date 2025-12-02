#include "stdio.h"
#include "stdbool.h"
enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
typedef enum Day Day;
enum Month
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};
typedef enum Month Month;

bool Isbisextile(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int nbr_jour_dans_mois(Month month, int year)
{
    bool bissextie = Isbisextile(year);
    switch (month)
    {
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOBER:
    case DECEMBER:
        return 31;

    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        return 30;

    case FEBRUARY:
        return bissextie ? 29 : 28;

    default:
        return 0;
    }
}

Day jour_dans_semaine(int day, Month month, int year)
{

    // int year_offset = year - 1900
    int days=0;
    for (int i = 1900; i < year; i++)
    {
        days += Isbisextile(year) ? 366 : 365;
    }
    
    for (int i = 0; i < month; i++)
    {
        days += nbr_jour_dans_mois(i, year);
    }
    days += day;

    return days % 6;
}

int main()
{
    int year = 2025;
    Month month = DECEMBER;
    int day =2;

    printf("Jour dans semaine : %d\n", jour_dans_semaine(day,month,year));

    // printf("nbr de jours dans %d , %d est : %d\n", FEBRUARY, year, nbr_jour_dans_mois(FEBRUARY, year));
    // printf("bisextile %s \n", (Isbisextile(year) ? "OUI" : "NON"));
    // printf("hello world\n");
    return 0;
}