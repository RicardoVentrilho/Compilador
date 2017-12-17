#ifndef COMPILADORPORTUGOLPARAC_H
#define COMPILADORPORTUGOLPARAC_H

#include <QString>
#include <QStringList>
#include "estado.h"

namespace negocio
{
class CompiladorPortugolParaC
{
public:
    CompiladorPortugolParaC();
    void compile(QString texto);

private:
    Estado* estadoInicial;
};
}

#endif // COMPILADORPORTUGOLPARAC_H
