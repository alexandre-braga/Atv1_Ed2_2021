#include <iostream>
#include <vector>

#include "./include/Balde.hpp"
#include "./include/Diretorio.hpp"

using namespace std;

int main(){
    size_t tamMMain;
    size_t nBitsMain;
    size_t nInsercoes;
    
    cout << "Insira o tamanho M dos baldes:" << endl;
    cin >> tamMMain;
    cout << "Insira o numero de bits B:" << endl;
    cin >> nBitsMain;
    cout << "Insira o numero de inserções N:" << endl;
    cin >> nInsercoes;
    
    Diretorio* dir = new Diretorio(nBitsMain, tamMMain);
    cout << "Diretório criado" << endl;


    std::string pseudoChave = "";
    for (size_t i = 0; i < nInsercoes; i++){
        for (size_t j = 0; j < nBitsMain; j++){
            pseudoChave.push_back(random() % 2 + '0');
        }
        dir->insere(pseudoChave);
        pseudoChave.erase(pseudoChave.begin(),pseudoChave.end());
    }
    

    dir->imprimeDiretorio();
}