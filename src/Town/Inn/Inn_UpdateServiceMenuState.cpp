#include <globaldefs.h>
ARM
class GameState;
struct DisplayState { typedef void (DisplayState::*Handler)(); };
struct HandlerTable { DisplayState::Handler entries[8]; };
// Original data: arm9/ov003 @ 0x217f578; symbol: data_ov003_0217f578.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 7cb0160200000000bcb716020000000068b916020000000070bb160200000000fcbc1602000000000cc0160200000000f0d31602000000000000000000000000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" HandlerTable InnUpdateServiceMenuState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" DisplayState::Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
extern "C" void Inn_ReleaseStayDialogResources(char*);
extern "C" int Inn_UpdateStayDialog(char*,int);
extern "C" void Inn_ResetServiceMenuAndSharedText(void*);
extern "C" void AdvanceFlaggedDisplayCommandState(unsigned char*);
// Original: arm9/ov003 @ 0x0216AF14; symbol: func_ov003_0216af14; size: 0x168.
// Processes panel shutdown and pending commands before dispatching the indexed member handler.
extern "C" int Inn_UpdateServiceMenuState(char* p) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 if((unsigned char)p[0x13ec]&2) {
 if(*(short*)(p+4)==3) {
 if(Inn_UpdateStayDialog(p+0x14,1)!=1) return 1;
 Inn_ReleaseStayDialogResources(p+0x14);
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x12d4);
 if(allocation) { _ZN13SafeAllocator7DestroyEv(p+0x12d4); Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation); }
 }
 Inn_ResetServiceMenuAndSharedText(p);return 0;
 }
 if(((unsigned char*)p)[0x13ea]) { AdvanceFlaggedDisplayCommandState((unsigned char*)p); if((unsigned char)p[0x13ec]&1)return 1; }
 unsigned tick=_ZNK9GameState12GetTickCountEv(game);
 if(*(unsigned char**)(p+0x12c0) && *(short*)(p+4)==2)
 *(int*)(p+0x10)=Window_UpdateCanvasesAndSelection(*(unsigned char**)(p+0x12c0),tick);
 HandlerTable table=InnUpdateServiceMenuState_UnknownRoleProcedureReferenceRecords;table.entries[7]=ShopUpdateInterface_UnknownRoleInitializedBytes;
 if(!table.entries[*(short*)(p+4)])return 0;
 (((DisplayState*)p)->*table.entries[*(short*)(p+4)])();return 1;
}
