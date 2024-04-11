#include <stdio.h>

int main(int argc, char **argv)
{
	
    //Declaración de variables
    FILE *pf; //Manejar el buffer del fichero
    float temp, hum; //Variables a utilizar
    int num_registro; //Número de peticiones al usuario
    int i; //Iterador
    pf=fopen("temp_hum.txt","w");
    if (pf==NULL) {
        printf("\nError al abrir el fichero");
    }else {
        printf("\nIntroduzca el num reg: ");
        scanf("%d",&num_registro);
        
        for (i=0;i<num_registro;i++) {
            printf("\nPlease, la temp: ");
            scanf("%f",&temp);
            printf("\nPlease, la hum: ");
            scanf("%f",&hum);
            fprintf(pf,"%.2f %.2f\n" , temp, hum) ;
        }
        if (fclose(pf)!=0) {
            printf("\nError al cerrar el fichero");
        }
    }
	return 0;
}
