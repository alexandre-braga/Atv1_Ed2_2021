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
            this->divideBaldes();
            this->insere(pseudoChave);
        }
        //dLocal == dGlobal
        else{
            //this->duplicaDiretorio();
            //chama por recursao;
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

void Diretorio::divideBaldes(){
    //divide os baldes em 2 novos com profundidadeLocal+1
    //cria um novo balde no caso, e mantem o original, 
    //ajusta ponteiros e dlocal (atualizaBalde())
    //redistribui entre os 2 novos baldes
}

void Diretorio::duplicaDiretorio(){
    this->profundidadeGlobal += 1;
    //std::vector<Balde*> duplicata {pow(2,profundidadeGlobal)};
    //rearranjar
    
    //this->conjuntoBaldes = duplicata;
}