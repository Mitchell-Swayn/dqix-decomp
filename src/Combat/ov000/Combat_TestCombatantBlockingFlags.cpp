#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool Object_TestNestedOffset138Word14Bit0(void*);
extern "C" bool Object_TestElement5Mask10(unsigned int*);
extern "C" int TestNestedRecordFlag2000(char*);
extern "C" bool TestLinkedRecordFlag20(void*);
extern "C" int HasBit3AtNestedOffset14From138(void*);
extern "C" int func_ov000_02156050(void*);
// Original: arm9/ov000 @ 0x02155F9C; symbol: func_ov000_02155f9c; size: 0x9C.
extern "C" int Combat_TestCombatantBlockingFlags(void* unused,int index,int includeFlag20) {
unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
if(!object)return 1;
if(Object_TestNestedOffset138Word14Bit0(object) || TestNestedRecordFlag2000((char*)object) || HasBit3AtNestedOffset14From138(object) || Object_TestElement5Mask10(*(unsigned int**)(object+0x138)) || func_ov000_02156050(object))return 1;
if(includeFlag20 && TestLinkedRecordFlag20(object))return 1;
return 0;
}
