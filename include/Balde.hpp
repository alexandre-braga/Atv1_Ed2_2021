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
        
        size_t getProfundidadeLocal();
        size_t getTamanhoM();
        std::string getPseudoChave(size_t i);
        bool isCheio();

        void insere(std::string pseudoChave);
        std::string busca(std::string pseudoChave);
        void atualizaBalde(size_t profundidadeNova);
};

#endif /* BALDE_HPP */