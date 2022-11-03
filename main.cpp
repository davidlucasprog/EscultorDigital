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
    //Biloca do olho direito
    desenho.setColor(0, 0, 0, 1);
    desenho.putVoxel(15, 16, 1);
    //Biloca do olho esquerdo
    desenho.setColor(0, 0, 0, 1);
    desenho.putVoxel(23, 19, 1);
    //Cabelo
    desenho.setColor(0, 0, 0, 1);
    desenho.putBox(6, 17, 30, 31, 4, 20);
    desenho.putBox(6, 13, 29, 30, 4, 20);
    desenho.putBox(18, 20, 31, 31, 4, 20);
    desenho.cutBox(17, 17, 31, 31, 4, 20);
    desenho.cutBox(15, 15, 31, 31, 4, 20);
    desenho.cutBox(6, 13, 31, 31, 4, 20);
    desenho.cutBox(13, 13, 30, 30, 4, 20);
    desenho.cutBox(11, 11, 30, 30, 4, 20);
    desenho.cutBox(6, 9, 30, 30, 4, 20);
    desenho.putBox(6, 9, 28, 28, 4, 20);
    desenho.putBox(7, 7, 27, 27, 4, 20);
    desenho.putBox(9, 9, 27, 27, 4, 20);
    //Contorno do lado direito
    desenho.putBox(4, 4, 27, 28, 4, 20);
    desenho.putBox(5, 5, 25, 27, 4, 20);
    desenho.putBox(6, 6, 22, 24, 4, 20);
    desenho.putBox(7, 7, 19, 21, 4, 20);
    desenho.putBox(8, 8, 15, 18, 4, 20);
    
    //vinicius
     //contorno preto-lado esquerdo
    desenho.setColor(0, 0, 0, 1);
    desenho.putBox(8, 8, 0, 2, 4, 20);//contorno do braço
    desenho.putBox(4, 4, 0, 2, 4, 20);
    desenho.putBox(5, 7, 3, 3, 4, 20);
    desenho.putBox(6, 6, 4, 4, 4, 20);
    desenho.putBox(7, 7, 5, 5, 4, 20);
    desenho.putBox(8, 8, 6, 6, 4, 20);
    desenho.putBox(9, 9, 6, 11, 4, 20);
    desenho.putBox(8, 8, 12, 12, 4, 20);
    desenho.putBox(7, 7, 13, 14, 4, 20);
    desenho.putBox(9, 9, 15, 15, 4, 20);
    desenho.putBox(10, 10, 12, 12, 4, 20);
    desenho.putBox(9, 9, 13, 13, 4, 20);
    desenho.putBox(10, 10, 14, 14, 4, 20);
   

    //contorno preto-lado direito
    desenho.setColor(0, 0, 0, 1);
    desenho.putBox(19, 19, 0, 2, 4, 20);
    desenho.putBox(20, 20, 0, 0, 4, 20);
    desenho.putBox(18, 18, 2, 3, 4, 20);
    desenho.putBox(17, 17, 4, 4, 4, 20);
    desenho.putBox(14, 16, 5, 5, 4, 20);
    desenho.putBox(11, 13, 4, 4, 4, 20);
    desenho.putBox(10, 10, 5, 5, 4, 20);
    desenho.putBox(16, 16, 6, 6, 4, 20);
    desenho.putBox(17, 18, 7, 7, 4, 20);
    desenho.putBox(19, 19, 8, 8, 4, 20);
    desenho.putBox(15, 23, 9, 9, 4, 20);
    desenho.putBox(12, 14, 10, 10, 4, 20);
    desenho.putBox(13, 13, 11, 11, 4, 20);
    desenho.putBox(24, 24, 10, 11, 4, 20);
    desenho.putBox(23, 23, 12, 12, 4, 20);
    desenho.putBox(21, 23, 13, 13, 4, 20);
    
    desenho.writeOFF((const char*)"BartSimpson.off");

    std::cout << "passou\n";

    getchar();
    return 0;
}
