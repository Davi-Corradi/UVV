#include <stdio.h>

void aposentar(int idade, int ts){
    if(idade >= 65){
        printf("Pode se aposentar! ");
    }
    else if(ts >= 30){
        printf("Pode se aposentar! ");
    }
    else if(idade >= 60 && ts == 25){
        printf("Pode se aposentar! ");
    }
    else{
        printf("Não pode se aposentar! ");
    }
}

int main()
{
    int idade, ts;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);
    
    printf("Digite o tempo de serviço: ");
    scanf("%d", &ts);
    
    aposentar(idade, ts);
    return 0;
}
