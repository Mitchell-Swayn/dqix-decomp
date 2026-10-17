#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" unsigned _fadd(unsigned,unsigned);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* GameState_GetValidObjectByIndex(void*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void* Object_FindResourceRecordByKeyCallback(void*,int);
extern "C" float ReadBoundedFiveEntryLookupTableOrZero(int);
extern "C" float Object_SumElevenPositiveEntryQuantitiesDividedByTen(int);
extern "C" int GameState_SumThreeSelectedAttributeValues(unsigned char*);
extern "C" int TestNestedStateWordBit0(void*);
extern "C" int ClassifyField81FE(unsigned char*);
struct RecordBits { unsigned pad:16,value:3,rest:13; };
// Original: arm9/ov000 @ 0x02156118; symbol: func_ov000_02156118; size: 0x140.
extern "C" float Combat_ComputeObjectAttributeWeight(unsigned char* self,int index) {
 if(ClassifyField81FE(self))return 0;
 void* game=_ZN9GameState11GetInstanceEv();
 void* combatant=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!combatant)return 0;
 float result;
 bool party;
 if(index>=0 && index<=3)party=true;else party=false;
 if(party) {
  void* object=GameState_GetObjectWithFlag100(game,index);
  if(!object)return 0;
  unsigned char* data=ReadWordFieldAtOffset150(object);
  if(!data)return 0;
  if(*(short*)(data+0x2cc)<=0)return 0;
  float initial=0.0f;
  float quantity=Object_SumElevenPositiveEntryQuantitiesDividedByTen((int)data);
  float selected=(float)GameState_SumThreeSelectedAttributeValues(data);
  result=selected+(initial+quantity);
 } else {
  unsigned char* object=(unsigned char*)GameState_GetValidObjectByIndex(game,index);
  if(!object)return 0;
  unsigned char* record=(unsigned char*)Object_FindResourceRecordByKeyCallback(*(unsigned char**)(self+0x8e18)+0x684,*(short*)(object+2));
  result=ReadBoundedFiveEntryLookupTableOrZero((signed char)((RecordBits*)(record+0x10))->value);
 }
 if(TestNestedStateWordBit0(combatant)) result=2.0f*result;
 return result;
}
