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

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this -> r = r; this -> g = g; this -> b = b; a = alpha;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if(nx>x && ny>y && nz>z)
    {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0>0 && x1<nx && y0>0 && y1<ny && z0>0 && z1<nz)
    {
       for(int i=x0; i<=x1; i++)
       {
           for(int j=y0; j<=y1; j++)
           {
               for(int k=z0; k<=z1; k++)
               {
                   v[i][j][k].isOn = false;
               }
           }
       }
    }
}



