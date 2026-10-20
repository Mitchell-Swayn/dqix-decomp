#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x11a]; unsigned char phase,selection; };
typedef void (State::*Handler)();
struct Table { Handler handlers[4]; };
// Original data: arm9/ov023 @ 0x21fd510; symbol: data_ov023_021fd510.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex a08e1d02000000002c8f1d0200000000d0901d02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { void* _ZN9GameState11GetInstanceEv(); unsigned _ZNK9GameState12GetTickCountEv(void*); int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned); extern Table GraphicsUpdateSelectionAndDispatchPhase_UnknownRoleProcedureReferenceRecords; extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes; }
// Original: arm9/ov023 @ 0x021D8BB4; symbol: func_ov023_021d8bb4; size: 0xAC.
extern "C" int Graphics_UpdateSelectionAndDispatchPhase(State* state) {
 unsigned tick=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
 if(tick==0) tick=1;
 if(state->selection==255) Window_UpdateCanvasesAndSelection((unsigned char*)state+0x20,tick);
 Table table=GraphicsUpdateSelectionAndDispatchPhase_UnknownRoleProcedureReferenceRecords;
 table.handlers[3]=ShopUpdateInterface_UnknownRoleInitializedBytes;
 if(!table.handlers[state->phase]) return 0;
 (state->*table.handlers[state->phase])();
 return 0;
}
