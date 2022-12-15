#include <unistd.h>
#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

/*
int main(void)
{
    char letter_t;
    char letter_G;
    letter_t = 't';
    letter_G = 'G';

    printf("letter_t after swap: %c\n", swap_bits(letter_t));
    printf("letter_G after swap: %c\n", swap_bits(letter_G));
}
*/
