#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int fatorial(int num){
    if(num == 0) return 1;
    return num * fatorial(num -1);
}

int combinacoes(int n, int k){
    return fatorial(n) / fatorial(k);
}

#define tam 999

void main(){

    
    int digitos[tam] = { 0 };
 

    printf("Combinacoes possiveis 10 elemetos de 4 em 4 %d",combinacoes(4,2));
}