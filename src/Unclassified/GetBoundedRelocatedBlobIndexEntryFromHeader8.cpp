#include <globaldefs.h>
extern "C" unsigned int* data_02110370[];
// Original: arm9/main @ 0x020BD454; symbol: func_020bd454; size: 0x64.
extern "C" int GetBoundedRelocatedBlobIndexEntryFromHeader8(unsigned int index) {
    char* owner=(char*)data_02110370[0];
    volatile int* rootSlot=(volatile int*)(owner+0x8C);
    int* root=(int*)rootSlot[0];
    int offset=*(int*)((char*)root+8);
    int* table=offset==0 ? 0 : (int*)((char*)root+offset);
    if(table==0) return 0;
    if((int)index<0) return 0;
    if(index >= (unsigned int)table[0]) return 0;
    int relative=*(int*)((char*)table + (index << 2) + 4);
    int baseValue=rootSlot[0];
    if(relative==0) return 0;
    return baseValue+relative;
}
