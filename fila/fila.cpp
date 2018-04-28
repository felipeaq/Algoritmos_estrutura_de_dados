#include "fila.h"

  Elemento::Elemento(int info){
    this->info =info;
    this->prox=NULL;
  }
    void SuperFila::push(int info){
    Elemento* elemento=new Elemento(info);
    this->tamanho++;
    if(this->fim!=NULL)
      this->fim->prox=elemento;
    else
      this->inicio=elemento;
    elemento->ant=this->fim;
    this->fim=elemento;
  }
    int SuperFila::pop(){
    Elemento *temp=this->inicio;
    int x=temp->info;
    this->inicio=temp->prox;
    if(this->inicio==NULL)
      this->fim=NULL;
    else
      this->inicio->ant=NULL;

    this->tamanho--;
    delete(temp);

    return x;
  }
  bool SuperFila::isempty(){
    return !this->inicio;
  }
  SuperFila::SuperFila(){
    this->tamanho=0;
    this->inicio=NULL;
    this->fim=NULL;
  }
