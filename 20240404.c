#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
typedef struct {
    int mes;
    int anyo;
}T_FECHA;


typedef struct {
    char nombrePlaneta[N];
    float diametro;
    T_FECHA fechaPlaneta;    
}T_PLANETA; 

void LeerPlaneta(T_PLANETA *p);
void GrabarPlaneta(FILE *pf, T_PLANETA p);
void LimpiarCadena(char cadena[]);
int main(int argc, char **argv)
{
	//Declaración variables
    FILE *pf; //Puntero a fichero
    char opc;
    T_PLANETA planeta;
    int ctrl;
    
    //Abro fichero
    pf=fopen("c:\\carpeta1\\carpeta\\planetas.txt","a+");
    if (pf==NULL) {
        printf("\nError, no se ha podido abrir el fichero");
    }else {
        //Trabajar con fichero
        do {
            LeerPlaneta(&planeta);
            GrabarPlaneta(pf,planeta);            
            printf("\n¿Quiere otro planea (S/N)? ");
            fflush(stdin);
            scanf("%c",&opc);
        }while(opc!='N' && opc !='n');
        rewind(pf);
        //Trabajar con fichero
        do{
            ctrl=fscanf(pf,"%s %f %d/%d",planeta.nombrePlaneta,&planeta.diametro,&planeta.fechaPlaneta.mes,&planeta.fechaPlaneta.anyo);
            if (ctrl==4) {
                printf("El planeta es: %s %.2f %d/%d\n",planeta.nombrePlaneta,planeta.diametro,planeta.fechaPlaneta.mes,planeta.fechaPlaneta.anyo);
            }                          
        }while(ctrl==4);
        if (fclose(pf)!=0) {
            printf("\nNo se ha podido cerrar el fichero");
        }  
    }
    
    
    /*
     //Abro fichero
    pf=fopen("planetas.txt","w");
    if (pf==NULL) {
        printf("\nError, no se ha podido abrir el fichero");
    }else {
        //Trabajar con fichero
        do {
            LeerPlaneta(&planeta);
            GrabarPlaneta(pf,planeta);            
            printf("\n¿Quiere otro planea (S/N)? ");
            fflush(stdin);
            scanf("%c",&opc);
        }while(opc!='N' && opc !='n');
        if (fclose(pf)!=0) {
            printf("\nNo se ha podido cerrar el fichero");
        }  
        //Abro el fichero lectura
        pf=fopen("planetas.txt","r");
        if (pf==NULL) {
            printf("\nError, no se ha podido abrir el fichero");
        }else {
            //Trabajar con fichero
            do{
                ctrl=fscanf(pf,"%s %f %d/%d",planeta.nombrePlaneta,&planeta.diametro,&planeta.fechaPlaneta.mes,&planeta.fechaPlaneta.anyo);
                if (ctrl==4) {
                    printf("El planeta es: %s %.2f %d/%d\n",planeta.nombrePlaneta,planeta.diametro,planeta.fechaPlaneta.mes,planeta.fechaPlaneta.anyo);
                }                
            }while(ctrl==4);
            if (fclose(pf)!=0) {
                printf("\nNo se ha podido cerrar el fichero");
            }  
        }*/
	return 0;
}


void LeerPlaneta(T_PLANETA *p) {
    printf("\nIntroduzca el nombre: ");
    fflush(stdin);
    fgets(p->nombrePlaneta,N,stdin);
    LimpiarCadena(p->nombrePlaneta);
    printf("\nIntroduzca el diametro: ");
    scanf("%f",&p->diametro);
    printf("Introduzca mes/fecha del creación del planeta: ");
    scanf("%d/%d",&p->fechaPlaneta.mes,&p->fechaPlaneta.anyo);
    
    return;
}

void LimpiarCadena(char cadena[]) {
    if (cadena[strlen(cadena)-1]=='\n'){
        cadena[strlen(cadena)-1]='\0';
    }
    return;
}

void GrabarPlaneta(FILE *pf, T_PLANETA p) {
    printf("%s %.2f %d/%d\n",p.nombrePlaneta,p.diametro,p.fechaPlaneta.mes,p.fechaPlaneta.anyo);
    fprintf(pf,"%s %.2f %d/%d\n",p.nombrePlaneta,p.diametro,p.fechaPlaneta.mes,p.fechaPlaneta.anyo);
    
    return;
}