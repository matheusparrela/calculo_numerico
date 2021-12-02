#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double met_trapezio(int m, double x_0, double x_n);    
double met_simpson_1(int m, double x_0, double x_n);    //intervalos pares
double met_simpson_2(int m, double x_0, double x_n);    //intervalos multiplos de 3
double funcao(double x);


int main(){

    setlocale(LC_ALL, "Portuguese");

    printf("\nMétodos de Integração Numérica\n\n");

    printf("\nTrapézio - I = %.6lf\n",met_trapezio(6, 4, 5.2));
    printf("\nSimpson 1/3 - I = %.6lf\n",met_simpson_1(6, 4, 5.2));
    printf("\nSimpson 3/8 - I = %.6lf\n",met_simpson_2(6, 4, 5.2));

    return 0;
}


double funcao(double x){ 

    double resultado;
 
    resultado = log(x); //Funçao dada - Escreva sua função

  return resultado;
}


double met_trapezio(int m, double x_0, double x_n){ 

    double h = 0, resultado = 0 , x = 0;
    int i = 0;

    h = (x_n - x_0) / m;
    x = x_0;  

        for(i = 0; i < m; i++){
            
            resultado = resultado + h/2*(funcao(x) + funcao(x+h));
            x = x + h;
    } 

  return resultado;
}


double met_simpson_1(int m, double x_0, double x_n){ 

    double h = 0, resultado = 0 , x = 0;
    int i = 0;

    h = (x_n - x_0) / m;
    x = x_0; 

    for(i = 0; i < m/2; i++){
            
        resultado = resultado + (h/3)*(funcao(x) + 4*funcao(x+h) + funcao(x + (2*h)));
        x = x+h*2;
    } 

  return resultado;
}


double met_simpson_2(int m, double x_0, double x_n){ 

    double h = 0, resultado = 0 , x = 0;
    int i = 0;

    h = (x_n - x_0) / m;
    x = x_0; 
    
    for(i = 0; i < m/3; i++){
            
        resultado = resultado + ((3*h)/8)*(funcao(x) + 3*funcao(x+h) + 3*funcao(x + (2*h)) + funcao(x +(3*h)));
        x = x+h*3;
    } 

  return resultado;
}