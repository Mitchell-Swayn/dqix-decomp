#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
struct Slot {unsigned char data[16];signed char mark;char pad[3];};
struct Owner {char pad[0xf2c];Slot slots[3];};
// Original: arm9/main @ 0x02087510; symbol: func_02087510; size: 0x64.
extern "C" int CopySixteenBytesIntoFirstFreeOfThreeSlots(Owner* p,unsigned char value,void* data) {
    for(int i=0;i<3;++i) {
        if(p->slots[i].mark<0) {
            memcpy(p->slots[i].data,data,16);
            p->slots[i].mark=value;
            return 1;
        }
    }
    return 0;
}
