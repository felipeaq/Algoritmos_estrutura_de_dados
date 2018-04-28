#include "AVL.h"
#include <iostream>
Nodo::Nodo(int info,int altura){
  this->info=info;
  this->dir=NULL;
  this->esq=NULL;
  this->altura =altura;

}


AVL::AVL(){

  this->raiz=NULL;
  this->quantia=0;
  this->altura=0;
}

int AVL::get_fb(Nodo* p){
  int ae,ad;
  if(p==NULL)
    return 0;

  ae=get_altura(p->esq);
  ad=get_altura(p->dir);
  return ae-ad;

}


void AVL::RR(Nodo* &raiz){
  Nodo *nodo = raiz->dir;

  raiz->dir=nodo->esq;
  nodo->esq=raiz;
  raiz->altura= std::max(get_altura(raiz->esq),get_altura(raiz->dir))+1;
  nodo->altura= std::max(get_altura(nodo->esq),raiz->altura)+1;

  raiz=nodo;



}

void AVL::LL(Nodo* &raiz){

  Nodo* nodo=raiz->esq;
  raiz->esq=nodo->dir;
  nodo->dir=raiz;
  raiz->altura= std::max(get_altura(raiz->esq),get_altura(raiz->dir))+1;
  nodo->altura= std::max(get_altura(nodo->dir),raiz->altura)+1;
  raiz=nodo;



}

void AVL::LR(Nodo* &p){

  AVL::RR(p->esq);
  AVL::LL(p);


}

void AVL::RL(Nodo* &p){

  AVL::LL(p->dir);
  AVL::RR(p);
}


int AVL::get_altura(Nodo*raiz){
  if(raiz==NULL)
    return -1;
  return raiz->altura;
}
void AVL::insereRecursivo (int info,Nodo* &raiz){


  if(info<raiz->info){
    if(raiz->esq==NULL){
      raiz->esq = new Nodo(info);


    }
    else
      AVL::insereRecursivo(info,raiz->esq);
  }else{
    if(raiz->dir==NULL){
      raiz->dir = new Nodo(info);



    }
    else
      AVL::insereRecursivo(info,raiz->dir);
  }
  balanceia(raiz);

}


Nodo* AVL::balanceia(Nodo* &raiz){
  raiz->altura= std::max(get_altura(raiz->esq),get_altura(raiz->dir))+1;

    int fb=get_fb(raiz);


    if(fb>=2){

      if(get_fb(raiz->esq)>=0)
        AVL::LL(raiz);
      else
      AVL::LR(raiz);

    }
    else if(fb<=-2){

      if(get_fb(raiz->dir)<=0){

        AVL::RR(raiz);


      }
      else
        AVL::RL(raiz);

    }

    raiz->altura= std::max(get_altura(raiz->esq),get_altura(raiz->dir))+1;
    return raiz;
}

void AVL::destroiRecursivo (Nodo* raiz){

  if(raiz->esq!=NULL)
   AVL::destroiRecursivo(raiz->esq);

 if(raiz->dir!=NULL)
   AVL::destroiRecursivo(raiz->dir);

 delete (raiz);
}



 Nodo* AVL::buscaRecursivo(int info,Nodo* raiz){
  if(raiz==NULL)
    return NULL;
  if(raiz->info==info)
    return raiz;
  if(info>raiz->info)
    return AVL::buscaRecursivo( info,raiz->dir);
  return  AVL::buscaRecursivo( info,raiz->esq);

}

void AVL::insere(int info){

  if(this->raiz==NULL)
    this->raiz=new Nodo(info);
  else
    AVL::insereRecursivo (info,this->raiz);



  this->altura=this->raiz->altura;


  this->quantia++;
}

void AVL::destroi(){
  if(this->raiz!=NULL)
    AVL::destroiRecursivo(this->raiz);
  this->quantia=0;
  this->altura=0;
}

int AVL::busca (int info){
  Nodo* aux=AVL::buscaRecursivo(info,this->raiz);
  if (aux==NULL){
    return -1;//melhorar esta parte para futuro uso da estrutura
  }
  return aux->info;
}


void AVL::iniciaComVec(int quantia){
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


void AVL::buscaOrdRecursivo (Nodo* raiz,int ordem){

  if (ordem==2){
    std::cout<<get_fb(raiz)<<" ";
  }
  if(ordem==-1)
    std::cout<<raiz->info<<" ";
  if(raiz->esq!=NULL){
   AVL::buscaOrdRecursivo ( raiz->esq, ordem);
 }

   if(ordem==0)
     std::cout<<raiz->info<<" ";

 if(raiz->dir!=NULL){
   AVL::buscaOrdRecursivo ( raiz->dir, ordem);
 }

   if(ordem==1)
     std::cout<<raiz->info<<" ";

    if (ordem==3){
      std::cout<<raiz->altura<<" ";
    }

}
