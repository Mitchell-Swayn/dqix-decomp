#pragma thumb off
struct Pool {char pad[0x5e00];unsigned char count,used;char pad2[2];void* slots[1];};
// Original: arm9/ov000 @ 0x021673E0; symbol: func_ov000_021673e0; size: 0x54.
extern "C" void* Memory_ClaimFirstAvailablePoolSlot(Pool* pool) {
 for(int i=0;i<pool->count;i++) {
  if(!(pool->used&(1<<i))) {
   pool->used|=1<<i;
   return pool->slots[i];
  }
 }
 return 0;
}
