#include <globaldefs.h>
ARM
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool Object_TestElement5Mask10(unsigned*);
extern "C" bool Object_TestElement6Mask80(unsigned*);
extern "C" bool TestLinkedRecordFlag20(Object*);
extern "C" int TestNestedRecordFlag200(char*);
extern "C" int HasObjectFlag100(const void*);
extern "C" int HasObjectFlag02000000(const void*);
extern "C" int HasNestedObjectFlag04(const void*);
extern "C" unsigned func_ov000_02159874(void*);
extern "C" unsigned func_ov000_0215991c(void*);
extern "C" int HasBit3AtNestedOffset14From138(void*);
extern "C" int func_ov000_02156404(void*);
extern "C" int TestNestedField14Bit40(void*);
extern "C" int HasNestedField138Flag08000000At14(void*);
extern "C" int HasNestedFlag28(void*);
extern "C" int func_ov000_021598a4(void*);
extern "C" int TestNestedField14Bit04000000(void*);
extern "C" int HasNestedField138Flag00400000At14(void*);
extern "C" int Ov000_TestNestedFlagBit3(void*);
extern "C" int HasNestedFlag10(void*);
extern "C" int Ov000_TestNestedFlagBit1(void*);
extern "C" int func_ov000_02159934(void*);
extern "C" int HasBit12AtNestedOffset14From138(void*);
extern "C" int func_ov000_02159964(void*);
extern "C" int func_ov000_0215997c(void*);
extern "C" int TestNestedFlags8000At13814(void*);
extern "C" int TestNestedFlags10000At13814(void*);
extern "C" int TestNestedFlags20000At13814(void*);
extern "C" int TestNestedStateWordBit0(void*);
extern "C" int Ov000_TestNestedFlagBit8(void*);
extern "C" int data_ov000_02182a94[];
struct Mapping {int index,value;};
extern "C" Mapping data_ov000_02182efc[];
// Original: arm9/ov000 @ 0x021599F4; symbol: func_ov000_021599f4; size: 0x264.
extern "C" void Combat_DecrementActiveFlagCounters(void*,int index) {
 unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!object) return;
 unsigned char* counters=*(unsigned char**)(object+0x138)+0x5c;
 unsigned char* states=*(unsigned char**)(object+0x138)+0x7f;
 unsigned char flags[29];
 flags[0]=HasBit3AtNestedOffset14From138(object);
 flags[1]=Object_TestElement5Mask10(*(unsigned**)(object+0x138));
 flags[2]=TestLinkedRecordFlag20((Object*)object);
 unsigned char active;
 unsigned char* test=flags;
 int* firstMap=data_ov000_02182a94;
 for(int i=0;i<3;++i,++test,++firstMap) {
  active=*test;
  if(active) {
   if(counters[*firstMap]) {
    --counters[*firstMap];
    if(!counters[*firstMap]) {counters[*firstMap]=0;states[*firstMap]=4;}
   }
   break;
  }
 }
 flags[3]=func_ov000_02156404(object);
 flags[4]=TestNestedRecordFlag200((char*)object);
 flags[5]=TestNestedField14Bit40(object);
 flags[6]=HasObjectFlag100(object);
 flags[7]=func_ov000_02159874(object);
 flags[8]=HasNestedField138Flag08000000At14(object);
 flags[9]=HasNestedFlag28(object);
 flags[10]=func_ov000_021598a4(object);
 flags[11]=TestNestedField14Bit04000000(object);
 flags[12]=HasNestedField138Flag00400000At14(object);
 flags[13]=Ov000_TestNestedFlagBit3(object);
 flags[14]=Object_TestElement6Mask80(*(unsigned**)(object+0x138));
 flags[15]=HasNestedFlag10(object);
 flags[16]=Ov000_TestNestedFlagBit1(object);
 flags[17]=HasNestedObjectFlag04(object);
 flags[18]=func_ov000_0215991c(object);
 flags[19]=func_ov000_02159934(object);
 flags[20]=HasBit12AtNestedOffset14From138(object);
 flags[21]=func_ov000_02159964(object);
 flags[22]=func_ov000_0215997c(object);
 flags[23]=TestNestedFlags8000At13814(object);
 flags[24]=TestNestedFlags10000At13814(object);
 flags[25]=TestNestedFlags20000At13814(object);
 flags[26]=TestNestedStateWordBit0(object);
 flags[27]=HasObjectFlag02000000(object);
 flags[28]=Ov000_TestNestedFlagBit8(object);
 unsigned char value;
 int key;
 int zero=0;
 unsigned char* remaining=flags+3;
 Mapping* map=data_ov000_02182efc;
 for(int i=0;i<26;++i,++remaining,++map) {
  value=*remaining;
  if(value) {
   key=map->index;
   value=counters[key];
   if(value) {
    counters[key]=value-1;
    key=map->index;
    value=counters[key];
    if(!value) {counters[key]=zero;states[map->index]=map->value;}
   }
  }
 }
}
