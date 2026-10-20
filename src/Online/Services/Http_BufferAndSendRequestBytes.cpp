#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291a04; symbol: data_ov031_02291a04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 9 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void Memory_CopyBytesToDestination(void*,const void*,unsigned int);
extern "C" int Http_SendSocketBytes(unsigned char*,int,const void*,int,int);
// Original: arm9/ov031 @ 0x022415E0; symbol: func_ov031_022415e0; size: 0xB4.
extern "C" int Http_BufferAndSendRequestBytes(unsigned char* context,int handle,int* buffered,const unsigned char* source,int length) {
int remaining=length;
if(remaining>0)do {
if(*(int*)(context+4))return -1;
int size=0x400-*buffered;
if(remaining<=size)size=remaining;
Memory_CopyBytesToDestination(HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant4+*buffered,source,size);
*buffered+=size;source+=size;remaining-=size;
if(*buffered==0x400){int result=Http_SendSocketBytes(context,handle,HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant4,0x400,0);if(result<=0)return result;*buffered-=result;}
}while(remaining>0);
return length;
}
