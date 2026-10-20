#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
// Original: arm9/ov024 @ 0x021F24FC; symbol: func_ov024_021f24fc; size: 0x4C.
// Copies the supplied value when signed bits 24 through 26 of nested status are below two.
extern "C" int Combat_CopyValueWhenIndexedObjectModeBelowTwo(void** self,int value,int unused,int* result,short* output) {
 GameObject* object=Combat_FindIndexedMonsterObject(*self,value);
 if (!object) return 0;
 char* nested=*(char**)((char*)object+0x138);
 int mode=(*(int*)(nested+0x58)<<5)>>29;
 if(mode>=2) return 0;
 *output=value;*result=1;
 return 1;
}
