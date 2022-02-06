//Universidade Estadual de Montes Claros
//Engenharia de Sistemas - Análise Numerica
//Matheus Melo Parrela

#include <stdio.h>
#include <stdlib.h>

double funcao(double x, double y);
double temp(double y, double h, double k1, double k2, double k3, double k4);


int main(){

    double x = 0, y = 0, h = 0, k1, k2, k3, k4, i;
    int intevalo_max;

    //Valores iniciais de x, y e h
    x = 0;
    y = 2;
    h = 0.1;
    intevalo_max = 1;


    printf("Valores de y:\n");
    printf("y[%.0lf] = %.0lf\n", x, y);

    //Calcula no intervalo [0, 1]
    for(i = h; i <= intevalo_max; i += h){
        

        k1 = funcao(x, y);
        k2 = funcao(x + h/2, y + (h/2)*k1);
        k3 = funcao(x + (h/2), y + (h/2)*k2);
        k4 = funcao(x + h, y + (h*k3));

        x += h;

        printf("y[%.1lf] = %.6lf\n", x, temp(y, h, k1, k2, k3, k4));

        y = temp(y, h, k1, k2, k3, k4);

    }

    printf("\n");
    return 0;
}

//Calcula os valores de ki
double funcao(double x , double y){

    double resultado = 0;
                    
        resultado = x - y + 2; //Função dada

    return resultado;
}

//Calcula o valor de yj+1;
double temp(double y, double h, double k1, double k2, double k3, double k4){

    double resultado = 0;

        resultado = y + (h/6)*(k1 + 2*k2 + 2*k3 + k4);

    return resultado;
}