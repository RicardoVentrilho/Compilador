#include "excecao.h"

infraestrutura::Excecao::Excecao(string mensagem)
{
    set_mensagem(mensagem);
}

string infraestrutura::Excecao::get_mensagem()
{
    return _mensagem;
}

void infraestrutura::Excecao::set_mensagem(string mensagem)
{
    _mensagem = mensagem;
}
