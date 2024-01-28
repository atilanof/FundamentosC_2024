/*
 * Teoria: Flujos de control
 * Fecha: 25/01/2024
 * Autor: Atilano
 *  
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   /*
    //Pequeño ejemplo de switch con caracteres
    char letra;
    
    printf("\nIntrozuca A y B: ");
    scanf("%c",&letra);
    
    switch(letra) {
        case 'A':
        case 'a':
            printf("\nIntroducido la letra A");
            break;
        case 'B':
        case 'b':
            printf("\nIntroducido la letra B");
            break;
        default:
            printf("\nCaracter no valido");
            break;
    }
    printf("\nGracias por usar software ICAI\n");
    */

    /*
	//Pequeño de switch case
    int numero;
    
    //Leer el numero
    printf("\nIntroduzca un numero del 1 al 10: ");
    scanf("%d",&numero);
    
    //switch case
    switch(numero) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            printf("\nEs numero impar");
            printf("\n");
            break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            printf("\nEs numero par");
            printf("\n");
            break;
        default:
            printf("\nValor no valido");
            break;                   
    }
    printf("\nGracias por usar software ICAI\n");
    */
    /*//Declaración
    int edad; //Almacenar la edad del ciudadano
    char sexo; //Almacena el sexo del ciudadano
    //Pedir el dato al usuario
    printf("\nIndique su sexo (H/M): ");
    scanf("%c",&sexo);
    
    if (sexo=='M' || sexo=='m') {
        printf("\n No tienes la mili por ser mujer\n");
    }
    else if (sexo =='H' || sexo=='h') {
        printf("\nPor favor, introduzca su edad: ");
        scanf("%d",&edad);
        
        //Lógica del programa
        if (edad<18) {
            printf("\nEres demasiado pequeño para hacer la mili");
        }else if (edad>=18 && edad <30) {
            printf("\nDebes servir a la Patria");
        }else{
            printf("\nEstas mayor\n");
        }
    }else {
        printf("\nNo ha introducido un sexo valido\n");
    }*/
    
    //Ejemplo completo de switch case e if
    //Declaración
    int edad; //Almacenar la edad del ciudadano
    char sexo; //Almacena el sexo del ciudadano
    //Pedir el dato al usuario
    printf("\nEdad: ");
    scanf("%d",&edad);
    printf("\nIndique su sexo (H/M): ");
    fflush(stdin);
    //scanf("%c",&sexo);    
    sexo=getchar();
    switch(sexo) {
        case 'M':
        case 'm':
            printf("\n No tienes la mili por ser mujer\n");    
            break;
        case 'H':
        case 'h':
            printf("\nPor favor, introduzca su edad: ");
            scanf("%d",&edad);
            
            //Lógica del programa
            if (edad<18) {
                printf("\nEres demasiado pequeño para hacer la mili");
            }else if (edad>=18 && edad <30) {
                printf("\nDebes servir a la Patria");
            }else{
                printf("\nEstas mayor\n");
            }
            break;
        default:
            printf("\nNo ha introducido un sexo valido\n");
            break;
    }
    printf("\nGracias por usar software ICAI\n");
    
	return 0;
}
