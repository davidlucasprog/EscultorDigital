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
void Sculptor::putVoxel(int x, int y, int z)
{
    if (nx>x && ny>y && nz>z)
    {
         v[x][y][z].isOn = true;// insere um voxel
    // repassa cor e transparência do voxel
        v[x][y][z].r = r; 
        v[x][y][z].g = g; 
        v[x][y][z].b = b; 
        v[x][y][z].a = a; 
        
    }
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    if(nx>x && ny>y && nz>z)
    {
        v[x][y][z].isOn = false;
    }
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
   
    if (x0> 0 && x1<nx && y0 > 0 && y1 <ny && z0> 0 && z1<nz)
    {
       //Define uma sequencia de voxel
        for(int i = x0; i<x1; i++){
            for (int j = y0; j<y1; j++){
                for (int k = z0; k<z1; k++){
                    v[i][j][k].isOn=true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
             }
         }
      }  
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
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
//Recebe as coordenadas e o raio da esfera
  if(nx>xcenter>0 && ny>ycenter>0 && nz>zcenter>0 && nx>radius>0)
  {
      for( int i = -radius; i<=radius; i++){ //pecorre o diametro
          for(int j = -radius; j<=radius; j++){
              for(int k = -radius; k<=radius; k++){
                  if ((i*i+j*j+k*k) == radius*radius)
                  { //condição da esfera centrada na origem
                      putVoxel(i+xcenter,j+ycenter,k+zcenter); //adiciona um voxel
                  }
              }
          }
      }
  }
}  
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  //Define uma elipsoide
   //recebe as coordenadas das dimensões e coordenadas do centro
    if(nx>xcenter>0 && ny>ycenter>0 && nz>zcenter>0)
    {
       for ( int i = 0; i < nx; i++){
           for ( int j = 0; j < ny; j++){
               for (int k = 0; k < nz; k++){
            //calculo da condição de existencia da elipsoide
                   if(((i-xcenter)*(i-xcenter)/(rx * rx))
                       +((j-ycenter)*(j-ycenter)/(ry * ry))+
                       ((k-zcenter)*(k-zcenter)/(rz * rz))>=1)
                   {
                       putVoxel(i,j,k); 
                   }
                }
            }
        } 
    }
}




