#include "./include/Balde.hpp"

Balde::Balde(size_t tamM):pseudoChaves{tamM} {
    this->profundidadeLocal = 0;
    this->tamanhoM = tamM;
}

size_t Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

size_t Balde::getTamanhoM(){
    return this->tamanhoM;
}

std::string Balde::getPseudoChave(size_t i){
    return this->pseudoChaves[i];
}

void Balde::imprimeBalde(){
    std::cout << "acessou a func" << std::endl;
    for(size_t i = 0; i < this->getTamanhoM(); i++){
        std::cout << "Elemento na pos: " << i << " do balde" << std::endl;
        std::cout << "Com pseudochave: " << this->getPseudoChave(i) << std::endl;
    }
}

bool Balde::isCheio(){
    if(this->pseudoChaves.size() < this->pseudoChaves.max_size()){
        return false;
    }
    return true;
}

void Balde::insere(std::string pseudoChave){
    this->pseudoChaves.push_back(pseudoChave);
}

std::string Balde::busca(std::string pseudoChave){
    std::vector<std::string>::iterator it;
    it = find (this->pseudoChaves.begin(), this->pseudoChaves.end(), pseudoChave);
    if (it != this->pseudoChaves.end())
        return pseudoChave;
    else
        std::cout << "Element not found in pseudoChaves\n";
    return {};
}

void Balde::atualizaBalde(size_t profundidadeNova) {
    this->profundidadeLocal = profundidadeNova;
}