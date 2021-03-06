#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
string commission(int locks, int stocks, int barrels){
    if( locks < 1 || locks > 70
    || stocks < 1 || stocks > 80
    || barrels < 1 || barrels > 90 )
        return "Out of range value";
    float sales = locks * 45 + stocks * 30 + barrels * 25;
    if( sales > 1800 ){
        return to_string(1000 * 0.1 + 800 * 0.15 + (sales - 1800) * 0.2);
    }else if( sales > 1000 ){
        return to_string(1000 * 0.1 + (sales - 1000) * 0.15);
    }else{
        return to_string(sales * 0.1);
    }
}
int main(){
    int locks, stocks, barrels;
    char input[16], *p;
    read(0, input, 15);
    p = strtok(input, " ");
    if(p != NULL){
        locks = atoi(p);
        p = strtok(NULL, " ");
        if(p != NULL){
            stocks = atoi(p);
            p = strtok(NULL, " ");
            if(p != NULL){
                barrels = atoi(p);
                cout << commission(locks, stocks, barrels) << endl;
                return 0;
            }
        }
    }
    return 1;
}
