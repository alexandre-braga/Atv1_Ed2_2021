#include "./include/Diretorio.hpp"

Diretorio::Diretorio(size_t nBits, size_t tamM):conjuntoBaldes{2} {
    this->profundidadeGlobal = 1;
    this->bitsB = nBits;
    std::vector<Balde*> conjuntoBaldes;
    for (size_t i = 0; i < 2; i++){
        Balde* novoBalde = new Balde(tamM);
        //std::cout << "Novo Balde criado" << std::endl;
        conjuntoBaldes.push_back(novoBalde);
        //std::cout << "Novo Balde adicionado" << std::endl;
    }
}

size_t Diretorio::getTamanhoDir(){
    return this->conjuntoBaldes.size();
}

void Diretorio::insere(std::string pseudoChave){
    size_t indiceBalde = std::stoi(pseudoChave.substr(0, this->profundidadeGlobal), nullptr, 2); //Acesso ao indice do Balde por binario
    size_t dLocal = conjuntoBaldes[indiceBalde]->getProfundidadeLocal();
    size_t dGlobal = this->profundidadeGlobal;
    if(!conjuntoBaldes[indiceBalde]->isCheio()){
        conjuntoBaldes[indiceBalde]->insere(pseudoChave); 
    }
    else{
        if(dLocal > dGlobal){
            std::cout << "implementaçao errada\n";
        }
        if(dLocal == dGlobal){
            if(dGlobal <= this->bitsB){
                this->duplicaDiretorio();
            }
            else{
                throw std::invalid_argument("Essa pseudochave não pode ser inserida, o diretório não pode mais ser duplicado");
            }
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
    return {};
}

void Diretorio::divideBaldes(size_t indiceBalde){
    //cria um novo balde
    size_t profundidadeNova = conjuntoBaldes[indiceBalde]->getProfundidadeLocal() + 1;
    size_t novoTamanhoM = conjuntoBaldes[indiceBalde]->getTamanhoM();
    Balde* novoBalde = new Balde(novoTamanhoM);

    //coloca os 2 com profundidade+1
    conjuntoBaldes[indiceBalde]->atualizaBalde(profundidadeNova);
    novoBalde->atualizaBalde(profundidadeNova);

    //percorre o balde original
    for (size_t i = 0; i < novoTamanhoM; i++){
        //pega a pseudochave no balde original
        std::string pseudoChaveAtual = conjuntoBaldes[indiceBalde]->getPseudoChave(i);
        //redistribui as chaves, colocando como novoIndice a pseudoChave de acordo com a profundidadeGlobal 
        size_t novoIndice = std::stoi(pseudoChaveAtual.substr(0, this->profundidadeGlobal), nullptr, 2);
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
    size_t tamanhoDir = this->getTamanhoDir();
    std::vector<Balde*> duplicata {2*tamanhoDir};
    for (size_t i = tamanhoDir; i > 0; i-=2){
        duplicata[2*i] = conjuntoBaldes[i];
        duplicata[2*i-1] = conjuntoBaldes[i];
    }
    this->conjuntoBaldes = duplicata;
}