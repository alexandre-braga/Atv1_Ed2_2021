#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <vector>

#include "./Balde.hpp"


class Diretorio{
    
    private:
        size_t profundidadeGlobal;
        size_t bitsB;
        std::vector<Balde*> conjuntoBaldes;
    public:
        void insere(String pseudoChave);
        void busca(String pseudoChave);
        void divide();
        void duplicaDiretorio();

};

#endif /* DIRETORIO_HPP */