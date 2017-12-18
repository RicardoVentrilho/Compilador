#include "tradutorportugolparac.h"

negocio::TradutorPortugolParaC::TradutorPortugolParaC()
{

}

void negocio::TradutorPortugolParaC::adicioneTokens(vector<negocio::TokenPortugol *> tokens)
{
    this->tokens.reserve(this->tokens.size() + tokens.size());
    this->tokens.insert(this->tokens.end(), tokens.begin(), tokens.end());
}

void negocio::TradutorPortugolParaC::adicioneTokenFinalDeLinha()
{
    auto tokenFinalDeLinha = new TokenPortugol(QString(";"), EnumToken::FINAL_DE_LINHA);

    this->tokens.push_back(tokenFinalDeLinha);
}

void negocio::TradutorPortugolParaC::imprima()
{
    for (auto i = tokens.begin(); i != tokens.end(); ++i)
    {
        if((*i)->getTipo() == EnumToken::FINAL_DE_LINHA)
        {
            cout << (*i)->getValor().toStdString() << endl;
        }
        else
        {
            cout << (*i)->getValor().toStdString() << ' ';
        }
    }

}
