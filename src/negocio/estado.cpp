#include "estado.h"

void Estado::valide(QString token)
{
    if(token != QString("programa"))
    {
        throw new Excecao("Esperado Id=programa");
    }
}
