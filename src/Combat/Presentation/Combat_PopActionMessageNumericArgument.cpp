#include <globaldefs.h>
ARM
struct PairedEntryQueue { unsigned char pad[0xf0]; unsigned words[16]; unsigned char bytes[32]; unsigned char unknown150; unsigned char count; };
// Original: arm9/ov025 @ 0x021ED2A0; symbol: func_ov025_021ed2a0; size: 0x54.
// Removes the first paired word/byte entry by shifting the remaining entries down.
extern "C" void Combat_PopActionMessageNumericArgument(PairedEntryQueue* queue) {
 if(!queue->count)return;
 --queue->count;
 for(int i=0;i<queue->count;i++) {
  queue->words[i]=queue->words[i+1];
  queue->bytes[i]=queue->bytes[i+1];
 }
}
