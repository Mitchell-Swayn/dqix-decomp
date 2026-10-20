#include <globaldefs.h>
ARM
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
struct Entry {unsigned char key[32];unsigned char value[48];int pad;int busy;unsigned short pending;unsigned char ready;unsigned char pad2;};
// Original data: arm9/ov031 @ 0x224e3b8; symbol: data_ov031_0224e3b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 368 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Entry MemoryZeroBlock170_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02207A10; symbol: func_ov031_02207a10; size: 0x94.
extern "C" void SslSessionCache_RestoreMasterSecret(unsigned char* p){
 int i;
 int irq=_Z20DisableIRQInterruptsv();
 p[0x30]=0;
 Entry* entry=MemoryZeroBlock170_UnknownRoleZeroInitializedStorage;
 for(i=0;i<4;i++,entry++){
 if(entry->ready && !entry->busy && !entry->pending && !RuntimeMemory_CompareByteRanges(entry,p+0x74,32)){
 MI_CpuCopy8(entry->value,p,48);
 p[0x30]=1;
 break;
 }
 }
 _Z20SetIRQInterruptStatei(irq);
}
