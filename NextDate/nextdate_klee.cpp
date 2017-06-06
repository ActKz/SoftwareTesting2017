#include "klee/klee.h"
#include <iostream>
#include <string>
using namespace std;
string NextDate( int year, int month, int day){
    string year_s = to_string(year), month_s = to_string(month), day_s = to_string(day), output;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year < 1900 || year > 2025 || month < 1 || month > 12 )
        return "Out of range value";
    if( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        days[2] += 1;
    }
    if( day < 1 || day > 31)
        return "Out of range value";
    else if( day > days[month] )
        return "Invalid date";
    if( month == 12 && day == 31 )
        output = to_string(year+1)+"/1/1";
    else if(day == days[month])
        output = year_s+"/"+to_string(month+1)+"/1";
    else
        output = year_s+"/"+month_s+"/"+to_string(day+1);
    return output;
}
int main(){
    int year, month, day;
    klee_make_symbolic(&year, sizeof(year), "year");
    klee_make_symbolic(&month, sizeof(month), "month");
    klee_make_symbolic(&day, sizeof(day), "day");
    printf("%s\n",NextDate(year, month, day).data());
    return 0;
}
