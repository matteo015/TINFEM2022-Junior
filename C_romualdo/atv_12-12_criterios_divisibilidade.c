#include <stdio.h>
#include <string.h>

#define TAM 10000
#define true 1
#define false 0

int qtd_digitos(int number){
    char num[TAM];
    sprintf(num, "%d" ,number);
    return strlen(num); 
}

int calcular(int number){
    int i,tam,soma = 0;
    tam = qtd_digitos(number);

    for(i = 0; i < tam; i++){
        soma += number % 10;
        number /= 10;
    }
    return soma;
}
int eh_div2(int number){ return (number%2 == 0) ? true : false; }

int eh_div3(int number){ return (calcular(number) % 3==0) ? true : false;}

int eh_div4(int number){
     return ((number%10 + 2*((number/10) % 10))==0) ||
            ((number%10 + 2*((number/10) % 10)) %4==0) ? true : false;
     }

int eh_div5(int number){ return (number %10==0) || (number % 5==0) ? true : false;}

int eh_div6(int number){ return (eh_div2(number) && eh_div3(number) == true) ? true : false;}

int eh_div7(int number){ return (number %7==0) ? true : false;}

int eh_div8(int number){ return (number %8==0) ? true : false;}

int eh_div9(int number){ return (calcular(number)%10 + calcular(number)/10) == 9 ? true : false;}

void criterios_divisibilidade(int number){
    printf("\nEste numero e divisivel por:");

    if(eh_div2(number) == true) printf(" 2");
    if(eh_div3(number) == true) printf(" 3");
    if(eh_div4(number) == true) printf(" 4");
    if(eh_div5(number) == true) printf(" 5");
    if(eh_div6(number) == true) printf(" 6");
    if(eh_div7(number) == true) printf(" 7");
    if(eh_div8(number) == true) printf(" 8");
    if(eh_div9(number) == true) printf(" 9");
}

void main(){
    int number = 0;

    printf("Para sair do loop digite ' -1 ' ");
    do{
    printf("\n\ninsira um numero: ");
    scanf("%d",&number);
    
    if(number >= 0)
        criterios_divisibilidade(number);
    }while(number != -1);
}