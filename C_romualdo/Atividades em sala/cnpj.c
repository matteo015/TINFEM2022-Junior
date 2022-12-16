#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DV1 -1
#define DV2 -2
#define cnpj_OK 0

int calcular_dv(char cnpj[],int ponteiro){
    int peso,soma,i,dv;
    peso = (ponteiro == 2) ? 5 : 6; 
    soma = 0;                       
                    
    for(i = 0; i < strlen(cnpj) - ponteiro; i++){
        soma += (cnpj[i] - 48) * peso--;
        peso  = (peso < 2) ? 9 : peso;
      }                                 
    return dv = (soma%11 < 2) ? 0 : (11 -soma%11);
}

void gerar_cnpj(char cnpj[]){
    int i;
    for(i = 0; i < 13; i++){
        cnpj[i] = (rand() % 10) + 48;
        if(i >= 8 && i <= 10)            
            cnpj[i] = '0';
    }
    cnpj[11] = '1'; 
    cnpj[12] = calcular_dv(cnpj,2) + 48;
    cnpj[13] = calcular_dv(cnpj,1) + 48;
    cnpj[14] = '\0';
}
void formatar_cnpj(char cnpj[], char cnpj_formatado[]){
    strncpy(cnpj_formatado,cnpj,2);
    cnpj_formatado[2] = '.';
    strncpy(&cnpj_formatado[3],&cnpj[2],3);
    cnpj_formatado[6] = '.';
    strncpy(&cnpj_formatado[7],&cnpj[5],3);
    cnpj_formatado[10] = '/';
    strncpy(&cnpj_formatado[11],&cnpj[8],4);
    cnpj_formatado[15] = '-';
    strncpy(&cnpj_formatado[16],&cnpj[12],2);
}

int validar_cnpj(char cnpj[]){
    int vezes,ind,ponteiro,dv,dv_cnpj;

    for(vezes = 1; vezes <= 2; vezes++){
        ponteiro = (vezes == 1) ? 2 : 1;
        dv = calcular_dv(cnpj,ponteiro);

        ind = (vezes == 1) ? 12 : 13;
        dv_cnpj = cnpj[ind] - 48;
        if(dv != dv_cnpj)
            if(vezes == 1) return DV1; 
                else return DV2; 
        }
    return cnpj_OK;
    }

void users_choice(char cnpj[]){
    int choice = 0;

    printf("Inserir cnpj [1] Gerar cnpj [2] Default (qualquer caractere)- ");
    scanf("%d",&choice);
    if(choice == 1)scanf("%s",cnpj);
    if(choice == 2)gerar_cnpj(cnpj);
}

void status_cnpj(char cnpj[],char cnpj_formatado[]){
    int r;
    r = validar_cnpj(cnpj);
    r == DV1 ? printf("\nErro no DV1") : 
    r == DV2 ? printf("\nErro no DV2") :
    formatar_cnpj(cnpj,cnpj_formatado);

    if(r != DV1 && r != DV2)
        printf("[%s] Valido!!\n\n",cnpj_formatado); 
}

void main(){
    srand(time(NULL));
    char cnpj[15] = "43285136000106";
    char cnpj_formatado[19] = { 0 };

    users_choice(cnpj);
    status_cnpj(cnpj,cnpj_formatado);
}