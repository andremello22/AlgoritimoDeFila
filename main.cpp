#include <iostream>
using namespace std;
#define tam 10
struct T_fila {
  int frente;
  int tras;
  int qtd;
  int vetor[tam];
} typedef fila;

int enfileirar(fila *f, int *valor) {
  if (f->qtd == tam) {
    return 0;
  }
  f->vetor[f->tras] = *valor;
  // f->tras++;
  f->tras = f->tras + 1 == tam ? 0 : f->tras + 1;
  f->qtd++;
  return 1;
}
int desenfileirar(fila *f, int *valor) {
  if (f->qtd == 0) {
    return *valor;
  }
  *valor = f->vetor[f->frente];
  // frente++;
  f->frente = f->frente + 1 == tam ? 0 : f->frente + 1;
  f->qtd--;
  return *valor;
}

int main() {
  fila f;
  f.frente = 0;
  f.tras = 0;
  f.qtd = 0;
  int valor = 0;
  for (int i = 0; i < tam; i++) {
    cout << "preencha o elemento " << i << endl;
    cin >> valor;
    enfileirar(&f, &valor);
  }
  cout << "\n------------------------------------" << endl;
  for (int i = 0; i < tam; i++) {
    int valor2;
    valor2 = desenfileirar(&f, &valor2);
    cout << valor2 << endl;
  }
  return 0;
}