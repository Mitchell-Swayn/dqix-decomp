#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e234; symbol: data_ov031_0224e234.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e274; symbol: data_ov031_0224e274.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage[],NetworkConfigureSharedWorkWithSwappedWords_UnknownRoleZeroInitializedStorage[];
extern "C" void* Network_AllocateSizePrefixedBuffer(void*);
extern "C" void Network_FreeSizePrefixedBuffer(void*);
extern "C" int System_RegisterPendingWorkIfIdle(unsigned);
#pragma always_inline on
inline unsigned SwapWord(unsigned v){return ((v>>24)&255)|((v>>8)&0xff00)|((v<<8)&0xff0000)|((v<<24)&0xff000000);}
typedef void* (*AllocateCallback)(void*);
typedef void (*DispatchCallback)(void*);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0220764C; symbol: func_ov031_0220764c; size: 0x174.
// Copies request configuration, byte-swaps five network words and registers the shared work record.
extern "C" int Network_ConfigureSharedWorkWithSwappedWords(char* config){
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x40)=F(unsigned,config,0xc)==1;
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x44)=SwapWord(F(unsigned,config,0x10));
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x48)=SwapWord(F(unsigned,config,0x14));
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x4c)=SwapWord(F(unsigned,config,0x18));
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x50)=SwapWord(F(unsigned,config,0x1c));
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x54)=SwapWord(F(unsigned,config,0x20));
F(AllocateCallback,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x58)=Network_AllocateSizePrefixedBuffer;
F(DispatchCallback,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x5c)=Network_FreeSizePrefixedBuffer;
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0xc)=F(unsigned,config,4);
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,4)=F(unsigned,config,8);
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x60)=64;
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x70)=F(unsigned,config,0x2c);
F(unsigned,NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage,0x74)=F(unsigned,config,0x30);
return System_RegisterPendingWorkIfIdle((unsigned)NetworkConfigureSharedWorkWithSwappedWords_UnknownRoleZeroInitializedStorage);
}
