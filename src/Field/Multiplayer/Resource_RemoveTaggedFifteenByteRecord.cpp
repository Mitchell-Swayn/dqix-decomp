#include <globaldefs.h>
ARM
extern "C" void Field_CopyPartyJoinRecord(void*,void*);
// Original: arm9/ov017 @ 0x02195398; symbol: Resource_RemoveTaggedFifteenByteRecord; size: 0x84.
// Removes first matching tag and shifts following fifteen-byte records.
extern "C" void Resource_RemoveTaggedFifteenByteRecord(unsigned char* self,int tag) {
 for(int i=0;i<self[0x42f0];++i) if(*(unsigned char*)(self+15*i+0x42f1)==tag) {
 --self[0x42f0];
 for(;i<self[0x42f0];++i)Field_CopyPartyJoinRecord(self+0x42f1+15*i,self+0x42f1+15*(i+1));
 return;
 }
}
