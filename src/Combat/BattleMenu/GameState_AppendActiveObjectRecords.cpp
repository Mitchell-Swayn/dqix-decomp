#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
unsigned char* GameObject_GetLinkedIndexedState(void*);
void BattleMenu_SetItemChoice(void*,int,void*);
// Original data: arm9/ov000 @ 0x02183380; symbol: data_ov000_02183380.
// Equipment-slot order used by GameState_AppendActiveObjectRecords to append occupied equipment records after carried-item choices.
// Values (uint8_t[8]): {8, 9, 7, 0, 5, 1, 6, 10}.
extern unsigned char BattleMenu_ItemChoiceEquipmentSlotOrder[];
}
struct Eight { unsigned char bytes[8]; };
struct Record { char pad[8]; unsigned kind:4; unsigned other:28;char pad2[12];short count; };
struct Owner { char pad[0x4c];unsigned index;char pad2[0x36];signed char count;char pad3[0x369];Record* records[16]; };
// Original: arm9/ov000 @ 0x02171C04; symbol: func_ov000_02171c04; size: 0x18C.
extern "C" void GameState_AppendActiveObjectRecords(Owner* p){
signed char index=p->index;
int valid; if(index>=0 && index<=3)valid=1;else valid=0;
if(valid){
char* obj=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
if(obj && GameObject_GetLinkedIndexedState(obj)){
signed char i=0;p->count=0;
for(;i<16;i++){
Record* r=p->records[i];
if(!r)break;
int low; if(r->kind<=7)low=1;else low=0;
if(low)break;
p->count++;
}
unsigned char slot=(p->count+3)&~3;
for(unsigned char j=slot;j<16;j++)p->records[j]=0;
Eight order=*(Eight*)BattleMenu_ItemChoiceEquipmentSlotOrder;
for(unsigned char j=0;j<8;j++){
Record* r=(Record*)(*(char**)(obj+0x150)+0x194+order.bytes[j]*32);
if(r && r->count>0){
int low; if(r->kind<=7)low=1;else low=0;
if(low){BattleMenu_SetItemChoice(p,slot,r);slot++;}
}
}
}
}
}
