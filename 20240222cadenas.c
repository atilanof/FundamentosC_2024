//Matrices de cadena

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_ALUMNOS 100
#define TAM_NOMBRE 50
#define NUM_ASIGNATURAS 10

void QuitarRetornoCarro(char cadena[]);
float CalcularNotamedia(float notas[], int num_asignaturas);
int CalcularMejorAlumnoAsignatura(float notas[][NUM_ASIGNATURAS],int num_alumnos,int asignatura);



int main(int argc, char **argv)
{
	char nombre_alumnos[NUM_ALUMNOS][TAM_NOMBRE];
    float notas_alumnos[NUM_ALUMNOS][NUM_ASIGNATURAS];
    int num_alumnos;
    int num_asignaturas;
    int i,j;
    int asignatura;
    float media_notas;
    int indice_mejor_alumno;
    
    //do-while >0 y <100
    num_alumnos=3;
    num_asignaturas=3;
    
    for (i=0;i<num_alumnos;i++) {
        printf("\nIntroduzca el nombre de alumnos, por favor: ");
        fflush(stdin);
        fgets(nombre_alumnos[i],TAM_NOMBRE,stdin);
        QuitarRetornoCarro(nombre_alumnos[i]);
    }
    
    for (i=0;i<num_alumnos;i++) {
        printf("\nEl nombre del alumno %d es %s: ",i,nombre_alumnos[i]);
    }
    
     for (i=0;i<num_alumnos;i++) {
         printf("\nIntroduzca las notas del alumno %s: ",nombre_alumnos[i]);
         for (j=0;j<num_asignaturas;j++) {
             printf("\n\tIntroduzca la asigntura %d: ",j);
             scanf("%f",&notas_alumnos[i][j]);             
         }
     }
     
     for (i=0;i<num_alumnos;i++) {
         media_notas=CalcularNotamedia(notas_alumnos[i],num_asignaturas);
         printf("\nLa nota media del alumno %s es %f",nombre_alumnos[i],media_notas);
     }
     
     printf("\nIntroduzca el indice de la asignatura: ");
     scanf("%d",&asignatura);
     
     indice_mejor_alumno=CalcularMejorAlumnoAsignatura(notas_alumnos,num_alumnos,asignatura);
     printf("\nEl alumno con mejor nota en la asignatura %d es %s",asignatura,nombre_alumnos[indice_mejor_alumno]);
    
    
    
    
    
	return 0;
}


void QuitarRetornoCarro(char cadena[]) {
    if(cadena[strlen(cadena)-1]=='\n') {
        cadena[strlen(cadena)-1]='\0';
    }
}

float CalcularNotamedia(float notas[], int num_asignaturas) {
    int i;
    float media;
    media=0;
    for (i=0;i<num_asignaturas;i++) {
        media+=notas[i];
    }
    return media/num_asignaturas;
}

int CalcularMejorAlumnoAsignatura(float notas[][NUM_ASIGNATURAS],int num_alumnos,int asignatura) {
    int i;
    int mejor_alumno;
    float max_nota;
    
    max_nota=notas[0][asignatura];
    mejor_alumno=0;
    for (i=0;i<num_alumnos;i++) {
        if(notas[i][asignatura]>max_nota) {
            max_nota=notas[i][asignatura];
            mejor_alumno=i;
        }
    }
    return mejor_alumno;
    
    
}