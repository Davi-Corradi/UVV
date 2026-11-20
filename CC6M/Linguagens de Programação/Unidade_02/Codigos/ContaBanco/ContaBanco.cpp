#include "ContaBanco.hpp"
#include <iostream>
#include <format>

ContaBanco::ContaBanco() : titular{"Nao identificado"}, saldo{0.0} {}

ContaBanco::ContaBanco(std::string nomeTitular, double saldoInicial) : 
    titular(!nomeTitular.empty() ? nomeTitular : "Nao identificado"),
    saldo(saldoInicial > 0 ? saldoInicial : 0.0)
{
    if (saldoInicial <= 0.0)
    {
        std::cout << "\nAviso: Conta iniciada com saldo zerado! Deposite alguma quantia para movimentar a conta ou sacar.\n";
    }
}

std::string ContaBanco::getTitular() const
{
    return titular;
}

double ContaBanco::getSaldo() const
{
    return saldo;
}

void ContaBanco::setTitular(std::string nome)
{
    if (!nome.empty())
    {
        this->titular = nome;
    }
}

void ContaBanco::depositar(double valor)
{
    if (valor > 0.0)
    {
        saldo += valor;
        std::cout << "Deposito de R$ " << valor << " realizado com sucesso.\n";
    }

    else
    {
        std::cout << "Deposito Invalido!";
    }
}

void ContaBanco::sacar(double valor)
{
    if (valor > 0.0 && valor <= saldo)
    {
        saldo -= valor;
        std::cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
    }

    else
    {
        std::cout << "Falha no saque. Saldo insuficiente ou valor invalido.\n";
    }
}

void ContaBanco::exibirDados() const
{
    std::cout << "Cliente: " << getTitular() << "\n";
    std::cout << std::format("Saldo: R$ {:.2f}\n", getSaldo());
}