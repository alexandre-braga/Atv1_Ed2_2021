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
        if(dLocal > dGlobal){
            std::cout << "implementaçao errada\n";
        }
        if(dLocal == dGlobal){
            this->duplicaDiretorio();
        }
        this->divideBaldes(indiceBalde);
        this->insere(pseudoChave);
    }
}

std::string Diretorio::busca(std::string pseudoChave){
    size_t indiceBalde = std::stoi(pseudoChave.substr(0, this->profundidadeGlobal), nullptr, 2); //Acesso ao indice do Balde por binario
    if (indiceBalde < pow(2,this->profundidadeGlobal)){
        conjuntoBaldes[indiceBalde]->busca(pseudoChave);     
    }
    else
        std::cout << "Element not found in conjuntoBaldes\n";
    return 0;
}

void Diretorio::divideBaldes(int indiceBalde){
    //cria um novo balde
    int profundidadeNova = conjuntoBaldes[indiceBalde]->getProfundidadeLocal() + 1;
    int novoTamanhoM = conjuntoBaldes[indiceBalde]->getTamanhoM();
    Balde* novoBalde = new Balde(novoTamanhoM);

    //coloca os 2 com profundidade+1
    conjuntoBaldes[indiceBalde]->atualizaBalde(profundidadeNova);
    novoBalde->atualizaBalde(profundidadeNova);

    //percorre o balde original
    for (int i = 0; i < novoTamanhoM; i++){
        //pega a pseudochave no balde original
        std::string pseudoChaveAtual = conjuntoBaldes[indiceBalde]->getPseudoChave(i);
        //redistribui as chaves, colocando como novoIndice a pseudoChave de acordo com a profundidadeGlobal 
        int novoIndice = std::stoi(pseudoChaveAtual.substr(0, this->profundidadeGlobal), nullptr, 2);
        //se o novo indice for diferente do indice que ja tinha, coloca no novo Balde
        if(novoIndice != indiceBalde){
            novoBalde->insere(std::move(pseudoChaveAtual));
        }
        //coloca o novo Balde no balde de novoIndice
        conjuntoBaldes[novoIndice] = novoBalde;
    }
}

void Diretorio::duplicaDiretorio(){
    this->profundidadeGlobal += 1;

    //cada indice na posição i, vai ter uma duplicata no indice na posição i+1
    //duplicar o tam do vector, e ir movendo cada indice (pos e pos-1) posições a frente a partir do ultimo
    //for com 2*pos = pos e 2*pos-1 = pos

    //std::vector<Balde*> duplicata {pow(2,profundidadeGlobal)};
    
    //this->conjuntoBaldes = duplicata;
}