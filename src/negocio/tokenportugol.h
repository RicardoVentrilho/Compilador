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
    void setValor(QString valor);
    void setTipo(EnumToken tipo);
    QString getValor();
    EnumToken getTipo();

private:
    QString valor;
    EnumToken tipo;
};
}

#endif // TOKEN_H
