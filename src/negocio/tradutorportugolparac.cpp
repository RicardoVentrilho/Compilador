#include "tradutorportugolparac.h"

negocio::TradutorPortugolParaC::TradutorPortugolParaC()
{
    tokens = new vector<TokenPortugol*>();
}

void negocio::TradutorPortugolParaC::adicioneLinha(vector<negocio::TokenPortugol *> tokens)
{
    this->tokens->reserve(this->tokens->size() + tokens.size());
    this->tokens->insert(this->tokens->end(), tokens.begin(), tokens.end());
}

void negocio::TradutorPortugolParaC::adicioneTokenFinalDeLinha()
{
    auto tokenFinalDeLinha = new TokenPortugol(QString(";"), EnumToken::FINAL_DE_LINHA, QString(";\n"));

    this->tokens->push_back(tokenFinalDeLinha);
}

void negocio::TradutorPortugolParaC::traduza()
{
    TokenPortugol* programa = tokens->front();
    int cache = 0;

    if (programa->getTipo() != EnumToken::PALAVRA_RESERVADA)
    {
        throw new Excecao("Erro na tradução!");
    }


    QString algoritmo;
    for (auto token : *tokens)
    {
        auto tipo = token->getTipo();
        {
            cache = 1;
        }

    }

    tokensTraduzido = QString("#include <stdio.h>\nint main() {\n%1}").arg(algoritmo);
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
