#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov023 @ 0x021DB4E4; symbol: func_ov023_021db4e4; size: 0x60.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" char* FindTwentyFourByteRecordBySignedKey(char* p,int key) {
    char* table=*(char**)(p+8);
    if(!table)return 0;
    unsigned count=*(unsigned short*)(p+20);
    if(!count)return 0;
    for(unsigned short i=0;i<count;i++) {
        char* entry=table+i*24;
        if(*(short*)entry==key)return entry;
    }
    return 0;
}
