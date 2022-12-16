#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 
#include <time.h>   

#define CPF_OK  0    
#define DV1 -1 
#define DV2 -2 

int calcular_dv(char cpf[], int ponteiro) {
   int peso, soma, i, dv;
   peso = (ponteiro == 9) ? 10 : 11;
   soma = 0;

   for (i = 0; i < ponteiro; i++)
      soma += ((cpf[i] - 48) * peso--);

   dv = 11 - (soma % 11);
   if(dv == 10 || dv == 11)return 0;
   return dv;
}

void gerar_cpf(char cpf[]) {
   int i;
   for(i = 0; i < 9; i++)
      cpf[i] = (rand() % 10) + 48;

   cpf[9]  = cpf[10] = '0';
   cpf[9]  = calcular_dv(cpf,9) + 48;
   cpf[10] = calcular_dv(cpf,10) + 48;
   cpf[11] = '\0';
}

void formatar_cpf(char cpf[], char cpf_formatado[]) {
   strncpy(cpf_formatado,cpf,3);
   cpf_formatado[3] = '.';
   strncpy(&cpf_formatado[4],&cpf[3],3);
   cpf_formatado[7] = '.';
   strncpy(&cpf_formatado[8],&cpf[6],3);
   cpf_formatado[11] = '-';
   strncpy(&cpf_formatado[12],&cpf[9],3);
}

void mostrar_estado_cpf(int estado) {
   switch(estado){
      case 0 : printf("Rio Grande do Sul");
         break;
      case 1 :
         printf("Distrito Federal, Goias, Mato Grosso, Mato Grosso do Sul, ");
         printf("Tocantins");
         break;
      case 2 : printf("Acre, Amapa, Amazonas, Para, Rondonia, Roraima");
         break;
      case 3 : printf("Ceara, Maranhao, Piaui");
         break;
      case 4 : printf("Alagoas, Paraiba, Pernambuco, Rio Grande do Norte");
         break;
      case 5 : printf("Bahia, Sergipe");
         break;
      case 6 : printf("Minas Gerais");
         break;
      case 7 : printf("Espirito Santo, Rio de Janeiro");
         break;
      case 8 : printf("Sao Paulo");
         break;
      case 9 : printf("Parana, Santa Catarina");
         break;
   }
   printf("\n");
}

int validar_cpf(char cpf[]){
   int vezes, ind, ponteiro, dv, dv_cpf;
   ponteiro = strlen(cpf) - 2;

   for(vezes = 1; vezes <= 2; vezes++){
      ponteiro = (vezes == 1) ? strlen(cpf) - 2 : strlen(cpf) - 1;
      dv = calcular_dv(cpf,ponteiro);

      ind = (vezes == 1) ? 9 : 10;
      dv_cpf = cpf[ind] - 48;
      if (dv != dv_cpf)
         if (vezes == 1) return DV1;
            else return DV2; 
        }
   return CPF_OK;
}

void users_choice(char cpf[]){
    int choice = 0;

    printf("Inserir CPF[1] Gerar CPF[2] Padrao (qualquer caractere)- ");
    scanf("%d",&choice);
    if(choice == 1)scanf("%s",cpf);
    if(choice == 2)gerar_cpf(cpf);
}

void status_cpf(char cpf[], char cpf_formatado[]){
    int  r;
    r = validar_cpf(cpf);
    r == DV1 ? printf("Erro no DV1\n") :
    r == DV2 ? printf("Erro no DV2\n") :
    formatar_cpf(cpf,cpf_formatado);
    
        if(r == CPF_OK)
            printf("\n[%s] Valido!!\n",cpf_formatado);
}

void main() {
    srand(time(NULL));
    char cpf[12] = "69889563010";
    char cpf_formatado[15] = { 0 };

    users_choice(cpf);
    status_cpf(cpf,cpf_formatado);

    int estado = cpf[8] - 48;
    mostrar_estado_cpf(estado);
}