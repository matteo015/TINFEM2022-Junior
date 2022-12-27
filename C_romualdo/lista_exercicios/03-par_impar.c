#include <stdio.h>

#define pair 2
#define odd  1

int pair_or_odd(int num){
    if(num %2==0) return pair;
    return odd;
    }

void show_number_state(int num){
    if(pair_or_odd(num) == pair)
        printf("O numero e par.");
    else
        printf("O numero e impar");
    }

void main(){
    int number;

    printf("Insira um numero: ");
    scanf("%d",&number);

    show_number_state(number);
}