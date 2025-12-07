#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdbool.h>

typedef enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
} Day;

typedef enum Month
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
} Month;

bool Isbisextile(int year);
int nbr_jour_dans_mois(Month month, int year);
Day jour_dans_semaine(int day, Month month, int year);

#endif
