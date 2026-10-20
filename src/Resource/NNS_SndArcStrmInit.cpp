#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <System/Mutex.h>
#include <Filesystem/NitroVM.h>
// Original data: arm9/main @ 0x21103b0; symbol: data_021103b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21103bc; symbol: data_021103bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21103c8; symbol: data_021103c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21103e0; symbol: data_021103e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 384 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110560; symbol: data_02110560.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1224 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110a4c; symbol: data_02110a4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1492 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111020; symbol: data_02111020.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 512 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
void NitroVM_Initialize(NitroVM*);extern "C" unsigned NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[];extern "C" SignedAllocatorList NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2;extern "C" char NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant4[],NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant7[],NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6[],NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant5[];extern "C" Mutex NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant3;extern "C" void NNS_SndArcStrmSetupPlayer(unsigned);extern "C" void InitializeGlobalCallbacksAndOwnerFlagFields(void*);extern "C" void SoundStream_CreateLoadingThread(void*,unsigned);
// Original: arm9/main @ 0x020BE9E8; symbol: func_020be9e8; size: 0x104.
extern "C" ARM void NNS_SndArcStrmInit(unsigned value,unsigned mode){if(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[0]){NNS_SndArcStrmSetupPlayer(mode);return;}NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[0]=1;NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2.Initialize(0);for(int i=0;i<8;i++)NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2.InsertAtEnd((SignedAllocatorHeader*)(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant4+i*0x30));ZeroInitializeMutex(&NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant3);NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[2]=(unsigned)NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant7;for(int i=0;i<4;i++){char* p=NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6+i*0x174;*(unsigned*)(p+0x110)&=~1;NitroVM_Initialize((NitroVM*)(p+0x5c));InitializeGlobalCallbacksAndOwnerFlagFields(p);*(int*)(p+0x148)=i;p[0x124]=0;*(unsigned*)(p+0x12c)=0;*(unsigned*)(p+0x130)=0;*(unsigned*)(p+0x120)=0;}NNS_SndArcStrmSetupPlayer(mode);SoundStream_CreateLoadingThread(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant5,value);}
