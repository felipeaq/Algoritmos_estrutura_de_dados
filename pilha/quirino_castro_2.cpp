#include <iostream>
#include "pilha.h"
#include <sstream> //int (argc[1])


using namespace std;



void empilha(Pilha *pilha,int n){
  for (int i=n;i>0;i--)
    pilha->push(i);



}
void imprime(int t){
  for (int i=0;i<t;i++)
    cout<<"*";

}

void demonstra(int n, Pilha *pilha[]){
  Pilha *aux[3];
  int emparelhamento=n;
  int x=0;
  for (int z=0;z<3;z++)

  x=0;

  for (int j=0;j<3;j++)
    aux[j]=new Pilha();
  while(!pilha[0]->isempty() ||!pilha[1]->isempty()||!pilha[2]->isempty()){
    for (int i=0;i<3;i++){
      if(!pilha[i]->isempty()){
        if(pilha[i]->tamanho>=emparelhamento-1){
        x=pilha[i]->pop();

          imprime(x);
        aux[i]->push(x);
      }

      }
      for (int z=0;z<n+3-x;z++)
        cout<<" ";
      x=0;

    }
    cout<<endl;
    emparelhamento--;
  }
  for (int k=0;k<3;k++){
    while(!aux[k]->isempty()){
      pilha[k]->push(aux[k]->pop());
    }
  }

  for (int j=0;j<3;j++)
    delete(aux[j]);
  cout<<"\n******************************************************************\n";
}
int troca(Pilha * origem, Pilha* destino){

  if  (!origem->isempty()){

    if (!destino->isempty()&&origem->top()>destino->top()){

        cout<<"Voce não pode colocar disco maior em cima de um menor\n";
        return 0;
      }
    destino->push(origem->pop());
    return 1;
  }else{
    cout<<"Voce n pode remover um elemento vazio\n";
    return 0;
  }
}

void joga(Pilha *pilha[],int f,int n){
  int atual,destino;
  int jogadas=0;
  while(pilha[f]->tamanho<n){
    demonstra(n,pilha);
    cout<<"\n\n\n\n";
    cout<<"Digite a posicao de retirada e de destino"<<endl;
    cin>>atual;
    cin>>destino;
    destino--;
    atual--;

    cout<<destino<<endl;
    if (atual>=3||destino>=3||atual<0||destino<0){
      cout<<"pos inválida tente um numero entro 1 e 3\n";
      continue;
    }

    jogadas+=troca(pilha[atual],pilha[destino]);
  }
  demonstra(n,pilha);
  if(pilha[f]->tamanho==n)
    cout<<"Parabéns, seu bosta, voce ganhou com "<<jogadas<<" jogadas!!!\n";
}

int main(int argc, char *argv[]){
  Pilha* pilha[3];
  for (int j=0;j<3;j++)
    pilha[j]=new Pilha();


  int i;
  int f;
  int n;
  if (argc>3){
    istringstream fi(argv[2]);
    istringstream ii(argv[1]);
    istringstream nn(argv[3]);
    if (!(fi >> f) || !(ii>>i) || !(nn>>n)){
      cout<< "argumentos inválidos,exemplo de execução: ./arquivo 1 3 3"<<endl;
      return 1;
    }
    i--;
    f--;
    if (i<0||i>=3||f<0||f>=3){
      cout<< "pos inválida"<<endl;
      return 1;
    }

  }else{
    cout<< "indique os valore de inicio, fim e número de discos: exemplo de execução: ./arquivo 1 3 3"<<endl;
    return 1;
  }
  if(n<3){
    cout<<"numero de discos deve ser maior ou igual a 3"<<endl;
    return 1;
  }

  if(f==i){
    cout<<"posicao inicial tem q ser diferente da final!"<<endl;
    return 1;
  }
  empilha(pilha[i],n);
  joga(pilha,f,n);




  return 0;

}
