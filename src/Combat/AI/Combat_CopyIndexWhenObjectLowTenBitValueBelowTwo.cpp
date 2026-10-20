#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject *Combat_FindIndexedMonsterObject(void *,int);
struct LowTenBitValue {unsigned value:10;unsigned other:22;};
// Original: arm9/ov024 @ 0x021F4120; symbol: func_ov024_021f4120; size: 0x54.
// Copies the requested index to the output when its flagged object's nested low ten-bit field is below two.
extern "C" int Combat_CopyIndexWhenObjectLowTenBitValueBelowTwo(void **self,int index,int unused,int *count,short *output) {
 GameObject *object=Combat_FindIndexedMonsterObject(*self,index);
 if(!object)return 0;
 unsigned short value=((LowTenBitValue *)(*(char **)((char *)object+0x138)+0x10))->value;
 if(value>=2)return 0;
 *count=1;*output=index;
 return 1;
}
