#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D2FF0; symbol: func_020d2ff0; size: 0x28.
    unsigned int String_CountBytesUntilTerminator(const signed char *str){
        unsigned int count=0;
        if(str[0])do{
            count++;
        }while(str[count]);
        return count;
    }
}
