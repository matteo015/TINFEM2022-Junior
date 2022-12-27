#include <stdio.h>
#include <math.h>

#define pair 2
#define odd  1

int pair_or_odd(int num){
    if(num %2==0) return pair;
    return odd;
    }

int solve_calculation(){
    int i,sum = 0;
    for(i = 50; i > 0; i--)
        if(pair_or_odd(i) == pair) sum += i*i;
            else sum -= i*i;
    return sum;
}

void main(){
    int result = solve_calculation();
    printf("O resultado do calculo [50^2 - 49^2 + 48^2 - 47^2 + ... + 2^2 - 1^2 ] e %d",result);
}