#include "calendar.h"

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
    int days = 0;
    for (int i = 1900; i < year; i++)
    {
        days += Isbisextile(i) ? 366 : 365;
    }

    for (int i = 0; i < month; i++)
    {
        days += nbr_jour_dans_mois(i, year);
    }
    days += day - 1;

    return days % 7;
}
