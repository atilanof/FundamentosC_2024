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
T_LIBRO Buscar_Ultimo_Libro(FILE *pf);
int Actualizar_datos(FILE *pf, T_LIBRO libro);
void Rellenar_Un_libro(T_LIBRO *libro);
int BuscarAntiguo (FILE * fp, T_LIBRO *antiguo);
void Descatalogar(FILE *fp,int pos);

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
    fp=fopen("/tmp/biblioteca.dat","r+b");
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
                    break;
                case 3:
                    libro=Buscar_Ultimo_Libro(fp);
                    printf("El libro mas nuevo en mi catalogo es: ");
                    MostrarUnLibro(&libro);
                    break;
                case 4:
                    printf("\nIntroduzca el libro actualizar: ");
                    Rellenar_Un_libro(&libro);
                    i=Actualizar_datos(fp,libro);
                    if (i==1) {
                        printf("\nLibro Actualizado");
                    }else {
                        printf("\nLibro No encontrado");
                    }
                    break;
                case 5:
                    i=BuscarAntiguo(fp,&libro);                    
                    if (i!=-1) {//Hay libros a descatalogar
                        printf("\nEl libro que se va a descatalogar es: ");
                        MostrarUnLibro(&libro);
                        Descatalogar(fp,i);
                    }
                    break;
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
            if(libro.fecha_publicacion.dia!=0 && libro.fecha_publicacion.mes!=0 && libro.fecha_publicacion.anyo!=0) {
                MostrarUnLibro(&libro);
            }           
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
    
    ctrl=fread(libros,sizeof(T_LIBRO),num_libros,pf);
    if (ctrl==num_libros) {
        for (i=0;i<num_libros;i++) {
            if (strcmp(autor,libros[i].autor)==0) {
                libro_autor++;
            }
        }
    }
    
    return libro_autor;
}


T_LIBRO Buscar_Ultimo_Libro(FILE *pf) {
    T_LIBRO libro;
    T_LIBRO libro_ultimo;
    rewind(pf); //Cursor al principio del fichero
    int fecha_ultima;
    int ctrl;    
    fecha_ultima=0;
    do {
        ctrl=fread(&libro,sizeof(T_LIBRO),1,pf);
        if (ctrl==1) {
            //Encuentro un libro más nuevo
            if (libro.fecha_publicacion.anyo*10000+libro.fecha_publicacion.mes*100+libro.fecha_publicacion.dia>fecha_ultima) {
                libro_ultimo=libro;
                fecha_ultima=libro.fecha_publicacion.anyo*10000+libro.fecha_publicacion.mes*100+libro.fecha_publicacion.dia;
            }
        }        
    }while(ctrl==1);
    return libro_ultimo;
    
}


int Actualizar_datos(FILE *pf, T_LIBRO libro)  {
   /* int ctrl;
    int encontrado;
    //int pos;
    T_LIBRO libro_fichero;
        
    rewind(pf);
    encontrado=0;
    do {
        ctrl=fread(&libro_fichero,sizeof(T_LIBRO),1,pf);
        if (ctrl==1) {
            if (strcmp(libro_fichero.titulo,libro.titulo)==0) {
                encontrado=1;
                //Actualizarlo                
                fseek(pf,(long)(-1*sizeof(T_LIBRO)),SEEK_CUR);
                fwrite(&libro,sizeof(T_LIBRO),1,pf);
            }
        }        
    }while(ctrl==1 && encontrado==0);
    return encontrado;
     */
    int ctrl;
    int encontrado;
    int pos;
    int i;
    T_LIBRO libro_fichero;
        
    rewind(pf);
    encontrado=0;
    pos=0;
    i=0;
    do {
        ctrl=fread(&libro_fichero,sizeof(T_LIBRO),1,pf);
        if (ctrl==1) {
            if (strcmp(libro_fichero.titulo,libro.titulo)==0) {
                encontrado=1;                
                pos=i;
            }
            i++;
        }        
    }while(ctrl==1 && encontrado==0);
    
    if (encontrado==1) {
        fseek(pf,(long)(pos*sizeof(T_LIBRO)),SEEK_SET);
        fwrite(&libro,sizeof(T_LIBRO),1,pf);
    }
    
    return encontrado; 
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


int BuscarAntiguo (FILE * fp, T_LIBRO *antiguo) {
    T_LIBRO libro;
    
    rewind(fp); //Cursor al principio del fichero
    int fecha_ultima;
    int ctrl;    
    int i;
    int pos;
    
    i=0;
    pos=-1;
    fecha_ultima=30000000;
    do {
        ctrl=fread(&libro,sizeof(T_LIBRO),1,fp);
        if (ctrl==1) {
            //Encuentro un libro más nuevo
            if (libro.fecha_publicacion.anyo!=0 && libro.fecha_publicacion.anyo*10000+libro.fecha_publicacion.mes*100+libro.fecha_publicacion.dia<fecha_ultima) {
                pos=i;
                (*antiguo)=libro;
                fecha_ultima=libro.fecha_publicacion.anyo*10000+libro.fecha_publicacion.mes*100+libro.fecha_publicacion.dia;
            }
            i++;
        }        
    }while(ctrl==1);
    
    return pos;
}

void Descatalogar(FILE *fp,int pos) {
    T_LIBRO libro;
    int ctrl;
    fseek(fp,pos*sizeof(T_LIBRO),SEEK_SET);
    ctrl=fread(&libro,sizeof(T_LIBRO),1,fp);
    if (ctrl==1) {
        libro.fecha_publicacion.dia=0;
        libro.fecha_publicacion.mes=0;
        libro.fecha_publicacion.anyo=0;
        fseek(fp,pos*sizeof(T_LIBRO),SEEK_SET);
        //fseek(fo;-1*sizeof(T_LIBRO),SEEK_CUR);        
        fwrite(&libro,sizeof(T_LIBRO),1,fp);    
    }
}
