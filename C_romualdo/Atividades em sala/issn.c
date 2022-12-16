#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DV -1
#define ISSN_OK 0

int calcular_dv(char issn[]){
    int peso,soma,i,dv;
    peso = 8, soma = 0;
    
    for(i = 0; i < strlen(issn) - 1; i++)
        soma += (issn[i] - 48) * peso--;

    if(issn[7] == 'X')
        dv = (soma + 10) % 11;
    else
        if(soma % 11 < 2)
            dv = 0;
        else
            dv = 11 - soma % 11;
    return dv;
}

void gerar_issn(char issn[]){
    int i;

    for(i = 0; i < 8; i ++)
        issn[i] = (rand() % 10 ) + 48;
        issn[7] = calcular_dv(issn) + 48;
        issn[8] = '\0';
    }

void formatar_issn(char issn[], char issn_formatado[]){
    strncpy(issn_formatado,issn,4);
    issn_formatado[4] = '-';
    strncpy(&issn_formatado[5],&issn[4],4);
}

int validar_issn(char issn[]){
    int dv,dv_issn;

    dv = calcular_dv(issn);
    if(issn[7] == 'X')
        dv_issn = 0;
    else
        dv_issn = issn[7] - 48;
    if(dv != dv_issn)return DV;
        else return ISSN_OK;
}

void users_choice(char issn[]){
    int choice = 0;

    printf("Inserir ISSN [1] Gerar ISSN [2] Default (qualquer caractere)- ");
    scanf("%d",&choice);
    if(choice == 1)scanf("%s",issn);
    if(choice == 2)gerar_issn(issn);
}

void status_issn(char issn[],char issn_formatado[]){
    int resultado;

    resultado = validar_issn(issn);
    resultado == DV ? printf("\nErro no DV.\n\n") : 
    formatar_issn(issn,issn_formatado);
    
    if(resultado != DV)
        printf("\n[%s] Valido!!\n\n",issn_formatado);
}

void main(){
    srand(time(NULL));
    char issn[9] = "2434561X";
    char issn_formatado[10] = { 0 };

    users_choice(issn);
    status_issn(issn,issn_formatado);
}