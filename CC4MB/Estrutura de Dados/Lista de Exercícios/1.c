 #include <stdio.h>

int somar(int x, int y){
    return x+y;
}

int main()
{
    int a,b;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    
    
    printf("Resultado: %d", somar(a,b));
    return 0;
}

