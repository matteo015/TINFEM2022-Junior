#include <stdio.h>
#include <string.h>

void morse_equivalent(char num[]){
    if(num == '0') printf(" ------ ");
    if(num == '1') printf(" .---- ");
    if(num == '2') printf(" ..--- ");
    if(num == '3') printf(" ...-- ");
    if(num == '4') printf(" ....- ");
    if(num == '5') printf(" ..... ");
    if(num == '6') printf(" -.... ");
    if(num == '7') printf(" --... ");
    if(num == '8') printf(" ---.. ");
    if(num == '9') printf(" ----. ");
    }  

void translate_to_morse(char num[]){
    int i;
    for(i = 0; i < strlen(num); i++){
        morse_equivalent(num[i]);
    }
}
void main(){
    char number[999] = "100";

    printf("Insira um numero: ");
    scanf("%s",number);

    printf("Traducao para morse:");
    translate_to_morse(number);
}