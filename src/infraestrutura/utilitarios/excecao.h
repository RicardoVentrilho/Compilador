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
    string get_mensagem();
    void set_mensagem(string mensagem);

private:
    string _mensagem;
};

}

#endif // EXCECAO_H
