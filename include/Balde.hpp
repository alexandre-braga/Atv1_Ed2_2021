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
        std::string getPseudoChave(int i);
        bool isCheio();

        void insere(std::string pseudoChave);
        std::string busca(std::string pseudoChave);
        void atualizaBalde(int profundidadeNova);
};

#endif /* BALDE_HPP */