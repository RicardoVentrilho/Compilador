#include "tradutorportugolparac.h"

negocio::TradutorPortugolParaC::TradutorPortugolParaC()
{
    tokens = new vector<TokenPortugol*>();
}

void negocio::TradutorPortugolParaC::adicioneTokens(vector<negocio::TokenPortugol *> tokens)
{
    this->tokens->reserve(this->tokens->size() + tokens.size());
    this->tokens->insert(this->tokens->end(), tokens.begin(), tokens.end());
}

void negocio::TradutorPortugolParaC::adicioneTokenFinalDeLinha()
{
    auto tokenFinalDeLinha = new TokenPortugol(QString(";"), EnumToken::FINAL_DE_LINHA);

    this->tokens->push_back(tokenFinalDeLinha);
}

void negocio::TradutorPortugolParaC::traduza()
{
    TokenPortugol* programa = tokens->front();

    if (programa->getTipo() != EnumToken::PALAVRA_RESERVADA)
    {
        throw new Excecao("Erro na tradução!");
    }

    tokens->pop_back();

    QString algoritmo;
    for (auto token : *tokens)
    {
        auto tipo = token->getTipo();

        switch (tipo) {
        case EnumToken::DELIMITADOR:
            break;
        case EnumToken::FINAL_DE_LINHA:
        case EnumToken::NUMERO:
        case EnumToken::OPERADOR_ATRIBUICAO:
        case EnumToken::OPERADOR_SEPARADOR:
        case EnumToken::ID:
            algoritmo.append(token->getValor());
            break;
        case EnumToken::VARIAVEL:
            algoritmo.append("int");
        }
    }

    tokensTraduzido = QString("#include <stdio.h>\n   int main() \n{\n%1}").arg(algoritmo);
}

void negocio::TradutorPortugolParaC::imprima()
{
//    for (auto i = tokens->begin(); i != tokens->end(); ++i)
//    {
//        if((*i)->getTipo() == EnumToken::FINAL_DE_LINHA)
//        {
//            cout << (*i)->getValor().toStdString() << endl;
//        }
//        else
//        {
//            cout << (*i)->getValor().toStdString() << ' ';
//        }
//    }

    cout << tokensTraduzido.toStdString() << endl;
}

QString negocio::TradutorPortugolParaC::monteEstruturaEmC(negocio::TokenPortugol *token, QString algoritmo)
{

}
