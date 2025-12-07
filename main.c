#include <stdio.h>
#include "calendar.h"
#include "fibonacci.c"
int main()
{
    // int year = 2025;
    // Month month = DECEMBER;
    // int day = 31;

    // printf("Jour dans semaine : %d\n", jour_dans_semaine(day, month, year));


    //fibonacci
    int n=12;
    int res=fibonacci_rec(n);
    printf("fibonacci de %d is %d \n",n,res);


    return 0;
}