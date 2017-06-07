#include "klee/klee.h"
#include <stdio.h>
#include <string.h>
int NextDate( int year, int month, int day){
    int output;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year < 1900 || year > 2025 || month < 1 || month > 12 )
        return 1;
    if( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        days[2] += 1;
    }
    if( day < 1 || day > 31)
        return 1;
    else if( day > days[month] )
        return 2;
    if( month == 12 && day == 31 )
        output = (year+1)*10000+101;
    else if(day == days[month])
        output = year*10000+(month+1)*100+1;
    else
        output = year*10000+month*100+day+1;
    return output;
}
int main(int argc, char** argv){
    int year, month, day;
    klee_make_symbolic(&year, sizeof(year), "year");
    klee_make_symbolic(&month, sizeof(month), "month");
    klee_make_symbolic(&day, sizeof(day), "day");
    printf("%d\n", NextDate(year, month, day));
    return 0;
}
