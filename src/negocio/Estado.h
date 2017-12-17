#ifndef ESTADO_H
#define ESTADO_H
#include <string>
#include "Objeto.h"
#include <vector>

class Estado {
private:
    Objeto objeto;
    std::vector<Objeto> listaAdjacente;

public:
    Estado();
    void addEstadoAdjacente(Objeto objeto){this->listaAdjacente.push_back(objeto);}
    void setEstado(Objeto objeto) {this->objeto = objeto;}
    std::vector<Objeto> getListEstadoAdjacente(){return this->listaAdjacente;}
    Objeto getEstado(){return this->objeto;}



};

#endif // ESTADO_H
