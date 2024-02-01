/*
 * Clase de bucles (for / while / do-while)
 * Fecha: 01/02/2024
 * Autor: Atilano Fernández-Pacheco Sánchez-Migallón
 * 
 */ 
#include <stdio.h>

int main(int argc, char **argv)
{
	//int copas_europa; //Variable para iterar
    
    /*for (copas_europa=1;copas_europa<=0;copas_europa) {
        if (copas_europa<14) {
            printf("\nEl Real Madrid no tiene %d",copas_europa);
        }else {
            printf("\nEl Real Madrid si tiene %d",copas_europa);
        }
    }*/
    /*for (;;) {
        printf("\n¿Está bien?");
    }*/
    //Mostrar pares
    /*int i;
    for (i=0;i<=10;i++) {
        if (i%2==0){
            printf("\nEl numero par es: %d",i);        
        }
    }*/
    /* int i;
    for (i=1;i<=10;i=i*2) {
        printf("\nEl numero par es: %d",i);                
    }
    printf("\n");
    */
    //for con varios elementos
    /*int i,j;
    for (i=0,j=10; i<=10 && j>=-2; i++,j--) {
        printf("\n%d,%d",i,j);
    }
    */
    //for hasta el valor de una variable
    /*int i;
    int num;
    printf("\nPor favor, introduzca hasta que n%cmero quiere avanzar: ",163);
    scanf("%d", &num);
    
    for (i=0;i<=num;i++) {
        printf("\nVoy subiendo: %d",i);
    }*/
    //Do-while de validación
    /*int edad;
    do {
        printf("\nIntroduzca la edad: ");
        scanf("%d", &edad);
        if (edad<0) {
            printf("\nEdad no valida");
        }
    }while (edad<0);*/
    //Validación de número entre 1y
    /*int num;
    do{
        printf("\nIntroduzca un n%cmero entre [0,50]",163);
        scanf("%d", &num);
        if (num<0 || num>50) {
            printf("\nDebe ser entre [0,50]");
        }
    }while(num<0 || num>50);*/
    
    //Ejemplo de while que pide números hasta que salga tenga media suspensa o decida salir
    /*int num;
    char salir;
    int acumulador;
    int num_notas;
    float media;
   
    
    printf("\nIntroduzca una nota: ");
    scanf("%d", &num);
    acumulador=num;
    num_notas=1;
    media=acumulador/num_notas;
    while (media>=5 && salir!='N' && salir !='n') {
        printf("\nIntroduzca una nota: ");
        scanf("%d", &num);
        acumulador+=num;
        num_notas++;
        media=(float)acumulador/(num_notas);
        printf("\nLa nota media que lleva: %.2f", media);
        printf("\n¿Quiere introducir otra nota? ");
        setbuf(stdin,NULL);
        scanf("%c", &salir);
    }
    
    */
    
    
    //Ejemplo de convesión de for y do/while
    int i, num;
    do {
        printf("\nIntroduzca el numero: ");
        scanf("%d", &num);
        if (num<0) {
            printf("\nNumero >0");
        }
    }while(num<0);
    
    for (i=0;i<num;i++) {
        printf("\n%d",i);
    }
    
    i=0;
    while(i<num) {
        printf("\n%d",i);
        i++;        
    }
    
    printf("\n");
    
	return 0;
}