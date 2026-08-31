#pragma once
#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    int anoPublicacao{0}; 

public:
    Livro();
    Livro(std::string tituloParam, std::string autorParam, int anoParam);
    
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAnoPublicacao() const;

    void setAnoPublicacao(int anoPublicacao);

    void exibirDados() const;
};