#include <iostream>
#include "livro.h"

int main() {
    Livro livro1("O Hobbit", "J.R.R. Tolkien", 1937);
    livro1.exibirDados();
    
    Livro livro2("O Senhor dos Aneis", "J.R.R Tolkien", -1);
    livro2.exibirDados();

    return 0;
}