#include <iostream>
#include "AVL.h"
using namespace std;

int main(){
  AVL arv;
  arv.iniciaComVec(1000);
  //arv.insere(1);
  //arv.insere(2);
  //arv.insere(3);
//  for (int i=0;i<20;i++)
  //  std::cout<<arv.busca(i)<<" ";



  //arv.insere(4);

  //AVL::buscaOrdRecursivo(arv.raiz,0);
  //AVL::buscaOrdRecursivo(arv.raiz,2);
  std::cout<<arv.altura<<"\n\n";
  //AVL::buscaOrdRecursivo(arv.raiz,3);
  arv.destroi();

  return 0;
}
