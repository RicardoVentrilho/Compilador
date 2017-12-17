#ifndef EXCECAO_H
#define EXCECAO_H

#include <string>
#include <exception>

using std::exception;
using std::string;

namespace infraestrutura
{

class Excecao : public exception
{
public:
    Excecao(string mensagem);
    string getMensagem();
    void setMensagem(string mensagem);

private:
    string mensagem;
};

}

#endif // EXCECAO_H
