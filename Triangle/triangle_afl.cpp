#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

const char* triangle( float a, float b, float c){
    bool IsTriangle;
    if( a > 200 || b > 200 || c > 200)
        return "Out of range value";
    if( a < 1 || b < 1 || c < 1)
        return "Out of range value";
    if( a + b > c && b + c > a && a + c > b){
        if( a == b && b == c)
            return "Equilateral";
        if( a == b || b == c || a == c)
            return "Isosceles";
        return "Scalene";
    } else return "Not a triangle";
}
int main(){
    int a, b, c;
    char len[16], *p;
    read(0, len, 15);
    p = strtok(len, " ");
    if(p != NULL){
        a = atoi(p);
        p = strtok(NULL, " ");
        if(p != NULL){
            b = atoi(p);
            p = strtok(NULL, " ");
            if(p != NULL){
                c = atoi(p);
                cout << triangle(a,b,c) << endl;
                return 0;
            }
        }
    }
    return 1;
}
