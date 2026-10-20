#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern unsigned GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov016 @ 0x2195f78; symbol: data_ov016_02195f78.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ba0500ea000100009e000000e8490000944a0000204c0000604d0000744f0000b4500000b8520000e8530000044a0000ec4a0000644c0000dc4d0000b84f0000 ...; full span in module reference.
// Observed span: 26012 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern unsigned char GetOrCopyDataBlock_UnknownRoleInitializedBytes[];
void MIi_CpuCopyFast(const void*,void*,unsigned);
}
// Original: arm9/ov016 @ 0x0218FCD4; symbol: func_ov016_0218fcd4; size: 0x7C.
extern "C" void* GetOrCopyDataBlock() {
 if(!GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[2]) {
  if(GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[5]>=0x659c) {
   GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[2]=GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[6];
   MIi_CpuCopyFast(GetOrCopyDataBlock_UnknownRoleInitializedBytes,(void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[6],0x659c);
   GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[6]+=0x659c;
   GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[5]-=0x659c;
  } else return GetOrCopyDataBlock_UnknownRoleInitializedBytes;
 }
 return (void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[2];
}
