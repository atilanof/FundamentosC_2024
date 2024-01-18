#include <stdio.h>

int main(int argc, char **argv)
{
	//Declaro variable
    int edad;
    
    //Solicito información al usuario
    printf("\nIntroduzca la edad: ");
    scanf("%d",&edad);
    //Lógica del programa
    if (edad<18) 
    {
        printf("\nNo puedes entrar a la discoteca");
    }else {
        printf("\nTienes acceso");
    }
    printf("\nGracias por utilizar software ICAI\n");
    
    
    
    /*float a;
    float b;
    int resultado;
    
    a=5.2;
    b=2.8;
    resultado =(int)a%(int)b;
    
    printf("\nEl valor a: %f",a);
    printf("\nEl resto es: %d",resultado);
    */
    
    /*DAR LA VUELTA A UN NUMERO
    int numero;
    int numero_inverso;
    
    numero=125;
    
    numero_inverso=numero%10;
    numero=numero/10;
    
    numero_inverso=numero_inverso*10+numero%10;
    numero=numero/10;
    
    numero_inverso=numero_inverso*10+numero%10;
    numero=numero/10;
      
    
    
    printf("\El numero inmerso %d",numero_inverso);
     */
      
    /*DIVIDENDO DIVISOR
    int a; //Diviendo
    int b;  //Divisor
    
    int x,y;
    
    //Pedido datos al usuario
    printf("\nIntroduzca dividendo: ");
    scanf("%d",&a);
    
    printf("\nIntroduzca divisor: ");
    scanf("%d",&b);
    //Cálculos
    x=a/b;
    y=a%b;
    
    printf("\nEl valor resto: %d",x);
    printf("\nEl valor del modulo: %d",y);
    */
    
    /*
    //Declaración variables
    int edad; //Variable para almacenar la edad
    float altura; //Variable para almacenar la altura en metros
    char sexo; //
    //Lectura de valores
    edad=100;
    altura=1.80;
    sexo='H';    
    
    
    //Mostrar resultados
    printf("Los datos introducidos son:\n");
    printf("\tEdad: %03d\n",edad);
    printf("\tAltura: %5.2f\n",altura);
    printf("\tSexo: %c",sexo);
    
    printf("\nPor favor, introduzca la sexo: ");
    scanf("%c",&sexo);
    printf("\nPor favor, introduzca la edad: ");
    scanf("%d",&edad);
    printf("\nPor favor, introduzca la altura: ");
    scanf("%f",&altura);

    printf("\nLos datos, edad: %d, altura: %5.2f, sexo: %c",edad,altura,sexo);
    
    printf("\n");
    
    
    */
	return 0;
}
