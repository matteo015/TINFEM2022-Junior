#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void asterisk_converter(int number){
    int i = 0;
    for(i = 0; i < number; i++)
        printf("*");
}

void main(){
    
    srand(time(NULL));
    int number;
    number = rand() % 9 + 1;

    asterisk_converter(number);
}