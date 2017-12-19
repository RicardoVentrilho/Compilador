#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include "enumeradores/enumtoken.h"
using enumeradores::EnumToken;
class Objeto {
private:
    std::string nome;
    int posicaoProximoEstado;
    std::string token;
public:
    Objeto();
    Objeto(std::string nome, int pos){this->nome = nome; this->posicaoProximoEstado = pos;}
    void setNome(std::string nome){ this->nome = nome;}
    void setPosicao(int pos){ this->posicaoProximoEstado = pos;}
    void setValor(std::string valor){this->token = valor;}
    std::string getNome(){return this->nome;}
    int getPosicao(){return this->posicaoProximoEstado;}
    std::string getValor(){return this->token;}

};

#endif // OBJETO_H
