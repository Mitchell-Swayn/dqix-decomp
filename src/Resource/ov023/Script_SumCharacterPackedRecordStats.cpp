#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(char*);
extern "C" char* ResolveCharacterBySignedSelector(int);
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
extern "C" void __clear(void*,unsigned);
struct PackedStats {unsigned pad[6];signed int a:10;signed int b:10;signed int c:10;unsigned int r:2;signed int d:10;signed int e:10;signed int f:10;unsigned int r2:2;};
struct Slot {PackedStats* record;char pad[28];};
// Original: arm9/ov023 @ 0x021E96A8; symbol: func_ov023_021e96a8; size: 0x170.
extern "C" int Script_SumCharacterPackedRecordStats(char* params) {
 _ZN9GameState11GetInstanceEv();
 char* character=ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(params));
 if(!character)return 0;
 int totals[6];__clear(totals,24);
 for(int i=0;i<11;i++) {
  Slot* slot=(Slot*)(*(char**)(character+0x150)+0x194)+(unsigned char)i;
  if(slot && slot->record) {
   PackedStats* p=slot->record;
   totals[0]+=p->a;totals[1]+=p->b;totals[2]+=p->c;
   totals[3]+=p->d;totals[4]+=p->e;totals[5]+=p->f;
  }
 }
 switch(ReadScriptParameterAsInteger(params+8)) {
 case 0:SetNestedSecondWordForTypeThree(params+16,totals[4]);break;
 case 1:SetNestedSecondWordForTypeThree(params+16,totals[0]);break;
 case 2:SetNestedSecondWordForTypeThree(params+16,totals[1]);break;
 case 3:SetNestedSecondWordForTypeThree(params+16,totals[2]);break;
 case 4:SetNestedSecondWordForTypeThree(params+16,totals[3]);break;
 case 5:SetNestedSecondWordForTypeThree(params+16,totals[5]);break;
 }
 return 1;
}
