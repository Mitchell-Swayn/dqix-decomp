#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov003 @ 0x217fbc8; symbol: data_ov003_0217fbc8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 10cf1702000000003cd5170200000000acd6170200000000d8d91702000000000000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Receiver{};typedef void(Receiver::*Method)();struct Methods{Method entries[5];};extern "C" Methods TownUpdateDestinationMenu_UnknownRoleProcedureReferenceRecords;extern "C" Method ShopUpdateInterface_UnknownRoleInitializedBytes;extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);extern "C" void UpdateDisplayCommandState(void*);extern "C" int Window_UpdateCanvasesAndSelection(void*,unsigned);
// Original: arm9/ov003 @ 0x0217CE3C; symbol: UpdateDisplayAndDispatchCurrentMemberHandler; size: 0xD4.
extern "C" int Town_UpdateDestinationMenu(char* self){void* game=_ZN9GameState11GetInstanceEv();UpdateDisplayCommandState(self);if(U(self,8)&1)return 1;unsigned ticks=_ZNK9GameState12GetTickCountEv(game);if(P(self,0x90))W(self,0x14)=Window_UpdateCanvasesAndSelection(P(self,0x90),ticks);Methods methods=TownUpdateDestinationMenu_UnknownRoleProcedureReferenceRecords;methods.entries[4]=ShopUpdateInterface_UnknownRoleInitializedBytes;int mode=*(signed char*)(self+4);if(!methods.entries[mode])return 0;(((Receiver*)self)->*methods.entries[mode])();return 1;}
