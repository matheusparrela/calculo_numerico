#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//Sendo m o numero de intervalos, x_0 e x_n o intervalo. 

double met_trapezio(int m, double x_0, double x_n);
double funcao(double x);  //Dada uma funçao 


int main(){

    printf("\nI = %.5lf\n", met_trapezio(6, 4, 5.2));

    return 0; 
}

double met_trapezio(int m, double x_0, double x_n){ 

    double h = 0, resultado = 0 , x = 0;
    int i = 0;

    h = (x_n - x_0) / m;
    x = x_0; 

    resultado = funcao(x_0); 

        for(i=1; i < m; i++){
            x = x + h;
            resultado = resultado + 2*funcao(x);
    } 

    resultado = funcao(x_n) + resultado;
    resultado = (h/2) * resultado;

return resultado;
}


double funcao(double x){ 

    double resultado;
 
    resultado = log(x); //Funçao dada 

return resultado;
}