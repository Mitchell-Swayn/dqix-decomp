#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int Buffer_FindBigEndianValueByStride(unsigned char*,int,int,unsigned);
// Original data: arm9/ov031 @ 0x22496fc; symbol: data_ov031_022496fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04000500ffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short SslSendClientHello_UnknownRoleInitializedBytes[2];
// Original: arm9/ov031 @ 0x02208A40; symbol: func_ov031_02208a40; size: 0x60.
// Returns the first of two shared halfwords found in the strided big-endian buffer, or zero if neither is found.
extern "C" unsigned Buffer_FindFirstSharedHalfwordByStride(unsigned char* bytes,int count,int stride) {
 unsigned i=0;
 do {
 if(Buffer_FindBigEndianValueByStride(bytes,count,stride,SslSendClientHello_UnknownRoleInitializedBytes[i]))return SslSendClientHello_UnknownRoleInitializedBytes[i];
 ++i;
 }while(i<2);
 return 0;
}
