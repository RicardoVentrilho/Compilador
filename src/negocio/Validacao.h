#ifndef VALIDACAO_H
#define VALIDACAO_H
#include<string>
#include<vector>
class Validacao{
private:
    std::string linha;
    std::vector<std::string> listLinha;
    std::string correspondenteC;

public:
    Validacao(){this->linha = "";}
    void setLinha(std::string linha){ this->linha = linha;}
    std::string getLinha(){ return this->linha;}
    void montarListLinha() {

    }
};

#endif // VALIDACAO_H
