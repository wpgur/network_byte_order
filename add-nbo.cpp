#include <stdio.h>
#include <stdlib.h> // exit()
#include <stdint.h>

FILE *in;
uint32_t ch;
int n[4];

uint32_t my_htonl(uint32_t n)
{
        uint32_t n1 = (n & 0xFF000000) >> 24;
        uint32_t n2 = (n & 0x00FF0000) >> 8;


        return n1 | n2;


}

uint32_t transfer (char *s){

    in = fopen(s, "rb");

    fread(n,sizeof(uint32_t),4,in);
    uint32_t* p = reinterpret_cast<uint32_t*>(n);


    return my_htonl(*p);

    fclose(in);

}

int main(int argc, char *argv[]) {


    uint32_t h1 = transfer(argv[1]);
    uint32_t h2 = transfer(argv[2]);

    printf("%d(0x%X) + %d(0x%X)=%d(0x%X)\n",h1,h1,h2,h2,h1+h2,h1+h2);
    return 0;

}
