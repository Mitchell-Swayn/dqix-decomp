#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov003 @ 0x217f4f0; symbol: data_ov003_0217f4f0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000000000000307b160200000000347b1602000000009c7c160200000000a07c160200000000a47c160200000000a87c160200000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Receiver{};typedef void(Receiver::*Method)();struct Methods{Method entries[7];};extern "C" Methods CharacterStatusRefreshChangedDisplayMode_UnknownRoleProcedureReferenceRecords;extern "C" Method ShopUpdateInterface_UnknownRoleInitializedBytes;extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(void*);
// Original: arm9/ov003 @ 0x02167A5C; symbol: DispatchChangedDisplayModeMemberHandler; size: 0xD4.
extern "C" void CharacterStatus_RefreshChangedDisplayMode(char* self,int mode,int value){if(!B(self,0x74)||!P(self,0x10))return;if(W(self,0x70)==mode&&*(signed char*)(self+0x76)==value)return;if(W(self,0x70)!=mode||value<0)Graphics_UpdateCounted224ByteDisplayRecords(P(self,0x10));W(self,0x70)=mode;B(self,0x76)=value;Methods methods=CharacterStatusRefreshChangedDisplayMode_UnknownRoleProcedureReferenceRecords;methods.entries[0]=ShopUpdateInterface_UnknownRoleInitializedBytes;if(methods.entries[mode])(((Receiver*)self)->*methods.entries[mode])();}
