#ifndef TABELA_H
#define TABELA_H
#include "estado.h"
#include <vector>

class Tabela{
private:
    std::vector<Estado> table;
    std::string linha;
    std::vector<std::string> listLinha;

public:
    Tabela() {
        Objeto *objeto = new Objeto("var", 0);
        Objeto *real = new Objeto("real", 1);
        Objeto *inteiro = new Objeto("inteiro", 2);
        Objeto *caracter = new Objeto("caracter", 3);
        Estado *estado = new Estado();
        estado->addEstadoAdjacente(*real);
        estado->addEstadoAdjacente(*inteiro);
        estado->addEstadoAdjacente(*caracter);
        estado->setObjeto(*objeto);
        this->table.push_back(*estado);
        // ---------------- 2 -----------------------
        objeto = new Objeto("nome", 4);
        estado = new Estado();
        estado->setObjeto(*real);
        estado->addEstadoAdjacente(*objeto);
        this->table.push_back(*estado);
        //----------------- 3 -----------------------
        estado = new Estado();
        estado->setObjeto(*inteiro);
        estado->addEstadoAdjacente(*objeto);
        this->table.push_back(*estado);
        //---------------- 4 -----------------------
        estado = new Estado();
        estado->setObjeto(*caracter);
        estado->addEstadoAdjacente(*objeto);
        this->table.push_back(*estado);
        //--------------- 5 -------------------------
        estado = new Estado();
        estado->setObjeto(*objeto);
        Objeto *igual = new Objeto("=", 5);
        estado->addEstadoAdjacente(*igual);
        Objeto *pontoVirgula = new Objeto(";", 6);
        estado->addEstadoAdjacente(*pontoVirgula);
        this->table.push_back(*estado);
        //--------------- 5.1 --------------------------
        estado = new Estado();
        estado->setObjeto(*igual);
        objeto = new Objeto("value", 7);
        estado->addEstadoAdjacente(*objeto);
        this->table.push_back(*estado);
        //----------------5.1A -------------------------
        estado = new Estado();
        estado->setObjeto(*objeto);
        estado->addEstadoAdjacente(*pontoVirgula);
        this->table.push_back(*estado);
        //--------------- 5.2 -------------------------
        estado = new Estado();
        estado->setObjeto(*pontoVirgula);
        objeto = new Objeto("fim", 8);
        estado->addEstadoAdjacente(*objeto);
        this->table.push_back(*estado);
        // ---------------- FIM -------------------------
        estado = new Estado();
        estado->setObjeto(*objeto);
        this->table.push_back(*estado);
    }

};

#endif // TABELA_H
