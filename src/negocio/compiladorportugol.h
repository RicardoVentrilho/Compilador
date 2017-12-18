#ifndef COMPILADORPORTUGOLPARAC_H
#define COMPILADORPORTUGOLPARAC_H

#include <QString>
#include <QStringList>
#include "estado.h"
#include "analisadorlexico.h"
#include "analisadorsemantico.h"

namespace negocio
{
class CompiladorPortugol
{
public:
    CompiladorPortugol();
    void compile(QString texto);
    QStringList separeLinhas(QString texto);

private:
    TabelaDeSimbolos* tabelaDeSimbolos;
    AnalisadorLexico* analisadorLexico;
    AnalisadorSemantico* analisadorSemantico;
};
}

#endif // COMPILADORPORTUGOLPARAC_H
