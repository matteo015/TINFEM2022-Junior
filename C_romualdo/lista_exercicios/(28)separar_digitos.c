#include <stdio.h>
#include <string.h>

#define size 999

void swap(char i, char j){
    char temp = i;
    i = j;
    j = temp;
}
    
void bubblesort(char num[]){
    int i,j;

    for(i = 0; i < strlen(num); i++)
    for(j = 0; j < strlen(num) - i; j++)
        if(num[j] + - 48 >  num[j + 1] - 48)
            swap(num[j], num[j + 1]);
}

void show_array(char array[]){
    int i;
    for(i = 0; i < strlen(array); i++)
        printf("%c ",array[i]);
}

void main(){
    char number[size];

    show_array(number);
}