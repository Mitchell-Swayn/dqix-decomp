#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct Buffer {char pad[8];unsigned char state;char pad2[0x33];unsigned capacity;char* data;unsigned size;};
extern "C" unsigned System_WaitForPendingResult(unsigned*,char*);
extern "C" void ConsumeBufferBytesAndNotify(unsigned,Buffer*);
// Original: arm9/ov031 @ 0x02209840; symbol: func_ov031_02209840; size: 0x6C.
// Copies capped pending chunks, notifies consumption, and returns -1 if a wait
// provides no bytes. The original performs the initial wait even for zero length.
extern "C" int Network_CopyPendingBufferChunks(char* destination,int remaining,Buffer* buffer) {
 unsigned available;
 do {
  unsigned source=System_WaitForPendingResult(&available,(char*)buffer);
  if(!available)return -1;
  if(available>(unsigned)remaining)available=remaining;
  MI_CpuCopy8((const void*)source,destination,available);
  ConsumeBufferBytesAndNotify(available,buffer);
  remaining-=available;destination+=available;
 }while(remaining>0);
 return 0;
}
