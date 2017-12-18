#ifndef TABELADESIMBOLOS_H
#define TABELADESIMBOLOS_H

#include <vector>
#include <QString>
#include <QRegExp>
#include "enumeradores/enumtoken.h"
#include "infraestrutura/utilitarios/excecao.h"
#include "tokenportugol.h"

using infraestrutura::Excecao;
using enumeradores::EnumToken;
using std::vector;

namespace negocio
{
class TabelaDeSimbolosPortugol
{
public:
    TabelaDeSimbolosPortugol();
    EnumToken getTipo(QString palavra);

private:
    vector<TokenPortugol> tabela;
};
}

#endif // TABELADESIMBOLOS_H
