#include <globaldefs.h>
ARM
extern "C" {int GameState_UpdatePartyTransitionDialogue(void*,int);void BackgroundLoader_CancelTaskAndDestroyDisplayAllocator(void*);void BattleMenu_RefreshExistingPanel(void*,int,int,int,int,int);void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);}
// Original: arm9/ov000 @ 0x0217DE64; symbol: CancelSelectionTaskAndPopHistory; size: 0xa4.
// Cancels completed task, pops signed-byte selection history and restarts prior entry.
extern "C" void BattleMenu_FinishPartyTransitionDialogue(char* self,int a,int b){*(unsigned short*)(self+0x1d72)&=~0x100;if(GameState_UpdatePartyTransitionDialogue(self+0x7c,*(int*)(self+0x94c))){BackgroundLoader_CancelTaskAndDestroyDisplayAllocator(self+0x7c);*(char*)((self+(signed char)self[0x1d68])+0x1d60)=0;--self[0x1d68];BattleMenu_RefreshExistingPanel(self,0,(signed char)*(char*)((self+(signed char)self[0x1d68])+0x1d60),a,b,0);BattleMenu_ConfigureGlobalCommandSelection(self,a,b);}}
