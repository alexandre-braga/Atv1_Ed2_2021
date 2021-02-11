#include "./include/Diretorio.hpp"

Diretorio::Diretorio(size_t nBits, size_t tamM) {
    this->profundidadeGlobal = 1;
    this->bitsB = nBits;
    std::vector<Balde*> conjuntoBaldes;
    for (size_t i = 0; i < 2; i++){
        Balde* novoBalde = new Balde(tamM);
        //std::cout << "Novo Balde criado" << std::endl;
        this->conjuntoBaldes.push_back(novoBalde);
        //std::cout << "Novo Balde adicionado" << std::endl;
    }
}

size_t Diretorio::getTamanhoDir(){
    return this->conjuntoBaldes.size();
}

void Diretorio::imprimeDiretorio(){
    for(size_t i = 0; i < this->conjuntoBaldes.size(); i++){
        std::cout << "\nElementos no balde de indice " << i << std::endl;
        this->conjuntoBaldes[i]->imprimeBalde();
    }
}

void Diretorio::insere(std::string pseudoChave){
    size_t indiceBalde = std::stoi(pseudoChave.substr(0, this->profundidadeGlobal), nullptr, 2); //Acesso ao indice do Balde por binario
    std::cout << "indiceBalde: " << indiceBalde << std::endl;
    size_t dLocal = this->conjuntoBaldes[indiceBalde]->getProfundidadeLocal();
    std::cout << "dLocal: " << dLocal << std::endl;
    size_t dGlobal = this->profundidadeGlobal;
    std::cout << "dGlobal: " << dGlobal << std::endl;
    
    if(!this->conjuntoBaldes[indiceBalde]->isCheio()){
        this->conjuntoBaldes[indiceBalde]->insere(pseudoChave); 
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
        this->conjuntoBaldes[indiceBalde]->busca(pseudoChave);     
    }
    else
        std::cout << "Element not found in conjuntoBaldes\n";
    return {};
}

void Diretorio::divideBaldes(size_t indiceBalde){
    std::cout << "Acessou a func divideBaldes" << std::endl;
    //cria um novo balde
    size_t profundidadeNova = this->conjuntoBaldes[indiceBalde]->getProfundidadeLocal() + 1;
    size_t novoTamanhoM = this->conjuntoBaldes[indiceBalde]->getTamanhoM();
    Balde* novoBalde = new Balde(novoTamanhoM);

    //coloca os 2 com profundidade+1
    this->conjuntoBaldes[indiceBalde]->atualizaBalde(profundidadeNova);
    novoBalde->atualizaBalde(profundidadeNova);;
    
    std::cout << "Baldes criados OK" << std::endl;

    //percorre o balde original
    for (size_t i = 0; i < novoTamanhoM; i++){
        //pega a pseudochave no balde original
        std::string pseudoChaveAtual = this->conjuntoBaldes[indiceBalde]->getPseudoChave(i);
        std::cout << "\nPseudoChaveAtual:" << pseudoChaveAtual << std::endl;

        //redistribui as chaves, colocando como novoIndice a pseudoChave de acordo com a profundidadeGlobal 
        size_t novoIndice = std::stoi(pseudoChaveAtual.substr(0, this->profundidadeGlobal), nullptr, 2);
        std::cout << "\nnovoIndice:" << novoIndice << std::endl;

        //se o novo indice for diferente do indice que ja tinha, coloca no novo Balde
        if(novoIndice != indiceBalde){
            novoBalde->insere(std::move(pseudoChaveAtual));
            //coloca o novo Balde no balde de novoIndice
           this->conjuntoBaldes[novoIndice] = novoBalde;
        }
    }
}

void Diretorio::duplicaDiretorio(){
    std::cout << "Acessou a func duplicaDir" << std::endl;
    this->profundidadeGlobal += 1;
    size_t tamanhoDir = this->getTamanhoDir();
    std::vector<Balde*> duplicata {2*tamanhoDir};
    for (size_t i = 2*tamanhoDir; i > 0; i-=2){
        duplicata[2*i] = this->conjuntoBaldes[i];
        duplicata[2*i-1] = this->conjuntoBaldes[i];    
        std::cout << "duplicata em" << i << std::endl;
        std::cout << duplicata[2*i] << std::endl;
        std::cout << duplicata[2*i-1] << std::endl;
    }
    this->conjuntoBaldes = duplicata;
    std::cout << "Diretorio após duplicata:\n" << std::endl;
    this->imprimeDiretorio();
}