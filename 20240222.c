//Clase de Matrices
//Fecha: 22/02/2024

#include <stdio.h>
#define N 3
#define M 3

void MostrarMatriz (int matriz[][M],int nfilas,int ncolumnas);
int DiagonalPrincipal(int matriz[][M],int nfilas,int ncolumnas);
int DiagonalInversa(int matriz[][M],int nfilas,int ncolumnas);

int main(int argc, char **argv)
{
	int m[N][M];
    int i,j; //Índices para recorrer el vector
    int transpuesta[M][N]; //Matriz transpuesta
    
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("\nIntroduzca la posicion %d,%d: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("\nImprimo la matriz: \n");
    MostrarMatriz(m,N,M);
    
    //Calcular la traspuesta
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            transpuesta[j][i]=m[i][j];
        }
    }
     printf("\nImprimo la transpuesta: \n");
    MostrarMatriz(transpuesta,M,N);
    
    printf("\nLa diagonal principal suma: %d",DiagonalPrincipal(m,N,M));
    printf("\nLa diagonal inversa suma: %d",DiagonalInversa(m,N,M));
	return 0;
}


void MostrarMatriz (int matriz[][M],int nfilas,int ncolumnas) {
    int i,j;
    for (i=0;i<nfilas;i++) {
        printf("| ");
        for (j=0;j<ncolumnas;j++) {
            printf("%2d ",matriz[i][j]);
        }
        printf("|\n");
    }
}

int DiagonalPrincipal(int matriz[][M],int nfilas,int ncolumnas) {
    int i,j;
    int diagonal;
    
    diagonal=0;
     for (i=0;i<nfilas;i++) {        
        for (j=0;j<ncolumnas;j++) {
            if (i==j) {
               diagonal+=matriz[i][j] ;
            }
        }
     }
     return diagonal;
}

int DiagonalInversa(int matriz[][M],int nfilas,int ncolumnas) {
    int i,j;
    int diagonal;
    diagonal=0;
    for (i=0;i<nfilas;i++) {        
        for (j=ncolumnas;j>=0;j--) {
            if (i==j) {
               diagonal+=matriz[i][j] ;
            }
        }
     }
     return diagonal;
    
}