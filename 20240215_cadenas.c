#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 11 //Porqué quiero 20 +1 del \0
int main(int argc, char **argv)
{
    char cadena[N];
    char nombre[N]={'J','u','a','n','\0'};
    int i;
    int num_a;
    //Primera forma
    /*printf("\nIntroduzca una cadena: ");
    scanf("%s",cadena);
    //OJO sólo lee hasta el primer espacio
    printf("\nLa cadena es: %s",cadena);*/
	
    //Segunda forma
    /*printf("\nIntroduzca la cadena: ");
    gets(cadena);
    printf("\nLa cadena es: %s\n",cadena);
    //The problem is...No asegura el \0
    */
    //Tercera forma (la buena)
    printf("\nIntroduzca la cadena: ");
    fflush(stdin);
    fgets(cadena,N,stdin);
    printf("\nLa cadena es: %s y con longitud %d\n",cadena,strlen(cadena));
    if (cadena[strlen(cadena)-1]=='\n') {
        cadena[strlen(cadena)-1]='\0';        
    }
    printf("\nLa cadena es: %s y con longitud %d\n",cadena,strlen(cadena));
    if (strcmp(cadena,nombre)==0){
        printf("Cadenas iguales");
    }else {
        printf("Cadena desiguales");
    }
    strcpy(nombre,cadena);
    printf("\nLa cadena es: %s y con longitud %d\n",nombre,strlen(nombre));
    if (strcmp(cadena,nombre)==0){
        printf("Cadenas iguales");
    }else {
        printf("Cadena desiguales");
    }
    
    num_a=0;
    for (i=0;i<strlen(cadena);i++) { //cadena[i]!='\0'
        if (cadena[i]=='a') {
            num_a++;
        }
    }
    printf("\nEl numero de aes es: %d",num_a);
    
    //Para mostrar una cadena
    //puts(cadena);
	return 0;
}
