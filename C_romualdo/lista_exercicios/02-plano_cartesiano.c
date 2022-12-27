#include <stdio.h>
#include <math.h>

void get_points(int* Xa,int* Ya,int* Xb,int* Yb){
    printf("Insira o ponto \nXa: "); scanf("%d",Xa);
    printf("Ya: "); scanf("%d",Ya);
    printf("Xb: "); scanf("%d",Xb);
    printf("Yb: "); scanf("%d",Yb);
}

int points_distance(int Xa,int Ya,int Xb,int Yb) { return sqrt(pow(Xb - Xa,2) + pow(Yb - Ya,2)); }

void main(){
    int Xa,Ya,Xb,Yb;

    get_points(&Xa,&Ya,&Xb,&Yb);
    printf("\nA distancia entre os pontos e de %d unidades de medida.",points_distance(Xa,Ya,Xb,Yb));
}