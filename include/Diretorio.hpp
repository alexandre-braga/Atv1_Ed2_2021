#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <string>
#include <vector>

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
        void divide();
        void duplicaDiretorio();
};

#endif /* DIRETORIO_HPP */