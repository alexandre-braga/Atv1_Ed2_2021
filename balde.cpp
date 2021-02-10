#include "./include/Balde.hpp"

Balde::Balde(size_t tamM):pseudoChaves{tamM} {
    this->profundidadeLocal = 0;
    this->tamanhoM = tamM;
}

int Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

int Balde::getTamanhoM(){
    return this->tamanhoM;
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
}

void Balde::atualizaBalde(int profundidadeNova) {
    this->profundidadeLocal = profundidadeNova;
}