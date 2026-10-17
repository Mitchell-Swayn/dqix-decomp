#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned Object_LookupKeyInOptionalTargetHandle(char*,unsigned,void**,unsigned);
extern "C" int TestLinkedWordFlagBitSeven(char*);
extern "C" int ReadHalfwordByClampedByteSelector(char*);
extern "C" char* GetPrimaryLinkedRecordByIndex(char*,int);
extern "C" char* GetSecondaryLinkedRecordByIndex(char*,int);
extern "C" char* ResolveOverrideOrIndexedRecord(void*);
extern "C" void* func_ov000_02160f9c(void*);
// Original: arm9/ov025 @ 0x021DFA9C; symbol: func_ov025_021dfa9c; size: 0x138.
extern "C" void* Object_FindSecondTargetForMatchingLinkedRecords(void* arg,char* base) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* rec=ResolveOverrideOrIndexedRecord(arg);
 int index=(int)func_ov000_02160f9c(arg);
 char* first=GetPrimaryLinkedRecordByIndex(rec,0);
 if(first) {
 unsigned key=*(unsigned short*)rec;
 char* actor=_ZN9GameState19GetCombatantByIndexEi(state,*(unsigned short*)(first+0x20));
 if(actor && index>0 && key==1 && TestLinkedWordFlagBitSeven(actor)) {
 char* other=base+0x821c+(index-1)*0x28;
 if(other) {
 char* second=GetPrimaryLinkedRecordByIndex(other,0);
 if(second && *(unsigned short*)(second+0x20)==*(unsigned short*)(first+0x20)) {
 char* a=GetSecondaryLinkedRecordByIndex(rec,0);
 char* b=GetSecondaryLinkedRecordByIndex(other,0);
 if(a && b && *(short*)(a+0xe)==*(short*)(b+0xe) && *(unsigned short*)other==1 && ReadHalfwordByClampedByteSelector(b)==*(short*)(b+0xe)) {
 void* targets[2];
 if((int)Object_LookupKeyInOptionalTargetHandle(actor,key,targets,2)>=2) return targets[1];
 }
 }
 }
 }
 }
 return 0;
}
