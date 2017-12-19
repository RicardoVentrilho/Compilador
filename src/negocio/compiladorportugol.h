#ifndef COMPILADORPORTUGOLPARAC_H
#define COMPILADORPORTUGOLPARAC_H

#include <QString>
#include <QStringList>
#include "estado.h"
#include "analisadorlexicoportugol.h"
#include "analisadorsintaticoportugol.h"
#include "tradutorportugolparac.h"

namespace negocio
{
class CompiladorPortugol
{
public:
    CompiladorPortugol();
    void compile(QString texto);
    void inicialize();
    QStringList separeLinhas(QString texto);

private:
    TabelaDeSimbolosPortugol* tabelaDeSimbolos;
    AnalisadorLexicoPortugol* analisadorLexico;
    AnalisadorSintaticoPortugol* analisadorSintatico;
    TradutorPortugolParaC* tradutor;

};
}

#endif // COMPILADORPORTUGOLPARAC_H
