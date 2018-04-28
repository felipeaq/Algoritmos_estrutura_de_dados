#ifndef NULL
#define NULL 0
#endif
class Elemento{
public:
  Elemento(int info);
  int info;
  Elemento* prox;
  Elemento* ant;


};

class SuperFila{
public:
  int pop();
  int tamanho;
  void push(int elemento);
  SuperFila();
  bool isempty();
private:
  Elemento *inicio;
  Elemento *fim;

};
