#include <stdio.h>
#include "neuronio.h"

int main() {
  float entrada[4] = {1, 1, 1, 1};
  float pesos[4] = {2, 2, 2, 2};
  int tamanho = 4;
  float resultado;
    
  resultado = neuronio(entrada, pesos, tamanho);

  printf("Resultado: %f\n", resultado);
  
  return 0;
}
