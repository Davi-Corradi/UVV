#include <stdio.h>

int main()
{

    int i; 
    
    i = 10;
    while(i <= 10 && i > 0){
        printf("%d ", i);
        i--;
    }
    
    printf("FIM");

    return 0;
}