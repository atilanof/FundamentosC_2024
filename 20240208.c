/*Tema 4: Funciones
 * 
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>


//Prototipo de mi función. Protipo siempre;
int Func_factorial(int factorial);
int Primo(int num);
void Menu();




int main(int argc, char **argv)
{
	int i;
    int num;
    int resultado;
    int suma;
    char opc;
    
    do {
        Menu();        
        fflush(stdin);
        scanf("%c",&opc);   
        
        switch(opc){
            case 'A':
            case 'a':        
                do {
                    printf("\nIntroduzca un n%cmero: ",163);
                    scanf("%d",&num);
                    if (num<0) {
                        printf("\nN+");
                    }
                }while(num<0);
                
                /*acumulador=1;
                for (i=1;i<=num;i++) {
                    acumulador*=i;   //acumulador=acumulador*i;
                }*/
                resultado=Func_factorial(num);    
                printf("\nEl factorial de %d es %d\n",num, resultado);
                break;
            case 'B':
            case 'b':
                do {
                    printf("\nIntroduzca un n%cmero hasta comprobar si son prims: ",163);
                    scanf("%d",&num);
                    if (num<0) {
                        printf("\nN+");
                    }
                }while(num<0);
                suma=0;
                for(i=1;i<=num;i++) {
                    if (Primo(i)==1) {
                        suma+=i;
                        printf("\n%d: Es primo",i);
                    }else {
                        printf("\n%d: NO es primo",i);
                    }
                }
                break;
            case 'S':
            case 's':
                printf("\nMuchas gracias por utilizar software ICAI");
                break;
            default:
                printf("\nVariable no valida");
                break;
        }
    }while(opc!='S' && opc!='s');
    
	return 0;
}


//Implementación de la funión
/*
    nombre: func_factorial
    parametros:
        * int factorial --> Número en el que quiero calcular el factorai
    retorno
        * int --> devuelve el facotrial del número 

*/
int Func_factorial(int factorial){ //siempre entre llaves
    int i;
    int acumulador;
    
    acumulador=1;
    for (i=1;i<=factorial;i++) {
        acumulador*=i;   //acumulador=acumulador*i;
    }
    return acumulador;
}

int Primo(int num) {
    int i;
    int es_primo;
    
    es_primo=1;
    for (i=2;i<num && es_primo==1;i++) {
        if (num%i==0) {
            es_primo=0;
        }
    }
    return es_primo;
}

void Menu() {
    printf("\nIntroduzca una opcion: ");
    printf("\nA) Factorial: ");
    printf("\nB) Primos: "); 
    printf("\nS) Salir: "); 
    printf("\nIntroduzca un valor"); 
    return;
}