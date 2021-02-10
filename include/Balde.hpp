#ifndef BALDE_HPP
#define BALDE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Balde{
    private:
        size_t profundidadeLocal;
        size_t tamanhoM;
        std::vector<std::string> pseudoChaves;
    public:
        Balde(size_t tamM);  
        void atualizaBalde(std::string novaPseudoChave);
        int getTamanhoM();
        std::string busca(std::string pseudoChave);
};

#endif /* BALDE_HPP */