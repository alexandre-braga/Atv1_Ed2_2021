#include <string>
#include <vector>

#include "./include/Balde.hpp"

Balde::Balde(size_t tamM):pseudoChaves{tamM} {
    this->profundidadeLocal = 0;
    this->tamanhoM = tamM;
}

void Balde::atualizaBalde(std::string novaPseudoChave) {
    pseudoChaves.push_back(novaPseudoChave);
    this->profundidadeLocal += 1;
}