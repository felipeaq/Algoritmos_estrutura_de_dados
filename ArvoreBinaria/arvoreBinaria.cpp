#include "arvoreBinaria.h"

Nodo::Nodo(int info){
  this->info=info;
  this->dir=NULL;
  this->esq=NULL;

}

Arvore::Arvore(){

  this->raiz=NULL;
  this->quantia=0;
  this->altura=0;
}

int Arvore::insereRecursivo (int info,Nodo* raiz,int altura){

  altura ++;
  if(info<raiz->info){
    if(raiz->esq==NULL){
      raiz->esq = new Nodo(info);
      return altura;
    }
    else
      return Arvore::insereRecursivo(info,raiz->esq,altura);
  }else{
    if(raiz->dir==NULL){
      raiz->dir = new Nodo(info);
      return altura;
    }
    else
      return Arvore::insereRecursivo(info,raiz->dir,altura);
  }
}

void Arvore::destroiRecursivo (Nodo* raiz){

  if(raiz->esq!=NULL)
   Arvore::destroiRecursivo(raiz->esq);
 //std::cout<<raiz->info<<" ";
 if(raiz->dir!=NULL)
   Arvore::destroiRecursivo(raiz->dir);

 delete (raiz);
}

 Nodo* Arvore::buscaRecursivo(int info,Nodo* raiz){
  if(raiz==NULL)
    return NULL;
  if(raiz->info==info)
    return raiz;
  if(info>raiz->info)
    return Arvore::buscaRecursivo( info,raiz->dir);
  return  Arvore::buscaRecursivo( info,raiz->esq);

}

void Arvore::insere(int info){
  int altura=0;
  if(this->raiz==NULL)
    this->raiz=new Nodo(info);
  else
    altura=Arvore::insereRecursivo (info,this->raiz);
  if(this->altura<altura)
    this->altura=altura;
  //std::cout<< this->altura<<" ";
  this->quantia++;
}

void Arvore::destroi(){
  if(this->raiz!=NULL)
    Arvore::destroiRecursivo(this->raiz);
  this->quantia=0;
  this->altura=0;
}

int Arvore::busca (int info){
  Nodo* aux=Arvore::buscaRecursivo(info,this->raiz);
  if (aux==NULL){
    return -1;//melhorar esta parte para futuro uso da estrutura
  }
  return aux->info;
}


void Arvore::iniciaComVec(int quantia){
  srand (time(NULL));
  std::vector<int> v(quantia);
  int aleatorio;
  for (int i=0;i<quantia;i++)
    v[i]=i;
  for (int i=0;i<quantia;i++){
    aleatorio=rand()%quantia;
    std::swap(v[i],v[aleatorio]);

  }
  for (int i=0;i<quantia;i++){
    this->insere(v[i]);

  }

}

/*int main(){
  Arvore arv;
  arv.iniciaComVec(10000);
//  for (int i=0;i<20;i++)
  //  std::cout<<arv.busca(i)<<" ";

  arv.destroi();

  return 0;
}*/
