#ifndef NULL
#define NULL 0
#endif

class Elemento_pilha{
public:
  Elemento_pilha(int info);
  Elemento_pilha* prox;
  int info;
};

class Pilha{
  public:
    int tamanho;
    Pilha();
    void push(int info);
    int pop();
    bool isempty();
    int top();
  private:
    Elemento_pilha* cabeca;

};
