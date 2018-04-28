#ifndef NULL
  #define NULL 0
#endif

#include <vector>
#include <stdlib.h>
#include <time.h>

class Nodo{
public:
  int info;
  Nodo* dir;
  Nodo* esq;
  Nodo(int info);

};

class Arvore{
private:
  Nodo* raiz;
public:
  Arvore();
  void insere (int info);
  void destroi ();
  int busca(int info);
  int quantia;
  int altura;
  void iniciaComVec(int quantia);
  static int insereRecursivo (int info, Nodo* raiz, int altura=0);
  static void destroiRecursivo (Nodo* raiz);
  static Nodo* buscaRecursivo(int info,Nodo* raiz);



};
