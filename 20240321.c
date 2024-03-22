/*
 * Tema: Memoria dinámica
 * Fecha:21/03/2024 
 * 
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *v;
    int dim;
    int i;
    
    printf("\nIntroduzca la dimension: ");
    scanf("%d",&dim);
    
    //Pedir memoria
    v=(int *)calloc(dim,sizeof(int));
    if (v==NULL) {
        printf("\nError, no hay memoria");
    }else {
        //Opero con el vector
        for(i=0;i<dim;i++) {
            printf("\nIntroduzca el elemento %d: ",i);
            scanf("%d",&v[i]);
        }
        printf("\nEl vector es: ");
        for(i=0;i<dim;i++) {
            printf("\nEl elemento %d es: %d",i,v[i]);            
        }
        
        
        free(v);
    }
    
	return 0;
}
