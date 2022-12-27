#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void fill_array(int num_array[]){
    int i;
    for(i = 0; i < size; i++)
        num_array[i] = rand() % 100;
    }

void show_array(int num_array[]){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",num_array[i]);
    }

int odd_sum(int num_array[]){
    int i,odd = 0;
    for(i = 0; i < size; i++)
        if(num_array[i] %2!=0)
           odd += num_array[i];
    return odd;
    }

int pair_sum(int num_array[]){
    int i,pair = 0;
    for(i = 0; i < size; i++)
        if(num_array[i] %2==0)
           pair += num_array[i];
    return pair;
    }

void show_greater_sum(int num_array[]){
    if(pair_sum(num_array) > odd_sum(num_array))
        printf("\nO maior somatorio e dos pares.");
    else
        printf("\nO maior somatorio e dos impares.");
    }

void main(){
    srand(time(NULL));
    int num_array[size];

    fill_array(num_array);

    printf("Numeros processados: ");
    show_array(num_array);

    printf("\nSoma dos pares: %d",pair_sum(num_array));
    printf("\nSoma dos impares: %d",odd_sum(num_array));

    show_greater_sum(num_array);
}