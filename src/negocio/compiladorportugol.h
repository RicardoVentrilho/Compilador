#ifndef COMPILADORPORTUGOLPARAC_H
#define COMPILADORPORTUGOLPARAC_H

#include <QString>
#include <QStringList>
#include "estado.h"
#include "analisadorlexico.h"

namespace negocio
{
class CompiladorPortugol
{
public:
    CompiladorPortugol();
    void compile(QString texto);
    QStringList separeLinhas(QString texto);
    QStringList separeTokens(QString texto);

private:
    Estado* estadoInicial;
    AnalisadorLexico* analisadorLexico;
};
}

#endif // COMPILADORPORTUGOLPARAC_H
