#pragma once

#include <string>

class ContaBanco
{
private:
    std::string titular;
    double saldo{0.0};

public:
    ContaBanco();
    ContaBanco(std::string nomeTitular, double saldoInicial);

    void setTitular(std::string nomeTitular);

    std::string getTitular() const;
    double getSaldo() const;

    void depositar(double valor);
    void sacar(double valor);
    void exibirDados() const;
};