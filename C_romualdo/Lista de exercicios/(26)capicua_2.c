#include <stdio.h>

#define true 1
#define false 0;

int num_lenght(int num){
    char lenght[999];
    sprintf(lenght,"%d",num);
    return strlen(lenght);
}

int invert_num(int num){
    int inverted = 0;
    int lenght = num_lenght(num);

    for(;lenght > 0; lenght --){
        inverted = inverted*10 + num%10;
        num /= 10;
    }
    return inverted;
}

int eh_capicua(int num){
    if(num == invert_num(num)) return true;
        else false;
}

int closest_capicua(int num){
    while(eh_capicua(num) != true){
        num += invert_num(num);
    }
    return num;
}
void main(){
    int number;
    
    printf("Insira um numero inteiro: ");
    scanf("%d",&number);

    printf("O capicua mais proximo de %d e %d",number,closest_capicua(number));
}