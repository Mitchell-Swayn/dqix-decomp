#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
extern "C" bool CharacterState_WeaponDoublesEligibleActionHits(void*);
extern "C" bool GameState_TestFlagD0RandomRoll(void*,int);
extern "C" void* memcpy(void*,const void*,unsigned);
struct Table {unsigned short values[32];};
// Original data: arm9/ov024 @ 0x21fe930; symbol: data_ov024_021fe930.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" const Table CombatRepeatTargetListForActionProperties_UnknownRoleInitializedBytes;
struct Action {unsigned a;unsigned id:12,rest:20;unsigned other[5];unsigned low:14,type:5,high:13;};
struct Flags {unsigned first:1,second:1,rest:30;};
inline int ValidIndex(int i) {if(i>=0&&i<=3)return 1;return 0;}
// Original: arm9/ov024 @ 0x021E8DC0; symbol: func_ov024_021e8dc0; size: 0x1E4.
extern "C" int Combat_RepeatTargetListForActionProperties(char* context,int index,Action* action,short* targets,int count) {

 void* random=*(void**)(context+0x10);
 int repeats=1;
 switch(action->type) {
 case 1:repeats=2;break;
 case 2:repeats=(int)_Z22NextRandomFloatBetweenP6Randomff(random,3.0f,4.0f);break;
 case 6:repeats=4;break;
 case 9:repeats=5;break;
 }
 if(repeats>1)context[0x7a]=1;
 if(ValidIndex(index)) {
  char* actor=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
  if(actor && (*(unsigned*)((char*)action+0x10)&0x100000)) {
   if(CharacterState_WeaponDoublesEligibleActionHits(*(void**)(actor+0x150))) {context[0x7a]=1;repeats*=2;}
  }
  if(action->id==1) {
   Flags* flags=(Flags*)(*(char**)(actor+0x150)+0x2f4);
   if(!flags)return repeats;
   if(!flags->second && !flags->first && GameState_TestFlagD0RandomRoll(*(void**)(context+0x10),index)) {
    context[0x78]=1;context[0x7a]=1;++repeats;
   }
  }
 }
 Table table=CombatRepeatTargetListForActionProperties_UnknownRoleInitializedBytes;
 short length=0;
 for(int j=0;j<repeats;j++)for(int i=0;i<count;i++)table.values[length++]=targets[i];
 memcpy(targets,&table,length*2);
 return length;
}
