#include <stdio.h>

#include <stdio.h>

unsigned invert(unsigned x, int p, int n){
return x ^ (~(~0 << n) << (p + 1-n));

}


int main(){

unsigned x = 123;
int p = 2;
int n = 2;

printf("\n%u turns into %u", x, invert(x,p,n));




return 0;

}




XOR produces a 1 when the two bits are different and a 0 when they are the same. To invert bits you can just compare a number with 
all 1s using XOR. So if the original bit is a 0 it will produce a 1, if the original bit is a 1 it produces a 0. Then you shift the number 
based on your p and n values.
