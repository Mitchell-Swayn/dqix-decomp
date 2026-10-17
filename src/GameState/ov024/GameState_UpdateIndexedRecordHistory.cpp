#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
char* GameState_GetObjectWithFlag100(void*,int);
bool Object_TestPositiveCountAndOffset2F4Bit2(void*);
void ClearIndexedStateFields(void*);
}
struct Record {unsigned first;unsigned id:12,rest4:20;unsigned pad8[2];unsigned flags10;unsigned pad14[2];unsigned before:14,field1c:5,after:13;unsigned pad20[3];unsigned before2c:27,active:1,after2c:4;};
// Original: arm9/ov024 @ 0x021EA584; symbol: func_ov024_021ea584; size: 0x208.
extern "C" void GameState_UpdateIndexedRecordHistory(char* p,int index,int value,Record* r){
if(r->id==0x61 && *(int*)(p+0x18)>0)return;
if(r->field1c && *(int*)(p+0x18)>0)return;
if(*(unsigned char*)(p+0x78) && *(int*)(p+0x18)>0)return;
int party;if(index>=0 && index<=3)party=1;else party=0;
if(party){
char* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
if(obj && (r->flags10&0x100000) && Object_TestPositiveCountAndOffset2F4Bit2(*(void**)(obj+0x150)) && *(int*)(p+0x18)>0)return;
}
if(r->active){
int isParty;if(index>=0 && index<=3)isParty=1;else isParty=0;
if(isParty){
if(*(signed char*)(*(char**)(p+0x10)+0x8e82)!=1)*(signed char*)(*(char**)(p+0x10)+0x8e83)=0;
else if(*(int*)(*(char**)(p+0x10)+0x8e58)!=*(int*)(p+4))(*(signed char*)(*(char**)(p+0x10)+0x8e83))++;
*(signed char*)(*(char**)(p+0x10)+0x8e82)=1;
}else{
if(*(signed char*)(*(char**)(p+0x10)+0x8e82)!=2)*(signed char*)(*(char**)(p+0x10)+0x8e83)=0;
else if(*(int*)(*(char**)(p+0x10)+0x8e58)!=*(int*)(p+4))(*(signed char*)(*(char**)(p+0x10)+0x8e83))++;
*(signed char*)(*(char**)(p+0x10)+0x8e82)=2;
}
if(r->id!=*(short*)(*(char**)(p+0x10)+0x8e52))*(signed char*)(*(char**)(p+0x10)+0x8e83)=0;
*(short*)(*(char**)(p+0x10)+0x8e52)=r->id;
if(value!=*(short*)(*(char**)(p+0x10)+0x8e50))*(signed char*)(*(char**)(p+0x10)+0x8e83)=0;
*(short*)(*(char**)(p+0x10)+0x8e50)=value;
*(int*)(*(char**)(p+0x10)+0x8e58)=*(int*)(p+4);
}else ClearIndexedStateFields(*(void**)(p+0x10));
}
