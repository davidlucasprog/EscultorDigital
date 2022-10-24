#include "Sculptor.h"

Sculptor::Sculptor(int nx, int ny, int nz)
{
    int i, j, k;  //Variaveis para lassos
    this -> nx = nx; //Variaveis de dimensoes recebendo os valores de inicializacao do construtor
    this -> ny = ny;
    this -> nz = nz;

    v = new voxel**[nx]; //Alocacao dos voxels do eixo x da matriz

    for (i=0; i < nx; i++)
    {
        v[i] = new voxel*[ny]; //Alocacao dos voxels do eixo y da matriz
    }
    for (i=0; i < nx; i++)
    {
        for (j=0; j<ny; j++)
        {
            v[i][j] = new voxel[nz]; //Alocacao dos voxels do eixo z da matriz
        }
    }
}

Sculptor::~Sculptor()
{
    int i, j, k;
    for (i=0; i < nx; i++)
    {
        for (j=0; j<ny; j++)
        {
            delete [] v[i][j]; //Liberacao dos voxels do eixo z da matriz
        }
    }

    for (i=0; i < nx; i++)
    {
        delete [] v[i]; //Liberacao dos voxels do eixo y da matriz
    }
    
    delete [] v; //Liberacao completa da matriz
}
