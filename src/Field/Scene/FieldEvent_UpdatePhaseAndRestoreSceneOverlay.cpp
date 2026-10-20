#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
struct Owner {int Method(int);};typedef int(Owner::*Method)(int);
// Original data: arm9/ov017 @ 0x21d845c; symbol: data_ov017_021d845c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Method ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/ov017 @ 0x21d7ccc; symbol: data_ov017_021d7ccc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 10bc1b0200000000c4bf1b0200000000a852150200000000e057150200000000545d150200000000b06415020000000034651502000000005865150200000000 ...; full span in module reference.
// Observed span: 160 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Method FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleProcedureReferenceRecords[];
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(...);
extern "C" unsigned GameResources_GetMaskedPrimaryFlags(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(...);
extern "C" unsigned QuestMessagePanel_UpdateAndDrawIndicators(...);
extern "C" unsigned FileCache_RestoreRomTablesIfSpaceAvailable(...);
// Original: arm9/ov017 @ 0x021bb1a4; symbol: GameState_DispatchMemberStateAndMaybeRestoreOverlay; size: 0xd8.
extern "C" void FieldEvent_UpdatePhaseAndRestoreSceneOverlay(unsigned address,int argument){
Owner* self=(Owner*)address;if(!(FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleZeroInitializedStorage&1)){FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleProcedureReferenceRecords[19]=ShopUpdateInterface_UnknownRoleInitializedBytes;FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleZeroInitializedStorage|=1;}
if(U32(address+0x120))QuestMessagePanel_UpdateAndDrawIndicators(U32(address+0x120),_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv()));
if(FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleProcedureReferenceRecords[U16(address+10)])U16(address+10)=(self->*FieldEventUpdatePhaseAndRestoreSceneOverlay_UnknownRoleProcedureReferenceRecords[U16(address+10)])(argument);
if(U8(address+0xff)){if(!GameResources_GetMaskedPrimaryFlags(GameResources_GetInstance(),0x1000)){OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);FileCache_RestoreRomTablesIfSpaceAvailable();}}
}