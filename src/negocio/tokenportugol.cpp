#include "tokenportugol.h"

negocio::TokenPortugol::TokenPortugol(QString valor, enumeradores::EnumToken tipo)
    : valor(valor), tipo(tipo)
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

QString negocio::TokenPortugol::getValor()
{
    return valor;
}

enumeradores::EnumToken negocio::TokenPortugol::getTipo()
{
    return tipo;
}
