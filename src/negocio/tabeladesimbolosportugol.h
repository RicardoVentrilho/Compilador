#ifndef TABELADESIMBOLOS_H
#define TABELADESIMBOLOS_H

#include <map>
#include <QString>
#include <QRegExp>
#include "enumeradores/enumtoken.h"
#include "infraestrutura/utilitarios/excecao.h"

using infraestrutura::Excecao;
using enumeradores::EnumToken;
using std::map;

namespace negocio
{
class TabelaDeSimbolosPortugol
{
public:
    TabelaDeSimbolosPortugol();
    EnumToken getTipo(QString palavra);
    bool ehId(QString palavra);

private:
    map<QString, EnumToken> dicionario;
};
}

#endif // TABELADESIMBOLOS_H
