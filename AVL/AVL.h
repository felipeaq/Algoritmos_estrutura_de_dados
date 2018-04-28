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
  int altura;
  Nodo(int info,int altura=0);


};

class AVL{
private:

  static void insereRecursivo (int info, Nodo* &raiz);
  static void destroiRecursivo (Nodo* raiz);
  static Nodo* buscaRecursivo(int info,Nodo* raiz);
  static void RR(Nodo* &raiz);
  static void LL(Nodo* &raiz);
  static void RL(Nodo* &raiz);
  static void LR(Nodo* &raiz);
  Nodo* raiz;
  static Nodo* balanceia(Nodo* &raiz);

public:

  AVL();
  static void buscaOrdRecursivo (Nodo* raiz,int ordem);
  static int get_altura(Nodo* p);
  void insere (int info);
  void destroi ();
  int busca(int info);
  int quantia;
  int altura;
  static int get_fb(Nodo* p);
  void iniciaComVec(int quantia);




};
