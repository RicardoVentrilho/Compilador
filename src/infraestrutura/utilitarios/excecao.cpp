#include "excecao.h"

infraestrutura::Excecao::Excecao(string mensagem)
{
    setMensagem(mensagem);
}

string infraestrutura::Excecao::getMensagem()
{
    return mensagem;
}

void infraestrutura::Excecao::setMensagem(string mensagem)
{
    this->mensagem = mensagem;
}
