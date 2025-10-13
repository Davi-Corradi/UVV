#include <stdio.h>

int somar(int x, int y, int z){
    return x+y+z;
}

int main()
{
    int a,b,c;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    
    printf("Digite o segundo e o terceiro número: ");
    scanf("%d %d", &b, &c);
   
    printf("Resultado: %d", somar(a,b,c));
    return 0;
}
