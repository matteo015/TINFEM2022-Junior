#include <stdio.h>
#include <string.h>

#define size 8
#define base 2

void show_array(char array[]){
    int index;
    for(int index = 0; index < size; index++){
        printf("%c",array[index]);
        if(index==3)
            printf(" ");
    }
    printf("\n");
}

void convert(int num,char binary[],int index){
    if(num == 0) return;

    binary[index] = num%base + 48;
    convert(num/2,binary,index - 1);
}

void main(){
    int num = 3;
    int index = size - 1;
    char binary[size];

    
    while(num <= 255){
    memset(binary,'0',size);
    printf("Decimal - %4d Binario - ",num);
    convert(num,binary,index);
    show_array(binary);

    num++;
    }
}