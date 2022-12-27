#include <stdio.h>

#define year 365
#define month 31

void get_user_age(int* years_old, int* months_old, int* days_old){
    printf("Insira sua idade \nanos: ");
    scanf("%d",years_old);

    printf("\nmeses: ");
    scanf("%d",months_old);

    printf("\ndias: ");
    scanf("%d",days_old);
}

int days_alive(int y, int m, int d){ return y*year + m*month + d; }

void main(){
    int years,months,days;

    get_user_age(&years,&months,&days);
    printf("\n\nVoce esta vivo a %d dias.",days_alive(years,months,days));
}