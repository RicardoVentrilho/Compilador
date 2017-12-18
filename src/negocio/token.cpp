#include "token.h"

negocio::Token::Token(QString valor, enumeradores::EnumToken tipo)
    : valor(valor), tipo(tipo)
{
}

void negocio::Token::setValor(QString valor)
{
    this->valor = valor;
}

void negocio::Token::setTipo(enumeradores::EnumToken tipo)
{
    this->tipo = tipo;
}

QString negocio::Token::getValor()
{
    return valor;
}

enumeradores::EnumToken negocio::Token::getTipo()
{
    return tipo;
}
