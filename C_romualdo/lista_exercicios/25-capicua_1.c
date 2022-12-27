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

void main(){
    int number;

    printf("Insira um numero inteiro e positivo: ");
    scanf("%d",&number);

    if(eh_capicua(number) == true)
        printf("- O numero e capicua!!");
            else printf("- O numero nao e capicua.");
}