#include "livro.h"
#include <iostream>

Livro::Livro() : titulo{"Desconhecido"}, autor{"Desconhecido"}, anoPublicacao{0} {
}

Livro::Livro(std::string tituloParam, std::string autorParam, int anoParam) 
    : titulo(!tituloParam.empty() ? tituloParam : "Titulo invalido"),
      autor(!autorParam.empty() ? autorParam : "Autor invalido")
   // anoPublicacao(anoParam > 0 ? anoParam : "Ano invalido") 
{
    if (anoParam > 0){
        anoPublicacao = anoParam;
    }
    else {
        anoPublicacao = 0;
    }
}

std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

void Livro::setAnoPublicacao (int anoPublicacao){

    if (anoPublicacao > 0){
        this->anoPublicacao = anoPublicacao;
    }
}

void Livro::exibirDados() const {
    std::cout << "\nTitulo: " << titulo << "\n";
    std::cout << "Autor: " << autor << "\n";

    if (anoPublicacao == 0) {
        std::cout << "Ano: 0 (Ano invalido! O ano foi definido com 0 por padrao)\n\n";
    } else {
        std::cout << "Ano: " << anoPublicacao << "\n";
    }
    
}