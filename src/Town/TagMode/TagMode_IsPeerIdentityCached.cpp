#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" int Util_AreFirstSixBytesZero(const unsigned char*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
struct CachedPeerIdentityView {unsigned char identity[6],active,pad;};
// Original: arm9/ov003 @ 0x02171D78; symbol: func_ov003_02171d78; size: 0x78.
extern "C" int TagMode_IsPeerIdentityCached(void* menu,const unsigned char* identity) {
    if(!identity || Util_AreFirstSixBytesZero(identity)) return 0;
    CachedPeerIdentityView* record=(CachedPeerIdentityView*)((char*)menu+8);
    for(int i=0;i<50;i++,record++) {
        if(record->active && RuntimeMemory_CompareByteRanges(record->identity,identity,6)==0) return 1;
    }
    return 0;
}
