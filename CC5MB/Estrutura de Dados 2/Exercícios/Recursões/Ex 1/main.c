#include <stdio.h>

int mult_aux(int a, int b, int res){
    if(b == 0) return res;
    
    return mult_aux(a, b - 1, res + a);
}

int mult(int a, int b){
    return mult_aux(a, b, 0);
}

int main()
{
    printf("%d", mult(5,3));
    
    return 0;
}
