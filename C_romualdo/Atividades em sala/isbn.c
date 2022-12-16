#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DV -1
#define ISBN_OK 0

int calcular_dv_isbn_10(char isbn10[]){
    int peso,soma,i,dv;
    peso = 10, soma = 0;
    
    for(i = 0; i < strlen(isbn10) - 1; i++)
        soma += (isbn10[i] - 48) * peso--;

    dv = (soma % 11 < 2) ? 0 : 11 - soma % 11;
    return dv;
}

void gerar_isbn_10(char isbn10[]){
    int i;
    for(i = 0; i < 10; i ++)
        isbn10[i] = (rand() % 10 ) + 48;
        isbn10[9] = calcular_dv_isbn_10(isbn10) + 48;
        isbn10[10] = '\0';
}

void formatar_isbn_10(char isbn10[],char isbn_formatado[]){
    strncpy(isbn_formatado,isbn10,5);
    isbn_formatado[5] = '-';
    strncpy(&isbn_formatado[6],&isbn10[5],2);
    isbn_formatado[8] = '-';
    strncpy(&isbn_formatado[9],&isbn10[7],2);
    isbn_formatado[11] = '-';
    strncpy(&isbn_formatado[12],&isbn10[9],1);
}

int validar_isbn_10(char isbn10[]){
    int dv,dv_isbn;

    dv = calcular_dv_isbn_10(isbn10);
    dv_isbn = isbn10[9] - 48;
    if(dv != dv_isbn)return DV;
        else return ISBN_OK;
}

void users_choice_10(char isbn10[]){
    int choice = 0;

    printf("Inserir ISBN-10 [1] Gerar ISBN-10 [2] Padrao [3]- ");
    scanf("%d",&choice);
    if(choice == 1)scanf("%s",isbn10);
    if(choice == 2)gerar_isbn_10(isbn10);
}

void status_isbn10(char isbn10[],char isbn_formatado[]){
    int r;
    r = validar_isbn_10(isbn10);
    r == DV ? printf("\nErro no DV") : 
    formatar_isbn_10(isbn10,isbn_formatado);

    if(r != DV)
        printf("\n[%s] Valido!!",isbn_formatado); 
}

int calcular_dv_isbn_13(char isbn13[]){
    int i,j,dv,soma;
    soma = 0, j = 0;
    
    for(i = 0; i < strlen(isbn13) - 7; i++){
        soma += (isbn13[i + j] - 48) + 3 * (isbn13[i + 1 + j] - 48);
        j++;
        }
    dv = (10 - soma % 10 == 10) ? 0 : 10 - soma % 10;
    return dv;
}

void gerar_isbn_13(char isbn13[]){
    int i;
    for(i = 0; i < 13; i ++)
        isbn13[i] = (rand() % 10 ) + 48;
        isbn13[12] = calcular_dv_isbn_13(isbn13) + 48;
        isbn13[13] = '\0';
}

void formatar_isbn_13(char isbn13[],char isbn_formatado[]){
    strncpy(isbn_formatado,isbn13,3);
    isbn_formatado[3] = '-';
    strncpy(&isbn_formatado[4],&isbn13[3],1);
    isbn_formatado[5] = '-';
    strncpy(&isbn_formatado[6],&isbn13[4],3);
    isbn_formatado[9] = '-';
    strncpy(&isbn_formatado[10],&isbn13[7],5);
    isbn_formatado[15] = '-';
    strncpy(&isbn_formatado[16],&isbn13[12],1);
}

int validar_isbn_13(char isbn13[]){
    int dv,dv_isbn;

    dv = calcular_dv_isbn_13(isbn13);
    dv_isbn = isbn13[12] - 48;
    if(dv != dv_isbn)return DV;
        else return ISBN_OK;
}

void users_choice_13(char isbn13[]){
    int choice = 0;

    printf("\n\nInserir ISBN-13 [1] Gerar ISBN-13 [2] Padrao (qualquer caractere)- ");
    scanf("%d",&choice);
    if(choice == 1)scanf("%s",isbn13);
    if(choice == 2)gerar_isbn_13(isbn13);
}

void status_isbn13(char isbn13[],char isbn_formatado[]){
    int r;
    r = validar_isbn_13(isbn13);
    r == DV ? printf("\nErro no DV") : 
    formatar_isbn_13(isbn13,isbn_formatado);

    if(r != DV)
        printf("\n[%s] Valido!!",isbn_formatado); 
}

void main(){
    
    srand(time(NULL));
    char isbn10[11] = "8573591781";  
    char isbn13[14] = "9786587138350";
    char isbn10_formatado[14] = { 0 };
    char isbn13_formatado[18] = { 0 };    
    
    users_choice_10(isbn10);
    status_isbn10(isbn10,isbn10_formatado);

    users_choice_13(isbn13);
    status_isbn13(isbn13,isbn13_formatado);
}