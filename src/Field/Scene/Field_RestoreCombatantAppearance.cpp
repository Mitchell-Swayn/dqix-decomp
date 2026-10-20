#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" void Resource_SetIndexedObjectCodeAndApply(int);
extern "C" void Field_SetCombatantAlphaAndPaletteTint(void*,int,int,int,int);
extern "C" void Graphics_StagePartyObjectTexturesAfterDisplayWait(void*,int);
// Original: arm9/ov017 @ 0x02191F4C; symbol: ApplyCombatantObjectCodeOrDefault; size: 0xa0.
// Uses flagged combatant object code or default1000 and applies party-index followup.
extern "C" void Field_RestoreCombatantAppearance(void* p,int index){
 void* state=_ZN9GameState11GetInstanceEv();if(_ZN9GameState19GetCombatantByIndexEi(state,index)){
 char* object=GameState_GetObjectWithFlag100(state,index);
 if(object&&(*(unsigned*)(object+0x18c)&0x40))Resource_SetIndexedObjectCodeAndApply(index);
 else{Field_SetCombatantAlphaAndPaletteTint(p,index,0x1000,0,0);int party;if(index>=0&&index<=3)party=1;else party=0;if(party)Graphics_StagePartyObjectTexturesAfterDisplayWait(p,index);}}
}
