#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <vector>
#include <QString>
#include "objeto.h"
#include "infraestrutura/utilitarios/excecao.h"

using infraestrutura::Excecao;

class Estado
{
private:
    Objeto objeto;
    std::vector<Objeto> listaAdjacente;

public:
    Estado();
    void addEstadoAdjacente(Objeto objeto){this->listaAdjacente.push_back(objeto);}
    void setObjeto(Objeto objeto) {this->objeto = objeto;}
    std::vector<Objeto> getListEstadoAdjacente(){return this->listaAdjacente;}
    Objeto getObjeto(){return this->objeto;}

    //Exemplo
    void valide(QString token);
};

#endif // ESTADO_H
