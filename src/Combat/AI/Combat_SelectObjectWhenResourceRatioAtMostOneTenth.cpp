#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
#pragma opt_propagation off
#pragma opt_common_subs off
// Original: arm9/ov024 @ 0x021F3248; symbol: func_ov024_021f3248; size: 0x6C.
// Selects the indexed object when its descriptor halfword ratio does not exceed one tenth.
extern "C" int Combat_SelectObjectWhenResourceRatioAtMostOneTenth(void** owner,int index,int unused,int* selected,short* selectedIndex) {
 GameObject* object=Combat_FindIndexedMonsterObject(*owner,index);
 if(!object)return 0;
 unsigned short* descriptor=*(unsigned short**)((unsigned char*)object+0x138);
 unsigned maximum=descriptor[3];
 unsigned current=descriptor[1];
 float ratio=(float)current/(float)maximum;
 if(ratio>0.1f)return 0;
 *selected=1;*selectedIndex=index;
 return 1;
}
