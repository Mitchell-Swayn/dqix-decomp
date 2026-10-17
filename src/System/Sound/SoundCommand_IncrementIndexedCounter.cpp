#include <globaldefs.h>
extern "C" {
struct E{char pad[8];unsigned char count;char pad2[3];};extern E data_02114260[];
// Original: arm9/main @ 0x020D2960; symbol: func_020d2960; size: 0x20.
void SoundCommand_IncrementIndexedCounter(int i){E *p=data_02114260+i;p->count++;}
}
