#include <iostream>
#include <iomanip>
#include <vector>

#include "./include/Balde.hpp"
#include "./include/Diretorio.hpp"

using namespace std;

int main(){
    size_t tamMMain;
    size_t nBitsMain;
    size_t nInsercoes;
    size_t nCasasMesmoPadrao;
    size_t naoInseridos = 0;

    cout << "Insira o tamanho M dos baldes:" << endl;
    cin >> tamMMain;
    cout << "Insira o numero de bits B:" << endl;
    cin >> nBitsMain;
    cout << "Insira o numero de inserções N:" << endl;
    cin >> nInsercoes;
    cout << "Insira o numero de casas N para mesmo padrão:" << endl;
    cin >> nCasasMesmoPadrao;
    
    Diretorio* dir = new Diretorio(nBitsMain, tamMMain);
    cout << "Diretório criado" << endl;


    std::string pseudoChave = "";
    for (size_t i = 0; i < nInsercoes; i++){
        for (size_t k = 0; k < nCasasMesmoPadrao; k++){
            pseudoChave.push_back('0');
        }
        for (size_t j = 0; j < (nBitsMain - nCasasMesmoPadrao); j++){
            pseudoChave.push_back(random() % 2 + '0');
        }
        if(!dir->busca(pseudoChave)){
            dir->insere(pseudoChave);
        }
        else{
            naoInseridos++;
        }
        pseudoChave.erase(pseudoChave.begin(),pseudoChave.end());
    }
    

    dir->imprimeDiretorio();
    cout << "\nNão inseridos: " << naoInseridos << endl;
    size_t a = nInsercoes - naoInseridos;
    size_t b = dir->getTamanhoDir() * tamMMain;
    double fatorCarga = double(a)/double(b);
    cout << "Fator de Carga: " << fixed << setprecision(4) << fatorCarga << endl;
    cout << "Tamanho Diretório: " << dir->getTamanhoDir() << endl;
}