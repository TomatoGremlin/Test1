#include <stdio.h>
#include <stdint.h>
#define INT_SIZE sizeof(int) * 8

void  flopOddBits(uint64_t mask)
{
    for(int i=0; i<32; i+=2){
        int i_bit = ( mask >> i ) & 1; 
        int i_1_bit = (mask >> ( i+1 )) & 1;  
         
        mask = mask - ( i_bit << i) - ( i_1_bit << ( i+1 ) ) + ( i_bit << ( i+1 ) ) + ( i_1_bit << i );  

    }
   
}
 
void zerosCount()
{
    
    int num, zeros, ones, i;

    printf("Enter any number: ");
    scanf("%d", &num);

    zeros = 0;

    for(i=0; i<INT_SIZE; i++)
    {   
        if(!(num & 1))
            zeros++;

        num >>= 1;
    }

    printf("Total zero bit is %d\n", zeros);

    return 0;
}
 

int main()
{
    
 
    return 0;
}