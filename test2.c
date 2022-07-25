
#include <stdio.h>
#include <stdint.h>

unsigned zerosCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    unsigned count = 0;
    for (int bit = 0; bit < sizeof(uint64_t) * 8; bit++){
        if ((mask1 & (1UL << bit)) >> bit == 0)
        {
            count ++ ;
        }
        
    }
    for (int bit = 0; bit < sizeof(uint32_t) * 8; bit++){
        if ((mask2 & (1UL << bit)) >> bit == 0)
        {
            count ++ ;
        }
    }
    for (int bit = 0; bit < sizeof(uint16_t) * 8; bit++){
        if ((mask3 & (1UL << bit)) >> bit == 0)
        {
            count ++ ;
        }
    }
    for (int bit = 0; bit < sizeof(uint8_t) * 8; bit++){
        if ((mask4 & (1UL << bit)) >> bit == 0)
        {
            count ++ ;
        }
    }
    return count;
}

void flipOddBits(uint64_t* mask){
    for (int bit = 1; bit < sizeof(uint64_t) * 8; bit += 2){
       *mask ^= (1UL << bit);
    }
}

int main() {
   printf("Ones count: %u\n", zerosCount(0, 0, 0, 0));
   uint64_t mask = 0;
   flipOddBits(&mask);
 
    return 0;
}
   

