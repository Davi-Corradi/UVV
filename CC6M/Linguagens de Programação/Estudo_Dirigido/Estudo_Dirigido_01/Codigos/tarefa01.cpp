#include <iostream>

int  main(int argc, char* argv[]) {
    std::cout << "Quantidade de argumentos (Desconsiderando o nome do arquivo executavel): " << argc -1;
    std::cout << "\nSao eles: ";
    
    for(int i = 1; i < argc; i++){
        std::cout << argv[i];

        if(i < argc - 1){
            std::cout << " , ";
        }
    }
    
    std::cout << "\nCaminho: " << argv[0];

    return 0;
}