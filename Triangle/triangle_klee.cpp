#include "klee/klee.h"
#include <iostream>
#include <string>
using namespace std;
const char* triangle( int a, int b, int c){
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
    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");
    klee_make_symbolic(&c, sizeof(c), "c");
    printf("%s\n", triangle(a, b, c));
    return 0;
}
