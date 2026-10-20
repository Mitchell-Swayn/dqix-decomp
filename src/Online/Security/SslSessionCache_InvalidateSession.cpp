#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
struct KeyRecord{unsigned char bytes[0x5a];unsigned char active;unsigned char padding;};
// Original data: arm9/ov031 @ 0x224e3b8; symbol: data_ov031_0224e3b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 368 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" KeyRecord MemoryZeroBlock170_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02207C30; symbol: func_ov031_02207c30; size: 0x68.
// Clears the first active table entry whose first32 bytes match owner+74,
// protecting the four-entry search with the original IRQ state save/restore.
extern "C" void SslSessionCache_InvalidateSession(const unsigned char* owner){
 int i;
 int irq=DisableIRQInterrupts();
 KeyRecord* record=MemoryZeroBlock170_UnknownRoleZeroInitializedStorage;
 i=0;
 do{
  if(record->active && !RuntimeMemory_CompareByteRanges(record,owner+0x74,32)){
   record->active=0;break;
  }
  i++;record++;
 }while(i<4);
 SetIRQInterruptState(irq);
}
