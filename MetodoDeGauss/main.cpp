#include <iostream>

#define nLinha 20
#define nColuna 21
using namespace std;
static void calcularVetorX();
static void mostrarTodasAsinformacoes();
static void mostrarMatriz();
static void mostrarVetorX();
static void mostrarVetorB();
static void mostrarMatrizA();

static double matriz[nLinha][nColuna] =
{
    {9,-6,-3,-4,-5,-5,-8,6,-2,2,-7,-1,4,-9,4,5,9,4,9,-5,25},
            {-8,5,-7,-8,0,2,10,-8,-2,-8,10,-2,-10,2,7,-7,6,-8,-4,-8,-184},
            {0,-1,-3,9,-5,-4,-7,8,0,-3,-1,-2,-8,10,-1,5,-9,10,1,-9,3},
            {9,-10,7,-10,-4,7,4,9,9,-2,2,10,-2,1,2,8,4,-4,6,5,185},
            {-6,-8,-4,3,0,6,4,-3,3,-5,-2,-7,-9,-10,8,0,-9,-7,3,0,-208},
            {8,1,5,-1,-7,6,-6,-8,-7,8,6,2,-6,-7,5,7,-9,-6,3,-9,-33},
            {7,1,3,-6,-9,4,0,5,-4,-2,-2,-2,-6,0,-6,0,4,-3,0,-6,142},
            {-8,6,-1,-9,0,-10,-10,-10,5,-10,-2,4,-10,2,7,1,-5,-6,0,-4,-71},
            {7,-2,-8,-5,-2,-9,10,-7,-8,-2,5,2,3,-3,4,-10,10,5,4,-5,-103},
            {7,-9,6,5,5,-6,-3,-3,1,-4,0,-6,10,0,7,8,-5,10,-4,-3,-73},
            {6,-9,4,5,-1,-5,10,10,-8,9,3,9,-9,6,-10,5,-1,-7,-5,3,220},
            {4,3,-10,-1,-3,5,4,-10,2,-8,-4,9,7,7,6,-3,1,-4,-6,2,-83},
            {7,10,10,2,6,-7,10,1,2,6,-6,8,6,10,1,-1,7,-2,5,9,209},
            {-7,9,9,-3,10,4,6,3,-9,-2,-6,-4,-6,3,-8,-6,7,1,8,-9,147},
            {1,1,-4,-4,-4,1,-5,-6,-4,-1,5,7,-2,-5,9,-2,0,4,3,-8,-159},
            {5,0,-10,-6,-7,-1,8,4,1,-10,4,-9,-4,-7,-4,3,5,8,2,6,-88},
            {-10,-2,10,7,-7,5,-8,6,5,8,9,-7,-5,-10,7,-1,-2,-4,2,7,-97},
            {-6,6,1,4,0,-2,3,-8,9,-6,7,-6,-4,-2,10,7,10,1,1,2,-193},
            {1,-8,8,-9,10,7,-5,5,-2,-9,10,5,6,0,-8,-8,-3,7,-7,-1,46},
            {6,9,-7,-4,-2,0,3,1,-9,-7,0,-8,1,-5,-8,-4,10,-3,8,6,30}
};

static int linhaAtual;
static int colunaAtual;
static double vetb[nLinha];
static double vetx[nLinha];
static double matA[nLinha][nLinha];
static double pivo;
static int n = 0;
int main()
{
    calcularVetorX();
    return 0;
}

void calcularVetorX()
{
    n = 0;
    pivo = 0;
    linhaAtual = -1;
    colunaAtual = -1;
    mostrarMatriz();

    cout << "\n";
    do
    {
        n++;
        linhaAtual++;
        colunaAtual++;
        pivo = matriz[linhaAtual][linhaAtual];
        double mnn;
        int l, c;
        for (l = linhaAtual + 1; l < nLinha; l++)
        {
            mnn = matriz[l][colunaAtual] / pivo;

            for (c = colunaAtual; c < nColuna; c++)
            {
                matriz[l][c] = matriz[l][c] - (mnn * (matriz[linhaAtual][c]));
            }

        }

        mostrarTodasAsinformacoes();

    }
    while (linhaAtual < nLinha - 1);
    mostrarVetorX();
}

static void mostrarTodasAsinformacoes()
{
    cout << "Nº: " << n << endl;
    cout << "Pivô: " << pivo << endl;

    cout << "Matriz:" << endl;
    int x,y;
    for (int x = 0; x < nLinha; x++)
    {
        for (int y = 0; y < nColuna; y++)
        {
            cout << " " << matriz[x][y] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

static void mostrarMatriz()
{
    cout << "Matriz:" << endl;
        for (int x = 0; x < nLinha; x++) {
            for (int y = 0; y < nColuna; y++) {
                cout << " " << matriz[x][y] << " ";
            }
            cout << "\n";
        }
}

static void mostrarVetorX()
{
    double res = 0;

        int b;
        for(b = 0; b < nLinha; b++){
            vetb[b] = matriz[b][nColuna -1];
        }

        int l;
        for (l = 0; l < nLinha; l++) {
            for (int c = 0; c < nColuna - 1; c++) {
                matA[l][c] = matriz[l][c];
            }
        }

        mostrarVetorB();
        mostrarMatrizA();

        for(l = nLinha - 1; l >= 0; l--){
            for(int c = nLinha - 1; c >= 0; c--){
                if(l == c){
                    break;
                }else{
                    res = res + (matA[l][c] * (vetx[c]));
                }
            }
            vetx[l] = (vetb[l] - (res)) / (matA[l][l]);
            res = 0;
        }
        cout << "\n";
        cout << "Vetor X:"<< endl;
        int x;
        for(x = 0; x < nLinha; x++){
            cout << vetx[x] << endl;
        }
}

static void mostrarVetorB()
{
    cout << "\n";
        cout << "Vetor B:" << endl;
        int b;
        for(b = 0; b < nLinha; b++){
            cout << (vetb[b]) << endl;
        }
}

static void mostrarMatrizA()
{
    cout << "\n";
        cout << "Matriz A:" << endl;
        int l, c;
        for(int l = 0; l < nLinha; l++){
            for(int c = 0; c < nLinha; c++){
                cout << " " << matA[l][c] << " ";
            }
            cout << "" << endl;
        }
}

