class LDF {

public:


  LDF(int quantidade);

  static void expandir(int N);
  static void mostraTudo(LDF *pont);
  static void ciclo(LDF *fila,int N);
  static SuperFila* menorPonteiro;
  static int menor;

private:
  SuperFila* principal;



  LDF* prox;
  int tamanho;




};
