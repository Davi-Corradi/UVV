#include <stdio.h>

int main()
{

    int i; 
    
    for(i = 1; i < 101; i++){
        printf("% d", i);
    }
    
    printf ("\n\n");
    
    i = 1;
    while(i < 101){
        printf("%d ", i);
        i++;
        
    }
    
    i = 1;
    
    printf("\n\n");
    
    do{
        printf("%d ", i);
        i++;
    }
    while(i < 101);

    return 0;
}
