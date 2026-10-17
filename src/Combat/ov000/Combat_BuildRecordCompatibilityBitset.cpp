#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GetLinkedEmbeddedBufferWhenHalfwordCountPositive(char*);
extern "C" char* Object_GetNestedOffset150Subrecord488(char*);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void* memset(void*,int,unsigned);
extern "C" void Initialize2RecordFields_Main0209A338(unsigned*);
extern "C" void BackgroundLoader_LoadAndExecuteTemporaryOwnerScript(unsigned*,unsigned);
struct Record{unsigned short id:11;unsigned short tail:5;unsigned short key;unsigned kind:5;unsigned rest:27;unsigned pad;};
struct Kind{unsigned low:7;unsigned kind:4;unsigned high:21;};
extern "C" Record* FindTwelveByteRecordByHalfwordKey(unsigned char*,unsigned);
struct Entry{unsigned pad;unsigned key:12;unsigned rest:20;};
// Original: arm9/ov000 @ 0x0217C32C; symbol: func_ov000_0217c32c; size: 0x1BC.
extern "C" void Combat_BuildRecordCompatibilityBitset(char* self){
 unsigned char* bits;
 char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(int*)(self+0x4c));
 if(!object)return;
 char* first=GetLinkedEmbeddedBufferWhenHalfwordCountPositive(object);
 char* second=*(char**)(object+0x150)+0x2b4;
 char* flags=Object_GetNestedOffset150Subrecord488(object);
 if(flags){int a=*(short*)(flags+14),b=*(short*)(flags+16);if(a<0)first=0;if(b<0)second=0;}
 if(!ReadWordFieldAtOffset150(object))return;
 memset(self+0x88,0,19);
 unsigned header[2];char buffer[sizeof(Record)*287];
 Initialize2RecordFields_Main0209A338(header);
 BackgroundLoader_LoadAndExecuteTemporaryOwnerScript(header,(unsigned)buffer);
 unsigned short i=0;
 for(;i<147;i++){
  char* entry=*(char**)(self+0x1a4+i*4);if(!entry)break;
  Record* record=FindTwelveByteRecordByHalfwordKey((unsigned char*)header,((Entry*)entry)->key);
  if(record){
   int compatible;
   if(!*(int*)(*(char**)(object+0x150)+0x950))compatible=1;
   else if(first)compatible=((Kind*)*(char**)first)->kind==record->kind;
   else compatible=record->kind==14;
   if(second && ((Kind*)*(char**)second)->kind==record->kind)compatible=1;
   if(record->kind>14)compatible=1;
   if(record->id==286)compatible=1;
   if(compatible){bits=(unsigned char*)self+0x88;bits[(unsigned char)(i>>3)]|=1<<(i&7);}
  }
 }
}
