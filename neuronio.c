#include <math.h>
#include "neuronio.h"

float neuronio(float *e, float *w, int tamanho) {
  int i;
  float resultado = 0;
    
  for (i = 0; i < tamanho; i++) {
    resultado += e[i]*w[i];
  }
  return 1/(1 + exp(-resultado));

}
