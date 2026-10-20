#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" int SaveData_ReadCardSaveBytes(int,void*,unsigned,int);extern "C" void SaveData_WriteBackupBytes(unsigned,void*,unsigned,int);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x020ABCA8; symbol: func_020abca8; size: 0x78.
extern "C" ARM int SaveData_CopyPrimaryBankBodyToMirror(){char* state=_ZN9GameState11GetInstanceEv();int result=0;state[0x5cc8]=0;void* memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x6fe4);if(memory){result=SaveData_ReadCardSaveBytes(16,memory,0x6fe4,0);if(result)SaveData_WriteBackupBytes(0x8010,memory,0x6fe4,0);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,memory);}return result;}
