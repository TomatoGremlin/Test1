#include <stdio.h>
#include <stdarg.h> 

size_t onesCount (size_t count, ...){
    size_t ones = 0;
    va_list args;
    va_start(args,count);

    for (int i = 0; i < count; i++){
        int mask = va_arg(args, int);
        for (size_t j = 0; j < sizeof(mask)*8; j++){
            if(mask & (1ull << j)){
                ones ++ ;
            }
        }
    }
    va_end(args);
    printf("%d\n", ones );
    return ones;
}

int main() {
    onesCount (4, 0x0a, 0, 1, 2);
    onesCount (3, 0xff, 0x131, 0xaaaa);
    onesCount (2, 0b0001, 9);
    return 0;
}


