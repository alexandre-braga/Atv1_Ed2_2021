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
        
        int getProfundidadeLocal();
        int getTamanhoM();
        bool isCheio();

        void atualizaBalde(std::string novaPseudoChave);
        void insere(std::string pseudoChave);
        std::string busca(std::string pseudoChave);
};

#endif /* BALDE_HPP */