#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 50
#define A 30

typedef struct {
    int dia;
    int mes;
    int anyo;
}T_FECHA;

typedef struct {
    char titulo[T];
    char autor[A];
    T_FECHA fecha_publicacion;
    
}T_LIBRO;

void Rellenar_Un_libro(T_LIBRO *libro);
void LimpiarCaracter(char cadena[]);
int main(int argc, char **argv)
{
	//Declaración de variables
    FILE *fp; 
    T_LIBRO libro; //Variable para guardar los libros
    int num_libros; //Número de libros
    int i; //iterador
    //Abrir el fichero
    fp=fopen("/tmp/biblioteca.dat","wb");
    if (fp==NULL) {
        printf("\nError al abrir el fichero");
    }else {
        printf("\nIntroduzca el número de libros: ");
        scanf("%d",&num_libros);
        for(i=0;i<num_libros;i++) {
            Rellenar_Un_libro(&libro);
            fwrite(&libro,sizeof(T_LIBRO),1,fp);
        }
        if (fclose(fp)!=0) {
            printf("\nError al cerrar el fichero");
        }
    }
	return 0;
}


void Rellenar_Un_libro(T_LIBRO *libro) {
    printf("\nIntroduzca el titulo: ");
    fflush(stdin);
    fgets(libro->titulo,T,stdin);
    LimpiarCaracter(libro->titulo);
    printf("\nIntroduzca el autor: ");
    fflush(stdin);
    fgets(libro->autor,A,stdin);
    LimpiarCaracter(libro->autor);
    printf("\nIntroduza la fecha de publicación: ");
    scanf("%d/%d/%d",&libro->fecha_publicacion.dia,&libro->fecha_publicacion.mes,&libro->fecha_publicacion.anyo);
    
}

void LimpiarCaracter(char cadena[]) {
    if (cadena[strlen(cadena)-1]=='\n'){ 
        cadena[strlen(cadena)-1]='\0';
    }
}
