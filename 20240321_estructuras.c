/*
 * Estructuras
 * 
 * 
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 35


typedef struct {
    char nombre[N];
    int edad;
    float peso;
    float altura;    
}T_PERSONA;

void RellenaPersonas(T_PERSONA vpersonas[], int dim);
void RellenaPersona(T_PERSONA *persona);
void MostrarPersonas(T_PERSONA vpersonas[], int dim);
void MostrarPersona(T_PERSONA persona);
void LimpiarCadena(char cadena[]);

int main(int argc, char **argv)
{
	T_PERSONA *vpersonas;
    int dim;
    
    dim=5;
    
    vpersonas=(T_PERSONA *)calloc(dim,sizeof(T_PERSONA));
    if (vpersonas==NULL) {
        printf("\nError no tengo memoria");
    }else {
        RellenaPersonas(vpersonas,dim);    
        MostrarPersonas(vpersonas, dim);
        free(vpersona);
    }
    /*T_PERSONA persona;
    T_PERSONA clon;
    
    printf("\nBuenos días, introduzca de la nombre de la persona: ");
    fflush(stdin);
    fgets(persona.nombre,N,stdin);
    
    printf("\nIntroduzca el edad: ");
    scanf("%d",&persona.edad);
    
    printf("\nIntroduzca el peso: ");
    scanf("%f",&persona.peso);
    
    printf("\nIntroduzca la altura: ");
    scanf("%f",&persona.altura);
    
    clon=persona;*/
    
	return 0;
}


void RellenaPersonas(T_PERSONA vpersonas[], int dim) {
    int i;
    for (i=0;i<dim;i++) {
        RellenaPersona(&vpersonas[i]);
        //RellenaPersona(vpersonas+i);
    }
}
void RellenaPersona(T_PERSONA *persona){
    
    printf("\nIntroduzca el nombre: ");
    fflush(stdin);
    fgets(persona->nombre,N,stdin);
    LimpiarCadena(persona->nombre);
     printf("\nIntroduzca el edad: ");
    scanf("%d",&persona->edad);
    
    printf("\nIntroduzca el peso: ");
    scanf("%f",&persona->peso);
    
    printf("\nIntroduzca la altura: ");
    scanf("%f",&persona->altura);
}

void LimpiarCadena(char cadena[]) {
    if(cadena[strlen(cadena)-1]=='\n'){
        cadena[strlen(cadena)-1]='\0';
    }
}

void MostrarPersonas(T_PERSONA vpersonas[], int dim) {
    int i;
    
    for (i=0;i<dim;i++) {
        MostrarPersona(vpersona[i]);
    }
}

void MostrarPersona(T_PERSONA persona) {
      printf("\nLa persona tiene los siguientes datos:");
        printf("\n\tNombre: %s",persona.nombre);
        printf("\n\tEdad: %d",persona.edad);
        printf("\n\tPeso: %f",persona.peso);
        printf("\n\tAltura: %f",persona.altura);
}