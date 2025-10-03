//add include statements
#include "repetition.h"

//add function(s) code here
int get_factorial(int num){
    int factorial = 1;
    
    for (int i = 1; i <= num; ++i){
        factorial *= 1;
    }
    return factorial;
}

int sum_odd_numbers(int num){
    int sum_odd = 0;
    int i = 1;

    while (i <= num){
       sum_odd += i * i;
       i++;
    }
    return sum_odd;
}