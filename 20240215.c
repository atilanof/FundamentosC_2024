/* Vectores
 * Fecha: 15/02/2024
 * Autor: Atilano
 * */

#include <stdio.h>
#define N 5

//Prototipo
void LeerVector(float vector[],int dim);
void MostrarVector(float vector[],int dim);
float Media(float vector[], int dim);
float NotaMaxima(float vector[], int dim);

int main(int argc, char **argv)
{
    float notas[100];
    int dim;
    int i;
    float media_notas;
    
    do {
        printf("\nIntroduzca el numero de alumnos: ");
        scanf("%d",&dim);
        if (dim<=0 || dim>100) {
            printf("\nEl numero de alumnos [1,100]");
        }
    }while(dim<=0 || dim>100);
    //Pido las notas
    LeerVector(notas, dim);
    MostrarVector(notas, dim);

    //Calcular la media    
    media_notas=Media(notas,dim);
    printf("\nLa nota media es: %.2f\n",media_notas);
    //Declaración de variables
    /*int vector[N]={1,10,15,20,25};
    int i;
    
    for (i=0;i<N;i++) {
        printf("\nIntroduzca el valor: ");
        scanf("%d",&vector[i]);
    }
    
    for (i=0;i<N;i++) {
        printf("\nEl elemento %d es: %d",i,vector[N]);        
    }
    printf("\n");
      */ 
    /*
	return 0;
}


void LeerVector(float vector[],int dim){
    int i;
    for (i=0;i<dim; i++) {
        printf("\nIntroduzca la nota: ");
        scanf("%f",&vector[i]);
    }
    return;
}

void MostrarVector(float vector[],int dim) {
    int i;
    for (i=0;i<dim; i++) {
        printf("\nLa nota del alumno %d es %f: ",i,vector[i]);
        
    }
    return;
}

float Media(float vector[], int dim) {
    int i;
    float media;
    media=0;
    for (i=0;i<dim; i++) {
        media+=vector[i]; //media=media+notas[i];
    }
    media=media/dim;
    return media;
}

float NotaMaxima(float vector[], int dim){
    float maxima;
    int i;
    maxima=vector[0];
    for (i=1;i<dim;i++) {
        if (vector[i]>maxima) {
            maxima=vector[i];
        }
    }   
    return maxima;
}