#include <stdio.h>

int main(int argc, char **argv)
{
	
    //Declaración de variables
    FILE *pf; //Manejar el buffer del fichero
    float temp, hum; //Variables a utilizar
    //int num_registro; //Número de peticiones al usuario
    int ctrl; //controlar las lectursa
    pf=fopen("C:\\Users\\stic\\Documents\\pr11\\ej1\\Debug\\temp_hum.txt","r");
    if (pf==NULL) {
        printf("\nError al abrir el fichero");
    }else {
        do{
            ctrl=fscanf(pf,"%f %f",&temp,&hum);
            printf("\nEl control es %d: ",ctrl);
            if (ctrl==2) {
                printf("\n%f %f",temp,hum);
            }            
        }while(ctrl==2);
        if (fclose(pf)!=0) {
            printf("\nError al cerrar el fichero");
        }
    }
	return 0;
}
