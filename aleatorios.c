#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ITERACIONES 1000000000 // Número de iteraciones para el cálculo
#define RADIO 0.5 // Radio de la circunferencia, la mitad del diámetro

int main() {
    srand(time(NULL)); // Inicializar la semilla aleatoria con el tiempo actual

    int dentroCirculo = 0; // Contador para los puntos dentro del círculo
    int fueraCirculo = 0; // Contador para los puntos fuera del círculo
    for (int i = 0; i < ITERACIONES; i++) {
        // Generar números aleatorios en el rango [0, 1]
        
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
       // printf("Los puntos son: %f,%f",x,y);
        // Comprobar si el punto (x, y) está dentro del círculo
        if (sqrt(x * x + y * y) <= RADIO) {
            dentroCirculo++;
        } else {
            fueraCirculo++;
        }
    }

   

    // Estimar Pi basado en la proporción de áreas
    double piEstimado = 16.0 * (double)dentroCirculo / ITERACIONES;
    

    printf("Número de puntos dentro del círculo: %d\n", dentroCirculo);
    printf("Número de puntos fuera del círculo: %d\n", fueraCirculo);
    //printf("Área estimada del círculo: %f\n", areaCirculo);
    printf("Pi estimado: %f\n", piEstimado);

    return 0;
}
