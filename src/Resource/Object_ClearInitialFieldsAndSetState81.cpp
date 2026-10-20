// Original field/callee argument semantics reviewed; absolute values here are hardware MMIO.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20e73b4; symbol: data_020e73b4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff000021000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108da8; symbol: data_02108da8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Bits{unsigned char a:1,b:1,c:6;};extern "C" {void* memcpy(void*,const void*,unsigned);int Network_BeginPeerDiscovery(void*,void*,unsigned short);extern char Network_ProcessDiscoveredPeerAdvertisement[],SetStateThreeAndRegisterGlobalCallback_UnknownRoleInitializedBytes[];void CombatantState_ClearEerieLight(void*);void DisplaySpriteAnimation_ResetPlayback(void*);int CombatantState_IsEligibleForLinkedCombatEffect(void*);void ScriptValueTable_AllocateRecords(void*,void*,unsigned short);void CharacterTemplate_AllocateEntries(void*,void*,short);extern void* ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage[],*ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[];}
#pragma optimization_level 4
// Original: arm9/main @ 0x020DDE3C; symbol: func_020dde3c; size: 0x28.
extern "C" void Object_ClearInitialFieldsAndSetState81(char* p){*(int*)(p+8)=0;*(int*)(p+12)=0;*(short*)p=0;*(short*)(p+2)=0;*(int*)(p+32)=81;DisplaySpriteAnimation_ResetPlayback(p);}
