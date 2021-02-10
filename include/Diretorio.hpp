#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "./Balde.hpp"

class Diretorio{
    private:
        size_t profundidadeGlobal;
        size_t bitsB;
        std::vector<Balde*> conjuntoBaldes;
    public:
        Diretorio(size_t nBits);
        void insere(std::string pseudoChave);
        std::string busca(std::string pseudoChave);
        void divideBaldes();
        void duplicaDiretorio();
};

#endif /* DIRETORIO_HPP */