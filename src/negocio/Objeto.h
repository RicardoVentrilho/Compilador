#ifndef OBJETO_H
#define OBJETO_H
#include <string>

class Objeto {
private:
    std::string nome;
    int posicaoProximoEstado;
    std::string valor;
public:
    Objeto();
    Objeto(std::string nome, int pos){this->nome = nome; this->posicaoProximoEstado = pos;}
    void setNome(std::string nome){ this->nome = nome;}
    void setPosicao(int pos){ this->posicaoProximoEstado = pos;}
    void setValor(std::string valor){this->valor = valor;}
    std::string getNome(){return this->nome;}
    int getPosicao(){return this->posicaoProximoEstado;}
    std::string getValor(){return this->valor;}

};

#endif // OBJETO_H
