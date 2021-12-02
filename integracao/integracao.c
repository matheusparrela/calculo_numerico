#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double met_trapezio(int m, double x_0, double x_n);    
double met_simpison_1(int m, double x_0, double x_n);    //intervalos pares
double met_simpison_2(int m, double x_0, double x_n);    //intervalos multiplos de 3
double funcao(double x);
int cria_vetor();
double preenche_vetor(double *vetor, int n);


int main(){

    setlocale(LC_ALL, "Portuguese");

    int menu, n;

    printf("Menu:\n");
    printf("1 - Dado poontos de uma função\n2 - Dada uma função\n0 - Sair\n");
      scanf("%d", &menu);

    while(menu != 0){  
      if(menu == 1){
        
         n = cria_vetor();
            double vetor[n]; 
        preenche_vetor(vetor, n);

        menu = 0;
      }

      if(menu == 2){
        printf("\nMétodos de Integração Numérica\n\n");

        printf("\nTrapézio - I = %.6lf\n",met_trapezio(6, 4, 5.2));
        printf("\nSimpson 1/3 - I = %.6lf\n",met_simpison_1(6, 4, 5.2));
        printf("\nSimpson 3/8 - I = %.6lf\n",met_simpison_2(6, 4, 5.2));
        menu = 0;
      }
    }

    return 0;
}


double funcao(double x){ 

    double resultado;
 
    resultado = log(x); //Funçao dada - Escreva sua função

  return resultado;
}

int cria_vetor(){

  int pontos = 0;

  printf("Insira o número de ponto: ");
      scanf("%d", &pontos);
  
  return pontos;
}


double preenche_vetor(double *vetor, int n){


  printf("Preenchendo os Pontos Y:\n");

  int i = 0;

  for(i = 0; i < n; i++){
    printf("Y[%d] =",i);
      scanf("%lf", &vetor[i]);
  }

  for(i = 0; i < n; i++){
    printf("Y[%d] = %.5lf\n", i, vetor[i]);
  }

  return 0;
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


double met_simpison_1(int m, double x_0, double x_n){ 

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


double met_simpison_2(int m, double x_0, double x_n){ 

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