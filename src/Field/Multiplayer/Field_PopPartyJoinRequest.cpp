#include <globaldefs.h>
ARM
extern "C" void Field_CopyPartyJoinRecord(void*,void*);
// Original: arm9/ov017 @ 0x0219531C; symbol: PopFrontFifteenByteRecord; size: 0x7c.
// Removes the first 15-byte record and shifts the remaining counted records.
extern "C" int Field_PopPartyJoinRequest(unsigned char* p, void* out) {
 if(!p[0x42f0]) return 0;
 Field_CopyPartyJoinRecord(out,p+0x42f1);
 --p[0x42f0];
 for(int i=0;i<p[0x42f0];++i) Field_CopyPartyJoinRecord(p+0x42f1+15*i,p+0x42f1+15*(i+1));
 return 1;
}
