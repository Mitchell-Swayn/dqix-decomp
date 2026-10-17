#include <globaldefs.h>
struct Entry { char pad[8]; short id; char pad2[8]; unsigned char nibble:4; unsigned char other:4; };
extern "C" Entry* FindNonnegativeKeyInCountedRecordArray(char*,int);
extern "C" char* FindTwoHundredTwentyFourByteRecordByByteKey(char*,int);
// Original: arm9/main @ 0x02080C68; symbol: func_02080c68; size: 0x58.
extern "C" ARM void Object_SetGroupNibbleAndTextureLowFourBits(char* self,int id,unsigned char value) {
 Entry* entry=FindNonnegativeKeyInCountedRecordArray(self+12,id); if (!entry) return;
 entry->nibble=value;
 char* output=FindTwoHundredTwentyFourByteRecordByByteKey(self,entry->id);
 if (output) *(unsigned short*)(output+0xc2)=entry->nibble & 15;
}
