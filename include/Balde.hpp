#ifndef BALDE_HPP
#define BALDE_HPP

#include <string>
#include <vector>

class Balde{
    private:
        size_t profundidadeLocal;
        size_t tamanhoM;
        std::vector<string> pseudoChaves;
    public:
        void atualizaProfundidade();
};

#endif /* BALDE_HPP */