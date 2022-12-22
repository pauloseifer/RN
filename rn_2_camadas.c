// 4 camadas, 4 entradas,  4x4x2 neurônios e 2 saídas 

#include <stdio.h>
#include "neuronio.h"

int main() {
  float entrada[4] = {1, 1, 1, 1};
  float pesos[3][4][4] = {{{1, 2, 2, 2}, {2, 1, 2, 2}, {2, 2, 1, 2}, {2, 2, 2, 1}},
			  {{1, 2, 2, 2}, {2, 1, 2, 2}, {2, 2, 1, 2}, {2, 2, 2, 1}},
			  {{2, 1, 2, 2}, {2, 2, 1, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
  int tamanho = 4, n_camadas[3] = {4, 4, 2}, r_camadas[4] = {4, 4, 4, 2};
  float resultado[4][4];
  float b[3][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
  int i, j;

  // Inicializa a variável resultado com 0s
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      resultado[i][j] = 0;
    }
  }

  // Primeiro resultado é a própria entrada
  
  for (i = 0; i < tamanho; i++) resultado[0][i] = entrada[i];

  // Calcula os resultados parciais das camadas
  
  for (i = 0; i < 3; i++) {
    for (j = 0; j < n_camadas[i]; j++) {
      resultado[i+1][j] = neuronio(resultado[i], pesos[i][j], b[i][j], tamanho);
    }
  }

  // Apresenta os resultados por cada camada
  
  printf("\nResultados por camadas:\n");
  for (i = 0; i < 4; i++) {
    printf("Camada %i: ", i);
    for (j = 0; j < r_camadas[i]; j++) {
 	printf("%f ", resultado[i][j]); 
    }
    printf("\n");
  }
   

  
  return 0;
}
