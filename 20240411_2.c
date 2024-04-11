#include <stdio.h>

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


void LimpiarCaracter(char cadena[]);
int Menu();
void MostrarLibros(FILE *pf);
void MostrarUnLibro(T_LIBRO *libro);
int Buscar_libros_del_Autor(FILE *pf, char *autor);

int main(int argc, char **argv)
{
	//Declaración de variables
    FILE *fp; 
    char autor[A];
    T_LIBRO libro; //Variable para guardar los libros
    int num_libros; //Número de libros
    int i; //iterador
    int opc;
    //Abrir el fichero
    fp=fopen("C:\\Users\\stic\\Documents\\pr11\\20240411\\Debug\\biblioteca.dat","r+b");
    if (fp==NULL) {
        printf("\nError al abrir el fichero");
    }else {
        do {
            opc=Menu();
        
            switch(opc) {
                case 1:
                    MostrarLibros(fp);
                    break;
                case 2:
                    printf("\nPor favor, introduzca el autor a buscar: ");
                    fflush(stdin);
                    fgets(autor,A,stdin);
                    LimpiarCaracter(autor);
                    num_libros=Buscar_libros_del_Autor(fp,autor);
                    printf("\nEl numero de libros de %s es: %d",autor,num_libros);
                case 6:
                    printf("\nGracias por utilizar software ICAI");
                    break;
                default:
                    printf("\nOpcion incorrecta.");
                    break;
            }
        }while(opc!=6);
        
        
        if (fclose(fp)!=0) {
            printf("\nError al cerrar el fichero");
        }
    }
	return 0;
}


void LimpiarCaracter(char cadena[]) {
    if (cadena[strlen(cadena)-1]=='\n'){ 
        cadena[strlen(cadena)-1]='\0';
    }
}

int Menu() {
    int opc;
    printf("\n\tMENU BIBLIOTECA");
    printf("\n\t===============");
    printf("\n1) Mostrar Libros.");
    printf("\n2) Buscar libro.");
    printf("\n3) Buscar último libro.");
    printf("\n4) Actualizar Datos.");
    printf("\n5) Descatalogar.");
    printf("\n6) Salir.");
    printf("\nIntroduzca una opcion: ");
    scanf("%d",&opc);
    
    return opc;
    
}

void MostrarLibros(FILE *pf) {
    rewind(pf); //Me sitio al principio
    int ctrl;
    T_LIBRO libro;
    do {
        ctrl=fread(&libro,sizeof(T_LIBRO),1,pf);
        if (ctrl==1) {
            MostrarUnLibro(&libro);
        }        
    }while(ctrl==1);
    
}


void MostrarUnLibro(T_LIBRO *libro){
    printf("\nLos datos libros son:");
    printf("\n\tTitulo: %s",libro->titulo);
    printf("\n\tAutor: %s",libro->autor);
    printf("\n\tFecha Publicacion: %2d/%2d/%4d",libro->fecha_publicacion.dia,libro->fecha_publicacion.mes,libro->fecha_publicacion.anyo);
}


int Buscar_libros_del_Autor(FILE *pf, char *autor) {
    int num_libros;
    int ctrl;
    int i;
    int libro_autor;
    T_LIBRO libro;
    T_LIBRO libros[100];
    rewind(pf); //Voy al principio del fichero
    num_libros=0;
    do {
        ctrl=fread(&libro,sizeof(T_LIBRO),1,pf);
        if (ctrl==1) {
            num_libros++;
        }        
    }while(ctrl==1);
    //Yo ya se el número de libros que tengo
    rewind(pf); //soy más listo que Atilano
    libro_autor=0;
    do {
        ctrl=fread(libros,sizeof(T_LIBRO),num_libros,pf);
        if (ctrl==num_libros) {
            for (i=0;i<num_libros;i++) {
                if (strcmp(autor,libros[i].autor)==0) {
                    libro_autor++;
                }
            }
        }        
    }while(ctrl==1);
    return libro_autor;
}