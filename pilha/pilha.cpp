#include "pilha.h"

Elemento_pilha::Elemento_pilha(int info){
  this->info=info;
  this->prox=NULL;
}

Pilha::Pilha(){
  this->cabeca=NULL;
  this->tamanho=0;
}
int Pilha::top(){
  return this->cabeca->info;
}
void Pilha::push(int info){
  if (this->cabeca!=NULL){
    Elemento_pilha* pilha = new Elemento_pilha(info);
    pilha ->prox=this->cabeca;
    this->cabeca=pilha;

  }else
    this->cabeca=new Elemento_pilha(info);
  this->tamanho++;

}
bool Pilha::isempty(){
  return this->cabeca==0;
}
int Pilha::pop(){
  Elemento_pilha* aux=this->cabeca;
  int x=aux->info;
  this->cabeca=this->cabeca->prox;
  delete (aux);
  this->tamanho--;
  return x;
}
