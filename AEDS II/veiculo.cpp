#include <iostream>
#include <fstream>
using namespace std;

typedef struct Tveiculo
{
    string modelo, marca, tipo, comb, camb, dir, cor, placa;
    int ano, km, port;
    float pot;
};
Tveiculo *busca(Tveiculo *bd[], int tam, string placa)
{
    for (int i = 0; i < tam; i++)
    {
        if (bd[i]->placa == placa)
            return bd[i];
    }
    return NULL;
}
int main(int argc, char **argv)
{
    int tam = 0;
    ifstream myfile("BDVeiculos.txt");
    Tveiculo *bd[50];
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            bd[tam] = new Tveiculo;
            myfile >> bd[tam]->modelo;
            myfile >> bd[tam]->marca;
            myfile >> bd[tam]->tipo;
            myfile >> bd[tam]->ano;
            myfile >> bd[tam]->km;
            myfile >> bd[tam]->pot;
            myfile >> bd[tam]->comb;
            myfile >> bd[tam]->camb;
            myfile >> bd[tam]->dir;
            myfile >> bd[tam]->cor;
            myfile >> bd[tam]->port;
            myfile >> bd[tam]->placa;

            tam++;
        }
        myfile.close();

        /*Tveiculo *p = busca(bd, tam, "AAC9107");
        if (p)
        {
            cout << "Veiculo encontrado" << endl;
            cout << p->marca << " " << p->modelo << " " << p->ano << " " << endl;
        }
        else cout << "Veiculo não encontrado" << endl;
*/
        for (int i = 0; i < tam; i++){
            cout << bd[i]->modelo << " ";
            cout << bd[i]->marca << " ";
            cout << bd[i]->tipo << " ";
            cout << bd[i]->ano << " ";
            cout << bd[i]->km << " ";
            cout << bd[i]->pot << " ";
            cout << bd[i]->comb << " ";
            cout << bd[i]->camb << " ";
            cout << bd[i]->dir << " ";
            cout << bd[i]->cor << " ";
            cout << bd[i]->port << " ";
            cout << bd[i]->placa << endl;
        }

        // Apontando os espaços vazios
        for (int i = tam; i < 50; i++)
            bd[i] = NULL;

        // Removendo structs da memória
        for (int i = 0; i < tam; i++)
            delete (bd[i]);
    }
    else
        cout << "Unable to open file";
}