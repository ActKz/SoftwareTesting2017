#include "nextDate.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
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
    char date[11], *p;
    read(0, date, 11);
    p = strtok(date, " ");
    if(p != NULL){
        year = atoi(p);
        p = strtok(NULL, " ");
        if(p != NULL){
            month = atoi(p);
            p = strtok(NULL, " ");
            if(p != NULL){
                day = atoi(p);
                cout << NextDate(year, month, day) << endl;
                return 0;
            }
        }
    }
    return 1;
}
