#ifndef COMPILADORPORTUGOLPARAC_H
#define COMPILADORPORTUGOLPARAC_H

#include <QString>
#include <QStringList>
#include "estado.h"
#include "analisadorlexicoportugol.h"
#include "analisadorsemanticoportugol.h"

namespace negocio
{
class CompiladorPortugol
{
public:
    CompiladorPortugol();
    void compile(QString texto);
    QStringList separeLinhas(QString texto);

private:
    TabelaDeSimbolosPortugol* tabelaDeSimbolos;
    AnalisadorLexicoPortugol* analisadorLexico;
    AnalisadorSemanticoPortugol* analisadorSemantico;
};
}

#endif // COMPILADORPORTUGOLPARAC_H
