#include "klee/klee.h"
#include "commission.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    int lock, stock, barrel;
    klee_make_symbolic(&lock, sizeof(lock), "lock");
    klee_make_symbolic(&stock, sizeof(stock), "stock");
    klee_make_symbolic(&barrel, sizeof(barrel), "barrel");
    cout << commission(lock, stock, barrel) << endl;
}
