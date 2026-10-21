#include <globaldefs.h>
ARM
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" char* BattleMenu_FindPartyCommandRecord(char*,int);
extern "C" int BattleMenu_ResolveActionTargetSelectionState(char*,char*);
// Original: arm9/ov000 @ 0x02175B54; symbol: AppendTransformedRecordResult; size: 0x90.
// Appends transformed-record result using current party index and copies signed byte 1d.
extern "C" void BattleMenu_PushActionDefinitionSelectionState(char* p) {
 void* global=ActionData_GetGlobalTables();
 if(!global)return;
 char* transformed=(char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)global,*(short*)(p+0x10+*(signed char*)(p+0x1d6d)*2));
 if(!transformed)return;
 char* r=BattleMenu_FindPartyCommandRecord(p,*(signed char*)(GameState_GetIndexList(_ZN9GameState11GetInstanceEv())+0xf78));
 if(!r)return;
 *(signed char*)(p+0x1d68)=*(signed char*)(p+0x1d68)+1;
 int value=BattleMenu_ResolveActionTargetSelectionState(transformed,r);
 *(signed char*)(p+*(signed char*)(p+0x1d68)+0x1d60)=value;
 *(signed char*)(p+0x1c)=*(signed char*)(r+0x1d);
}
