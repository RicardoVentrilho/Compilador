#ifndef TABELADESIMBOLOS_H
#define TABELADESIMBOLOS_H

#include <QString>
#include <QRegExp>
#include <list>
#include "enumeradores/enumtoken.h"
#include "infraestrutura/utilitarios/excecao.h"
#include "tokenportugol.h"

using infraestrutura::Excecao;
using enumeradores::EnumToken;
using std::list;

namespace negocio
{
class TabelaDeSimbolosPortugol
{
public:
    TabelaDeSimbolosPortugol();
    EnumToken getTipo(QString palavra);
    TokenPortugol getToken(QString palavra);
    void atualize(TokenPortugol* token);
    void adicioneTokenId(QString valor);

private:
    list<TokenPortugol> tabela;
};
}

#endif // TABELADESIMBOLOS_H
