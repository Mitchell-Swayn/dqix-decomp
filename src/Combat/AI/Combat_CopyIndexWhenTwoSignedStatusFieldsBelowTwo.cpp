#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject *Combat_FindIndexedMonsterObject(void *,int);
struct TwoSignedStatusFields {unsigned low:12;signed first:3;signed second:3;unsigned high:14;};
// Original: arm9/ov024 @ 0x021F40C8; symbol: func_ov024_021f40c8; size: 0x58.
// Copies the index when both signed three-bit fields at nested word 0x58 are below two.
extern "C" int Combat_CopyIndexWhenTwoSignedStatusFieldsBelowTwo(void **self,int index,int unused,int *count,short *output) {
 GameObject *object=Combat_FindIndexedMonsterObject(*self,index);
 if(!object)return 0;
 TwoSignedStatusFields *status=(TwoSignedStatusFields *)(*(char **)((char *)object+0x138)+0x58);
 if(status->first>=2 || status->second>=2)return 0;
 *count=1;*output=index;
 return 1;
}
