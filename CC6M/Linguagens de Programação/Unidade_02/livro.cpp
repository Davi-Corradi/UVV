#include <iostream>
#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    int anoPublicacao{0};

public:
    // Construtor padrão
    Livro() : titulo{"Desconhecido"}, autor{"Desconhecido"}, anoPublicacao{0} {}

    // Construtor com parâmetros usando operador ternário
    Livro(std::string tituloParam, std::string autorParam, int anoParam) 
        : titulo(!tituloParam.empty() ? tituloParam : "Titulo invalido"),
          autor(!autorParam.empty() ? autorParam : "Autor invalido"),
          anoPublicacao(anoParam > 0 ? anoParam : 0) 
    {
    }

    void exibirDados() const {
        std::cout << "Titulo: " << titulo << "\n";
        std::cout << "Autor: " << autor << "\n";
        std::cout << "Ano: " << anoPublicacao << "\n";
    }
};

int main() {
    Livro meuLivro("O Hobbit", "J.R.R. Tolkien", 1937);
    meuLivro.exibirDados();
    
    return 0;
}
