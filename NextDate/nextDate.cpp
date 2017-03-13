#include "nextDate.h"
#include <string>
#include <iostream>
using namespace std;

const char* NextDate( int year, int month, int day){
    string year_s = to_string(year), month_s = to_string(month), day_s = to_string(day), output;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year < 1900 || year > 2025 || month < 1 || month > 12 )
        return "Invalid date";
    if( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        days[2] += 1;
    }
    if( day < 1 || day > days[month] )
        return "Invalid date";
    if( month == 12 && day == 31 )
        output = to_string(year+1)+"/1/1";
    else if(day == days[month])
        output = year_s+"/"+to_string(month+1)+"/1";
    else
        output = year_s+"/"+month_s+"/"+to_string(day+1);
    return output.data();
}