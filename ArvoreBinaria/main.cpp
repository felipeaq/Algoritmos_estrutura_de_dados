#include "arvoreBinaria.h"
#include <iostream>
#include <numeric>
#include "gnuplot_i.hpp"
using namespace std;

void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
    cout << endl << "Press any key to continue..." << endl;

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    _getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    cout << endl << "Press ENTER to continue..." << endl;

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
#endif
    return;
}

pair<float,int> calcula(int quantia){
  srand (time(NULL));
   clock_t t1, t2;
   int altura;
  vector<float> tempos;
    Arvore arv;
  arv.iniciaComVec(quantia);
  for (int i=1;i<1000;i+=10){

    t1=clock();
    for (int j=0;j<i;j++){
      arv.busca(rand()%quantia);

    }
    t2=clock();
    tempos.push_back((float)(t2-t1));
  }
  altura=arv.altura;
  arv.destroi();
  return make_pair(accumulate( tempos.begin(), tempos.end(), 0.0)/tempos.size(),altura);
}
int main(){




  vector<float> media;
  std::vector<int> alturas, iteraco;
  pair <float,int> medidas;

  for (int i=10;i<=10000;i+=10){
    medidas=calcula(i);
    media.push_back(medidas.first);
    alturas.push_back(medidas.second);
    iteraco.push_back(i);
  }


  
  Gnuplot g1("lines");
  Gnuplot g2("lines");

  Gnuplot g1_save("lines");
  Gnuplot g2_save("lines");

  g1.set_grid();
  g1.set_style("lines").plot_xy(iteraco,alturas,"numero de nodos por altura");

  wait_for_key();
  g1.reset_plot();
  //g1.savetops("tempo-altura");
  g1.set_grid();
  g1.set_style("lines").plot_xy(iteraco,media,"numero de nodos por tempo de busca");


  wait_for_key();
  g1.reset_plot();

g1_save.savetops("altura");
  g1_save.set_grid();
  g1_save.set_style("lines").plot_xy(iteraco,alturas,"numero de nodos por altura");


  g1_save.reset_plot();

  g2_save.savetops("tempo");
  g2_save.set_grid();
  g2_save.set_style("lines").plot_xy(iteraco,media,"numero de nodos por tempo");


  g2_save.reset_plot();





  return 0;
}
