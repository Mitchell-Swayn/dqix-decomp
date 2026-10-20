#include <globaldefs.h>
ARM
extern "C" {int BattleMenu_FindNextPartyNeedingCommand(void*);char* BattleMenu_FindPartyCommandRecord(void*,int);void InitializeObjectAndConfigureSelectionIfPresent(void*,unsigned);void BattleMenu_RefreshSelectedPartyPanelExpansion(void*);void BattleMenu_RepositionCommandWindowsAroundActor(void*);}
// Original: arm9/ov000 @ 0x0217F62C; symbol: ResetSelectedFourSlotRecordState; size: 0x90.
// Validates four-slot index, restores field4C and clears selection counters and flags38.
extern "C" int BattleMenu_SelectNextPartyCommandAndResetTransition(char* self){int i=BattleMenu_FindNextPartyNeedingCommand(self);int valid;if(i>=0 && i<=3)valid=1;else valid=0;if(valid){char* p=BattleMenu_FindPartyCommandRecord(self,i);if(p){*(int*)(self+0x17c)=*(int*)(p+0x4c);InitializeObjectAndConfigureSelectionIfPresent(p,0);*(int*)(self+0x910)=0;*(int*)(self+0x914)=0;*(int*)(self+0x918)=0;*(int*)(self+0x91c)=0;*(unsigned short*)(self+0x1d72)&=~0x38;BattleMenu_RefreshSelectedPartyPanelExpansion(self);BattleMenu_RepositionCommandWindowsAroundActor(self);return 0;}}return 1;}
