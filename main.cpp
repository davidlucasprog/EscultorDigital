#include <iostream>
#include <cstdlib>
#include "Sculptor.h"
#include <fstream>
#include <string>

int main()
{
    Sculptor desenho(26, 33, 26);
    //Caixa que forma a parte do tronco
    desenho.setColor(1.0, 0.0, 0.0, 1.0);
    desenho.putBox(4, 20, 0, 6, 4, 20);
    //Cortes do lado direito do tronco
    desenho.cutBox(4, 5, 4, 6, 4, 20);
    desenho.cutBox(4, 4, 3, 3, 4, 20);
    desenho.cutBox(6, 6, 5, 5, 4, 20);
    desenho.cutBox(6, 7, 6, 6, 4, 20);
    //Cortes do lado esquerdo do tronco
    desenho.cutBox(20, 20, 1, 6, 4, 20);
    desenho.cutBox(19, 19, 3, 6, 4, 20);
    desenho.cutBox(18, 18, 4, 6, 4, 20);
    desenho.cutBox(17, 17, 5, 6, 4, 20);
    //Cabeça
    desenho.setColor(1, 0.64, 0, 1);
    desenho.putBox(10, 15, 6, 6, 4, 20);
    desenho.putBox(11, 13, 5, 5, 4, 20);
    desenho.putBox(6, 23, 7, 30, 4, 20);
    //Cortes no lado esquerdo da cabeça
    desenho.cutBox(20, 23, 7, 8, 4, 20);
    desenho.cutBox(19, 19, 7, 7, 4, 20);
    desenho.cutBox(22, 23, 23, 30, 4, 20);
    desenho.cutBox(23, 23, 21, 22, 4, 20);
    desenho.cutBox(21, 21, 27, 30, 4, 20);
    //desenho.cutBox(17, 23, 5, 6, 4, 20);
    //Cortes do lado direito da cabeça
    desenho.cutBox(6, 8, 7, 11, 4, 20);
    desenho.cutBox(7, 7, 12, 12, 4, 20);
    desenho.cutBox(6, 6, 12, 21, 4, 20);
    desenho.cutBox(7, 7, 15, 18, 4, 20);
    desenho.cutBox(17, 23, 5, 6, 4, 20);
    //Olho direito
    desenho.setColor(1, 1, 1, 1);
    desenho.putSphere(17, 17, 4, 3);
    //Olho esquerdo
    desenho.putSphere(23, 19, 4, 2);
    //Cabelo
    desenho.setColor(0, 0, 0, 1);
    desenho.putBox(6, 17, 30, 31, 4, 20);
    desenho.putBox(6, 13, 29, 30, 4, 20);
    desenho.putBox(18, 20, 31, 31, 4, 20);
    desenho.cutBox(17, 17, 31, 31, 4, 20);
    desenho.cutBox(15, 15, 31, 31, 4, 20);
    desenho.cutBox(6, 13, 31, 31, 4, 20);
    desenho.cutBox(13, 13, 30, 30, 4, 20);
    
    
    desenho.writeOFF((const char*)"BartSimpson.off");

    std::cout << "passou\n";

    getchar();
    return 0;
}
