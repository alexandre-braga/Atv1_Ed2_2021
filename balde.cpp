#include "./include/Balde.hpp"

Balde::Balde(size_t tamM):pseudoChaves{tamM} {
    this->profundidadeLocal = 0;
    this->tamanhoM = tamM;
}

void Balde::atualizaBalde(std::string novaPseudoChave) {
    pseudoChaves.push_back(novaPseudoChave);
    this->profundidadeLocal += 1;
}

int Balde::getTamanhoM(){
    return this->tamanhoM;
}

std::string Balde::busca(std::string pseudoChave){
    std::vector<std::string>::iterator it;
    it = find (pseudoChaves.begin(), pseudoChaves.end(), pseudoChave);
    if (it != pseudoChaves.end())
        return pseudoChave;
        
    else
        std::cout << "Element not found in pseudoChaves\n";
}