#include <iostream>
#include "fila.h"
#include "LDF.h"
#include <stdlib.h>  //srand()
#include <sstream> //int (argc[1])

using namespace std;

SuperFila* LDF::menorPonteiro;
LDF::LDF(int quantidade){
  //instancia recursivamente uma lista encadeada
  this->tamanho=0;
  this->principal = new SuperFila();
  if (quantidade>1)
  this->prox=new LDF(quantidade-1);
  else
  this->prox=NULL;

}



void LDF::expandir(int N){
  if(rand()%100>(100-N))
  LDF::menorPonteiro->push((rand()%11)+5);
}
void  LDF::mostraTudo(LDF *fila){

  SuperFila *aux = new SuperFila();
  int x;
  //percorre todos elementos da lista de filas
  while(fila!=NULL){
    cout<<"D ";


    //tira da fila o primeiro e diminui 1
    if(!fila->principal->isempty()){
      x=fila->principal->pop()-1;
      cout<<"<"<<hex<<x<<" ";
      if (x!=0)
      aux->push(x);

    }

    //desenfila  tudo pra n quebrar a estrutura de fila
    while (!fila->principal->isempty()){
      x=fila->principal->pop();
      cout<<"<"<<hex<<x<<" ";
      aux->push(x);
    }
    //coloca tudo na fila de novo
    while (!aux->isempty()){
      fila->principal->push(aux->pop());
    }
    cout<<endl;
    //guarda ponteiro pra menor elemente e envita ter q percorrer novamente
    if(fila->menorPonteiro->tamanho>fila->principal->tamanho)
    LDF::menorPonteiro=fila->principal;
    fila=fila->prox;
  }

  delete(aux);
}
void LDF::ciclo(LDF *fila,int N=10){
  string x;

  //incia menor ponteriro no primeiro elemento (já que todos tem tamanho zero)
  LDF::menorPonteiro=fila->principal;


  do{
    LDF::expandir(N);
    LDF::mostraTudo(fila);

    cout<<"Digite algo para continuar ou EOF (CTRL+D) para encerrar: ";
  }while(cin>>x);

}


int main(int argc, char *argv[]){


  int x;
  int N;
  //pega numero de caixas se numero de argumentos>1 e caso tenha algum erro define como 5
  if (argc>1){
    istringstream tamanho(argv[1]);
    if (!(tamanho >> x))
      x=5;

  }else
    x=5;
  //define a probabilidade de entrar alguem no caixa. Caso tenha algo errado ele define como 10
  if (argc>2){
    istringstream probabilidade(argv[2]);
    if (!(probabilidade >> N))
      N=10;

  }else
    N=10;



  srand(time(NULL));
  LDF *ldf =new LDF(x);
  LDF::ciclo(ldf,N);

  cout<<endl;

  return 0;
}
