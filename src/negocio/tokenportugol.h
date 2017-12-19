#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include "enumeradores/enumtoken.h"

using enumeradores::EnumToken;

namespace negocio
{
class TokenPortugol
{
public:
    TokenPortugol(QString valor, EnumToken tipo);
     TokenPortugol(QString valor, EnumToken tipo, QString traducao);
    void setValor(QString valor);
    void setTipo(EnumToken tipo);
    void setTraducao(QString traducao);
    QString getTraducao();
    QString getValor();
    EnumToken getTipo();

private:
    QString valor;
    EnumToken tipo;
    QString traducao;
};
}

#endif // TOKEN_H
