#include <globaldefs.h>
ARM
#pragma always_inline on
struct Image {unsigned header;void* records;char* base;};
inline char* ResolveRelativeOffset(Image* image,char* entry) {
 int offset=entry-(char*)0;
 int invalid=1;
 if(offset!=-1 && image->base) invalid=0;
 if(invalid)return 0;
 return image->base+offset;
}
// Original: arm9/ov012 @ 0x0218558C; symbol: func_ov012_0218558c; size: 0x64.
// Resolves counted record offsets against image base; null base or -1 sentinel becomes null.
extern "C" int ResolveCountedRecordOffsets(Image* image,char** entries) {
 for(int i=0;i<((unsigned char*)entries)[0x1e];i++) entries[i]=ResolveRelativeOffset(image,entries[i]);
 return 1;
}
