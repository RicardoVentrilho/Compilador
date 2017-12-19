#include "tokenportugol.h"

negocio::TokenPortugol::TokenPortugol(QString valor, enumeradores::EnumToken tipo)
    : valor(valor), tipo(tipo)
{
}

negocio::TokenPortugol::TokenPortugol(QString valor, enumeradores::EnumToken tipo, QString traducao)
    : valor(valor), tipo(tipo), traducao(traducao)
{
}

void negocio::TokenPortugol::setValor(QString valor)
{
    this->valor = valor;
}

void negocio::TokenPortugol::setTipo(enumeradores::EnumToken tipo)
{
    this->tipo = tipo;
}

void negocio::TokenPortugol::setTraducao(QString traducao)
{
    this->traducao = traducao;
}

QString negocio::TokenPortugol::getTraducao()
{
    return traducao;
}

QString negocio::TokenPortugol::getValor()
{
    return valor;
}

enumeradores::EnumToken negocio::TokenPortugol::getTipo()
{
    return tipo;
}


