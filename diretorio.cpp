#include "./include/Diretorio.hpp"

Diretorio::Diretorio(size_t nBits):conjuntoBaldes{2} {
    this->profundidadeGlobal = 1;
    this->bitsB = nBits;
    std::vector<Balde*> conjuntoBaldes;
}

void Diretorio::insere(std::string pseudoChave){
    size_t indiceBalde = std::stoi(pseudoChave.substr(0, this->profundidadeGlobal), nullptr, 2); //Acesso ao indice do Balde por binario
    int dLocal = conjuntoBaldes[indiceBalde]->getProfundidadeLocal();
    int dGlobal = this->profundidadeGlobal;
    if(!conjuntoBaldes[indiceBalde]->isCheio()){
        conjuntoBaldes[indiceBalde]->insere(pseudoChave); 
    }
    else{
        if(dLocal < dGlobal){

        }
    }
}

std::string Diretorio::busca(std::string pseudoChave){
    size_t indiceBalde = std::stoi(pseudoChave.substr(0, this->profundidadeGlobal), nullptr, 2); //Acesso ao indice do Balde por binario
    if (indiceBalde < pow(2,this->profundidadeGlobal)){
        conjuntoBaldes[indiceBalde]->busca(pseudoChave);     
    }
    else
        std::cout << "Element not found in conjuntoBaldes\n";
}

void Diretorio::divide(){

}

void Diretorio::duplicaDiretorio(){
    this->profundidadeGlobal += 1;
    //std::vector<Balde*> duplicata {pow(2,profundidadeGlobal)};
    //rearranjar
    
    //this->conjuntoBaldes = duplicata;
}