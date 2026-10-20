#include <globaldefs.h>
struct Pair { unsigned short key,value; };
struct Lookup { unsigned short first; unsigned short pad2; unsigned short mode; unsigned short pad6[3]; unsigned short payload[1]; };
// Original: arm9/main @ 0x020B0D80; symbol: func_020b0d80; size: 0xC8.
extern "C" ARM unsigned short Font_MapCharacterInRange(Lookup* table, unsigned short key) {
    unsigned short value=0xffff;
    switch(table->mode) {
    case 0: value=table->payload[0]+(key-table->first); break;
    case 1: value=table->payload[key-table->first]; break;
    case 2: {
        Pair* low=(Pair*)(table->payload+1);
        Pair* high=low+(table->payload[0]-1);
        if(low<=high) do {
            Pair* middle=low+(high-low)/2;
            if(middle->key<key) low=middle+1;
            else if(key<middle->key) high=middle-1;
            else { value=middle->value; break; }
        } while(low<=high);
        break;
    }
    }
    return value;
}
