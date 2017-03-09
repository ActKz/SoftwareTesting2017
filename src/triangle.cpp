#include "triangle.h"
using namespace std;

char* triangle( float a, float b, float c){
    bool IsTriangle;
    if( a > 200 || b > 200 || c > 200)
        return "Exceed upper bound";
    if( a < 1 || b < 1 || c < 1)
        return "Not a triangle";
    if( a + b > c && b + c > a && a + c > b){
        if( a == b && b == c)
            return "Equilateral";
        if( a == b || b == c || a == c)
            return "Isosceles";
        return "Scalene";
    } else return "Not a triangle";
}

