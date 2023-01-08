#include <stdio.h>

#define km 1
#define hm 2
#define dam 3 
#define m  4
#define dm 5
#define cm 6 
#define mm 7

void get_distance(int* distance){ 
    printf("Insira a distancia: ");
    scanf("%d",distance);
    }

void get_unit(int* unit){
    printf("Insira o tipo de unidade: ");
    scanf("%d",unit);
    }

int convert_distance(int distance, int unitA, int unitB){
    int i;
    if(unitA > unitB)
        for(i = unitA; i < unitB; i--){
            distance /=10;
            printf("Distancia>: %d \n",distance);
        }
    else
        for(i = unitA; i > unitB; i++){
            distance *=10;
            printf("Distancia<: %d \n",distance);
        }
    return distance;
    }

void show_distance(int distance){ printf("\nA distancia e de %d",distance); }

void show_unit(int unit){
    switch(unit){
        case km:  printf("km "); break;
        case hm:  printf("hm "); break;
        case dam: printf("dam"); break;
        case m :  printf("m  "); break;
        case cm:  printf("cm "); break;
        case dm:  printf("dm "); break;
        case mm:  printf("mm "); break;
    }
}

void show_options(){
    int i;
    for(i = 1; i < 7; i++){
        show_unit(i);
        printf("- %d.\t",i);
    }
}

void main(){
    int unitA,unitB;
    int distance;

    get_distance(&distance);
    show_options();
    
    get_unit(&unitA);
    get_unit(&unitB);

    printf("%unidade A-%d unidade B-%d",unitA,unitB);

    if(unitB != unitA){
        distance = convert_distance(distance,unitA,unitB);
        show_distance(distance);
        show_unit(unitB);

    }else{
      distance = convert_distance(distance,unitA,unitB);
      show_distance(distance);
      show_unit(unitA); 
    } 
}