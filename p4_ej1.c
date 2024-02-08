#include <stdio.h>

double CalculaAlt (double long_tibia, char sexo);

int main(int argc, char **argv)
{
	double tibia;
    char sexo;
    double altura;
    
    do {
        tibia=40; //cm
        if (tibia<0){
            printf("\nMayor que cero");
        }
    }while(tibia<0);
    sexo='H';
    
    altura=CalculaAlt(tibia,sexo); //Parámetros reales
    
    printf("\nLa altura es: %f m",altura);
    
    
	return 0;
}


double CalculaAlt (double long_tibia, char sexo) {
    double resultado;
    if (sexo=='H') {        
        resultado=69.089+2.238*long_tibia;
    }else  if (sexo =='M') {
        resultado = 61.412+2.317*long_tibia;
    }else {
        printf("\nSexo no valido");
    }
    return resultado/100;
}