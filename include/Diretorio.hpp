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
        size_t nBaldes;
        std::vector<Balde*> conjuntoBaldes;
    public:
        Diretorio(size_t nBits, size_t tamM);
        size_t getTamanhoDir();
        size_t getNBaldes();
        void imprimeDiretorio();
        void insere(std::string pseudoChave);
        bool busca(std::string pseudoChave);
        void divideBaldes(size_t indiceBalde);
        void duplicaDiretorio();
};

#endif /* DIRETORIO_HPP */