#ifndef BALDE_HPP
#define BALDE_HPP

#include <string>
#include <vector>
class Balde{
    private:
        size_t profundidadeLocal;
        size_t tamanhoM;
        std::vector<std::string> pseudoChaves;
    public:
        Balde(size_t tamM);  
        void atualizaBalde(std::string novaPseudoChave);
};

#endif /* BALDE_HPP */