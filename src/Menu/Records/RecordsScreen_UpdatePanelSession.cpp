#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
// Original data: arm9/ov008 @ 0x218b340; symbol: data_ov008_0218b340.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 4c4a1802000000009c59180200000000705a180200000000c05d1802000000008062180200000000c462180200000000e0621802000000005063180200000000 ...; full span in module reference.
// Observed span: 120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov008.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void _ZN13SafeAllocator7DestroyEv(void*);extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(void*);extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);extern "C" void Window_ClearResourceBuffers(unsigned char*);extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);extern "C" void Window_ResetResourceTransfers(void*);extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);struct Owner;typedef void(Owner::*Method)(unsigned);struct Methods{Method slots[15];};extern "C" const Methods RecordsScreenUpdatePanelSession_UnknownRoleProcedureReferenceRecords;extern "C" const Method ShopUpdateInterface_UnknownRoleInitializedBytes;extern "C" void RecordsScreen_BeginRequestedPanelClose(unsigned char*);extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);extern "C" int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);extern "C" void World_UpdateYawFromKeysOrTarget(char*,unsigned);extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);extern "C" void Graphics_RestartObjectAnimationWhenFlag0x4000SetAndEnded(unsigned char*);extern "C" void RecordsScreen_UpdateDisplayedElapsedTime(void*,int);extern "C" void ScriptListContext_UpdateExecution(void*);extern "C" void Menu_UpdateQueuedRecordPanel(unsigned char*);
// Original: arm9/ov008 @ 0x02184754; symbol: World_AdvancePanelStateAndDispatchCurrentMode; size: 0x124.
extern "C" int RecordsScreen_UpdatePanelSession(char* self){RecordsScreen_BeginRequestedPanelClose((unsigned char*)self);unsigned ticks=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());if(!ticks)ticks=1;Window_UpdateCanvasesAndSelection((unsigned char*)self+304,ticks);World_UpdateYawFromKeysOrTarget(self,ticks);_ZN8Object3D14AdvanceEffectsEv(self+1936);((void(*)(unsigned char*,unsigned))Graphics_RestartObjectAnimationWhenFlag0x4000SetAndEnded)((unsigned char*)self,ticks);RecordsScreen_UpdateDisplayedElapsedTime(self,0);RecordsScreen_UpdateDisplayedElapsedTime(self,1);Methods table=RecordsScreenUpdatePanelSession_UnknownRoleProcedureReferenceRecords;table.slots[14]=ShopUpdateInterface_UnknownRoleInitializedBytes;int index=S(self,2832);if(!table.slots[index])return 0;(((Owner*)self)->*table.slots[index])(ticks);if(P(self,2820))ScriptListContext_UpdateExecution(P(self,2820));if(P(self,2824))Menu_UpdateQueuedRecordPanel((unsigned char*)P(self,2824));return S(self,2832)==14;}
