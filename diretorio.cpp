#include <vector>
#include <cmath>
#include "./include/Diretorio.hpp"

Diretorio::Diretorio(size_t nBits):conjuntoBaldes{2} {
    this->profundidadeGlobal = 1;
    this->bitsB = nBits;
    std::vector<Balde*> conjuntoBaldes;
}

void Diretorio::insere(std::string pseudoChave){

}

std::string Diretorio::busca(std::string pseudoChave){

}

void Diretorio::divide(){

}

void Diretorio::duplicaDiretorio(){
    this->profundidadeGlobal += 1;
    //std::vector<Balde*> duplicata {pow(2,profundidadeGlobal)};
    //rearranjar
    
    //this->conjuntoBaldes = duplicata;
}