#include <stdio.h>

typedef union{
    float origin;
    struct {
        unsigned int mantissa:23;
        unsigned int exponent:8;
        unsigned int sign:1;
    }d;
    
}data;

int main()
{
    data v;
    v.origin = 33.75f;
    
    printf("%u ", v.d.sign);
    for(int i = 7; i >=0; --i){
        printf("%u", (v.d.exponent & (1 << i)) != 0);
    }
    printf(" ");
    for(int i = 22; i >=0; --i){
        printf("%u", (v.d.mantissa & (1 << i)) != 0);
    }
    printf("\n");
    

    return 0;
}