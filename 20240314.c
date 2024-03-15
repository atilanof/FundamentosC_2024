//Tema 8: Punteros
//FechaÇ: 14/03/2024
#include <stdio.h>
#define N 50

//void Intercambio(int *x, int *y);

void RellenarVectorMaxMin(float *vector, int dim, float *max, float *min);

int main(int argc, char **argv)
{
    float v[N];
    int dim;
    float max;
    float min;
    
    dim=4;
    RellenarVectorMaxMin(v,dim,&max,&min);
    
    printf("\nEl max y min respectivamente es: %f, %f",max, min);
    
    
    
    
    
    
    /*float v[4];
    int i;
    
    printf("\nEl tamaño de la variable int es: %d",(int)sizeof(int));
    printf("\nEl tamaño de la variable float es: %d",(int)sizeof(double));
    
    for (i=0;i<4;i++) {
        printf("\nEl valor es %d: %f",i,*(v+i));
        
    }
    
    
    /*int a;
    int b;
    a=4;
    b=3;
    printf("\nAntes de la llamada a: %d, b: %d",a,b);
    printf("\nLa dirección de la variable a es: %x",&a);
    printf("\nLa dirección de la variable b es: %x",&b);
    
    Intercambio(&a,&b);
    printf("\nAntes de la llamada a: %d, b: %d",a,b);
    //EJEMPLO BÁSICO E INSERVIBLE DE PUNTEROS
    /*float b;
    float *pb;
    
    b=3.2;
    pb=&b;
    
    printf("\nEl valor de la variable b es: %f",b);
    printf("\nLa dirección de la variable b es: %x",&b);
	
    printf("\nEl valor de la variable pb es: %x",pb);
    printf("\nLa dirección de la variable pb es: %x",&pb);
    printf("\nEl contenido de la dirección de memoria de pb: %f",*pb);
	printf("\nActualizo el valor de B");
    //b=5.4;
    *pb=5.4;
    printf("\nEl valor de la variable b es: %f",b);
    printf("\nLa dirección de la variable b es: %x",&b);
	
    printf("\nEl valor de la variable pb es: %x",pb);
    printf("\nLa dirección de la variable pb es: %x",&pb);
    printf("\nEl contenido de la dirección de memoria de pb: %f",*pb);
    */
    
	return 0;
}
/*
void Intercambio(int *x, int *y) {
    int aux;
    printf("\nLa dirección de la variable x es: %x",&x);
    printf("\nLa dirección de la variable y es: %x",&y);
    
    printf("\nEl valor de la variable x es: %x",x);
    printf("\nEl valor de la variable y es: %x",y);
    
    aux=*x;
    *x=*y;
    *y=aux; 
    
    return;
}*/


void RellenarVectorMaxMin(float *vector, int dim, float *max, float *min) {
    int i;
    
    for (i=0;i<dim;i++) {
        printf("\nIntroduzca el elmento %d: ",i);
        //scanf("%f",&vector[i]);
        scanf("%f",vector+i);
    }
    *max=vector[0];
    *min=vector[0];
    for (i=1;i<dim;i++) {
        if (vector[i]>*max) {
            *max=vector[i];
        }
        if (*(vector+i)<*min) {
            *min=vector[i];
        }
    }
    
}