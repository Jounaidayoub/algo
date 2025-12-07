#include <stdio.h>
#include "calendar.h"
#include "fibonacci.c"
#include <time.h>
int main()
{
    // int year = 2025;
    // Month month = DECEMBER;
    // int day = 31;

    // printf("Jour dans semaine : %d\n", jour_dans_semaine(day, month, year));

    // fibonacci
    int n = 45;
    clock_t start=clock();
    printf("fibonacci_iter de %d is %d \n", n, fibonacci_iter(n));
    clock_t end=clock();
    printf("clock for the iterfative version is : (%ld - %ld)=%ld \n",start,end,end-start);
    
    
    clock_t startr=clock();
    printf("fibonacci_rec de %d is %d \n", n, fibonacci_rec(n));
    clock_t endr=clock();
    printf("clock for the rec version is : (%ld - %ld)=%ld \n",startr,endr,endr-startr);
    return 0;
}