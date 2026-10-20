#include <globaldefs.h>
ARM
extern "C" unsigned Network_SendCurrentSocketPayloadSpans(void*,unsigned,void*,unsigned);
extern "C" void* memmove(void*,const void*,unsigned);
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02203A84; symbol: Network_ConsumeBufferedSendAndCompactRemainder; size: 0x98.
extern "C" unsigned Network_ConsumeBufferedSendAndCompactRemainder(void* input,unsigned length) {
 char* state=*(char**)(*(char**)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2+4)+0xa4);if(state){
 unsigned size=*(unsigned*)(state+0x60);if(size){unsigned used=Network_SendCurrentSocketPayloadSpans(*(void**)(state+0x5c),size,input,length);
 if(used<*(unsigned*)(state+0x60)){memmove(*(void**)(state+0x5c),*(char**)(state+0x5c)+used,*(unsigned*)(state+0x60)-used);*(unsigned*)(state+0x60)-=used;return 0;}
 unsigned prior=*(unsigned*)(state+0x60);*(unsigned*)(state+0x60)=0;return used-prior;
 }return Network_SendCurrentSocketPayloadSpans(input,length,0,0); }return 0;
}
