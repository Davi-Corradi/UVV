#include <iostream>

class Produto {

private:
    int codigo{0};
    double preco{0.0};
    int quantidade{0};

public:
    Produto() : codigo(0), preco(0.0), quantidade(0) {}

    Produto(int codigo, double preco, int quantidade) 
        : codigo(codigo > 0 ? codigo : 0),
            preco(preco > 0.0 ? preco : 0.0),
            quantidade(quantidade > 0 ? quantidade : 0)
    {

    }
      
    void setCodigo(int novoCodigo) {
        if (novoCodigo >= 0){
            codigo = novoCodigo;
        } else {
            std::cout << "Codigo invalido! \n";
        }  
    }

    void setPreco(double novoPreco){
        if (novoPreco >= 0.0){
           preco = novoPreco;
        } else {
            std::cout << "Preco invalido! \n";
        }
       
    }

    void setQuantidade(int novaQuantidade){
        if (novaQuantidade >= 0){
            quantidade = novaQuantidade;
        } else {
            std::cout << "Quantidade invalida! \n";
        }
    }

    int getCodigo() const{
        return codigo;
    }

    double getPreco() const{
        return preco;
    }

    int getQuantidade() const{
        return quantidade;
    }

    double aplicarDesconto(double percentual) const {
        return preco - (preco * (percentual / 100));
    }
    
    double calcularValorEstoque() const {
        return preco * quantidade;
    }
};

void exibirValorEstoque(const Produto& produto) {
    double valorEstoque = produto.calcularValorEstoque();
    std::cout << "Valor total do estoque: " << valorEstoque << "\n";
}

void exibirDados(const Produto& produto) {
    std::cout << "Codigo: " << produto.getCodigo() << "\n";
    std::cout << "Preco: " << produto.getPreco() << "\n";
    std::cout << "Quantidade: " << produto.getQuantidade() << "\n";
}

void exibirDadosComDesconto(const Produto& produto, double percentualDesconto) {
    std::cout << "Codigo: " << produto.getCodigo() << "\n";
    // Usa o método const para mostrar o preço reduzido sem alterar a memória
    std::cout << "Preco: " << produto.aplicarDesconto(percentualDesconto) << "\n";
    std::cout << "Quantidade: " << produto.getQuantidade() << "\n";
}

int main()
{
    int desconto {0};
    int desconto2 {0};
    int codigoLido {0};
    double precoLido {0.0};
    int quantidadeLida {0};

    Produto produto;
    Produto produto2(102, 50.0, 10);

    std::cout << "Digite o codigo do produto: ";
    std::cin >> codigoLido;

    std::cout << "Digite o preco do produto: ";
    std::cin >> precoLido;

    std::cout << "Digite a quantidade do produto: ";
    std::cin >> quantidadeLida;  
    
    produto.setCodigo(codigoLido);
    produto.setPreco(precoLido);
    produto.setQuantidade(quantidadeLida);
    
    std::cout << "\n";

    std::cout << "==== DADOS DO PRODUTO 1 ==== \n";
    std::cout << "\n";
    exibirDados(produto);
    
    std::cout << "\n";

    std::cout << "==== DADOS DO PRODUTO 2 ==== \n";
    std::cout << "\n"; 
    exibirDados(produto2);

    std::cout << "\n";

   /* std::cout << "Digite a porcentagem do desconto a ser aplicado no produto 1: ";
    std::cin >> desconto;
    produto.aplicarDesconto(desconto);

    std::cout << "Digite a porcentagem do desconto a ser aplicado no produto 2: ";
    std::cin >> desconto;
    produto2.aplicarDesconto(desconto);

    std::cout << "\n";
    std::cout << "Preco do produto 1 apos o desconto: " << produto.getPreco() << "\n";
    exibirDados(produto);

    std::cout << "\nPreco do produto 2 apos o desconto: " << produto2.getPreco() << "\n";
    exibirDados(produto2);

    std::cout << "\n";

    std::cout << "Produto 1 - Valor total do estoque (Baseado no desconto): " << produto.calcularValorEstoque() << "\n";
    std::cout << "Produto 2 - Valor total do estoque (Baseado no desconto): " << produto2.calcularValorEstoque() << "\n";

    */

    std::cout << "Digite a porcentagem do desconto a ser aplicado no produto 1: ";
    std::cin >> desconto;
    
    std::cout << "Digite a porcentagem do desconto a ser aplicado no produto 2: ";
    std::cin >> desconto2; // Sugiro ter variáveis separadas para cada desconto

    std::cout << "\n";
    
    std::cout << "Preco do produto 1 apos o desconto: " << produto.aplicarDesconto(desconto) << "\n";
    std::cout << "Preco do produto 2 apos o desconto: " << produto2.aplicarDesconto(desconto2) << "\n";

    std::cout << "\n==== DADOS DO PRODUTO 1 COM DESCONTO ==== \n\n";
    exibirDadosComDesconto(produto, desconto);
    
    std::cout << "\n==== DADOS DO PRODUTO 2 COM DESCONTO ==== \n\n";
    exibirDadosComDesconto(produto2, desconto2);
    
    std::cout << "\nProduto 1 - Valor total do estoque: " << produto.calcularValorEstoque() << "\n";
    std::cout << "Produto 2 - Valor total do estoque: " << produto2.calcularValorEstoque() << "\n";

    return 0;
}
