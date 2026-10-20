#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void OS_GetLowEntropyData(unsigned long*);extern "C" void Crypto_HashInputWithStaticSeed(const void*,unsigned);extern "C" int IsOverlayTaskAvailable();extern "C" char* YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02211138; symbol: HashEntropyAndDispatchCompletedCallback; size: 0xA8.
// Hashes low-entropy data then clears paired completion flags and dispatches the stored callback.
extern "C" void HashEntropyAndDispatchCompletedCallback(){unsigned long entropy[8];OS_GetLowEntropyData(entropy);Crypto_HashInputWithStaticSeed(entropy,32);if(IsOverlayTaskAvailable())return;char* object=YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;if(!object)return;if(*(unsigned*)object!=2)return;if(!*(unsigned*)(object+0x10)||!*(unsigned*)(object+0x30))return;*(unsigned*)(object+0x10)=0;*(unsigned*)(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage+0x30)=0;object=YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;void(*callback)(unsigned,unsigned,unsigned)=*(void(**)(unsigned,unsigned,unsigned))(object+0x40);if(callback)callback(*(unsigned*)(object+0x34),*(unsigned*)(object+0x38),*(unsigned*)(object+0x44));}
