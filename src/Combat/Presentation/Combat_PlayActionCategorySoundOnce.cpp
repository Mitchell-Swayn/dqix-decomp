#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags8{unsigned low:8;unsigned kind:2;unsigned high:22;};struct Flags24{unsigned low:5;unsigned mode:7;unsigned type:4;unsigned high:16;};extern "C" {unsigned BattleScene_GetActiveInstance();unsigned char* BattleScene_ResolveCurrentActionRecord(char*);void* ActionData_GetGlobalTables();void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);int Combat_IsDefaultOrSpecialPresentationAction(int);unsigned char* Combat_GetCommandActorSnapshot(void*,int);void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern char Main_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov025 @ 0x021EB6FC; symbol: Resource_DispatchLinkedRecordStateOnce; size: 0x100.
// Marks linked record processed and dispatches state7 or8 when forced by code or transformed flags.
extern "C" void Combat_PlayActionCategorySoundOnce(unsigned char* self,int force){if((W(self,0x1c4)&8)&&!force)return;unsigned char* record=BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());unsigned char* transformed=(unsigned char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),H(record,0));if(Combat_IsDefaultOrSpecialPresentationAction(U(record,0)))force=1;else if(transformed&&((Flags8*)(transformed+8))->kind==1&&((Flags24*)(transformed+24))->mode==1&&((Flags24*)(transformed+24))->type!=2)force=1;if(force){unsigned char* primary=Combat_GetCommandActorSnapshot(record,0);if(primary){int kind=U(primary,32);int valid;if(kind>=0&&kind<=3)valid=1;else valid=0;if(valid)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,7,0);else SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,8,0);}}W(self,0x1c4)|=8;}
