#include <stdio.h>
#include <string.h>

#define size 999

void swap(char* i, char* j){
    char temp = *i;
    *i = *j;
    *j = temp;
    }
    
void bubblesort(char num_array[]){
    int i,j;

    for(i = 0; i < strlen(num_array); i++)
    for(j = 0; j < strlen(num_array) - i - 1; j++)
        if(num_array[j] - 48 > num_array[j + 1] - 48)
            swap(&num_array[j], &num_array[j + 1]);
    }

void show_array(char num_array[]){
    int i;
    printf("\n");
    for(i = 0; i < strlen(num_array); i++)
        printf("%c ",num_array[i]);
    }

void get_number(char num_array[]){
    printf("insira um numero: ");
    scanf("%s",num_array);
    }

void main(){
    char number[size];

    get_number(number);
    show_array(number);

    bubblesort(number);
    show_array(number);
}