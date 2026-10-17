#include <globaldefs.h>
ARM
struct Payload {unsigned char id,kind;unsigned short source;short value;short pad;float timer;unsigned short meta,extra;};
struct Message {unsigned char command;char pad[3];Payload payload;};
struct Map {unsigned short key;unsigned short pad:4,value:12;unsigned short extra;};
struct Cache {unsigned short key,value;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned* Object_GetGlobalConnectionState();
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" char* GameResources_GetInstance();
extern "C" void* ReadGlobalAt020FDD44();
extern "C" void* ReadGlobalAt02100044();
extern "C" void* memset(void*,int,unsigned);
extern "C" char* OV017_ReadWordField6B0(void*);
extern "C" char* OV017_GetEmbeddedField1C(void*);
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" int TestPrimaryOrPairedByteFlags(void*);
extern "C" unsigned ToggleMaskedFlagsAtOffset34(void*,unsigned);
extern "C" int func_ov017_021b8b94(void*);
extern "C" float _ZNK9GameState11GetDayTimerEv(void*);
extern "C" Map* FindRecordAmongFourByNonnegativeKey(void*,int);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
// Original: arm9/ov017 @ 0x021C4FA0; symbol: func_ov017_021c4fa0; size: 0x220.
extern "C" void Network_QueueSelectedSourceAndDayTimer(int id,int key) {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned* connection=Object_GetGlobalConnectionState();
 unsigned short* global=ReadGlobalValueAt020FB3F0();
 char* resources=GameResources_GetInstance();
 Payload* out;char* data;
 char* primary=*(char**)(resources+0x3734);
 ReadGlobalAt020FDD44();
 void* queue=ReadGlobalAt02100044();
 Message message;message.command=0x8f;
 out=&message.payload;
 memset(out,0,16);
 out->kind=0;out->id=id;out->timer=-1.0f;
 char* owner;
 char* control=*(char**)(resources+0x3718);
 owner=OV017_ReadWordField6B0(control);
 data=OV017_GetEmbeddedField1C(control);
 if(TestInactiveOrPrimaryIndexState(connection)) {
 int selected=1;
 if(*(unsigned short*)(primary+0x1a)!=key||(*(unsigned short*)(primary+0x50)&0x800)) {
 if(*(unsigned short*)(primary+0x1c)!=key)selected=0;
 }
 if(TestPrimaryOrPairedByteFlags(primary)&&*(unsigned char*)(primary+0x12)&&!*(unsigned char*)(primary+0x106)&&selected) {
 out->kind=1;
 unsigned short source=*(unsigned short*)(primary+0x18);
 if(source==0) {
 out->source=*(unsigned short*)(primary+8);
 out->value=*(short*)(primary+0x52);
 } else {
 out->source=source;
 out->value=*(short*)(primary+0x52);
 }
 } else if(*(unsigned char*)(control+2)&&(!owner||!*(signed char*)(owner+0x8e14))&&data&&!ToggleMaskedFlagsAtOffset34(data,(unsigned char)id)&&!func_ov017_021b8b94(control)&&*(int*)(data+12)>=0) {
 out->kind=2;
 out->source=*(int*)(data+12);
 out->value=global[0];
 }
 out->timer=_ZNK9GameState11GetDayTimerEv(game);
 Map* found=FindRecordAmongFourByNonnegativeKey(ReadGlobalAt020FDD44(),key);
 if(found) {
 out->meta=found->value;out->extra=found->extra;
 } else {
 Cache* cache=(Cache*)(resources+0x44b4);
 if(cache->key==key)out->meta=cache->value;else out->meta=0;
 out->extra=0;
 }
 }
 MoveQueuedRecordAndApplySourceValue(queue,&message,0);
}
