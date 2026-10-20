#include <globaldefs.h>
ARM
#pragma opt_common_subs off
// Original data: arm9/ov025 @ 0x21ef9a4; symbol: data_ov025_021ef9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" {unsigned BattleScene_GetActiveInstance();char* BattleScene_ResolveCurrentActionRecord(char*);void* Combat_GetIndexedActionTarget(void*,int);int Combat_GetLatestTargetFromHistory(char*);int Combat_AppendActionMessage(char*,unsigned short,short,int,void*,short,unsigned short);extern unsigned CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2;}
struct RecordFlags {unsigned char bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,rest:3;};
#define IsFourSlotIndex(value) (((value)>=0 && (value)<=3)?1:0)
// Original: arm9/ov025 @ 0x021EABD0; symbol: func_ov025_021eabd0; size: 0x18C.
// Chooses the first linked record matching index class and queues its presentation key.
extern "C" void AppendPresentationForLinkedIndexClass(char* self,int fourSlot) {
 char* record=BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());
 int index=-1;
 for(int i=0;i<(unsigned char)record[9];i++) {
 char* linked=(char*)Combat_GetIndexedActionTarget(record,i);if(!linked)continue;
 int candidate=Combat_GetLatestTargetFromHistory(linked);
 if(fourSlot){if(IsFourSlotIndex(candidate)){index=candidate;break;}}
 else {if(!IsFourSlotIndex(candidate)){index=candidate;break;}}
 }
 int kind=0;RecordFlags* flags=(RecordFlags*)(record+12);
 if(fourSlot && (flags->bit0 || flags->bit1))kind=5;
 else if(!fourSlot && (flags->bit3 || flags->bit4))kind=5;
 int key=IsFourSlotIndex(index)?*(unsigned short*)(record+26):*(unsigned short*)(record+28);
 Combat_AppendActionMessage(self+0x5e8,key,(short)index,kind,0,-1,0);
 self[0x5cc]=1;
 if(fourSlot)CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2|=0x800;else CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2|=0x4000;
}
