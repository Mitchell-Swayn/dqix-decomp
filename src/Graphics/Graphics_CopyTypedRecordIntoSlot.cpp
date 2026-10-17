#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Payload {unsigned a,b,c,d,e,f,g,h;};
struct Record { Payload* payload; char* text; unsigned flags:4; unsigned rest:28; unsigned other[5]; };
extern "C" void* memset(void*,int,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void InitializePacked999FieldsAndInvalidIndex(void*);
extern "C" void Copy10RecordFields(void*,void*);
extern "C" char* GetSelectedEmbeddedTextBufferPointer(char*,int);
// Original: arm9/main @ 0x0208358C; symbol: func_0208358c; size: 0x158.
extern "C" void Graphics_CopyTypedRecordIntoSlot(char* self,Record* input,int custom) {
 if(!input)return;
 int index=-1;
 switch(input->flags) {
 case 0:index=8;break;
 case 1:index=9;break;
 case 4:index=7;break;
 case 2:index=0;break;
 case 5:index=5;break;
 case 3:index=1;break;
 case 6:index=6;break;
 case 7:index=10;break;
 case 11:index=custom;break;
 }
 if(index<0)return;
 Record* slot=(Record*)(self+0x194+index*32);
 Payload* dst=slot->payload; char* text=slot->text; Payload* src=input->payload;
 dst->a=src->a; dst->b=src->b; dst->c=src->c; dst->d=src->d; dst->e=src->e; dst->f=src->f; dst->g=src->g; dst->h=src->h;
 text[0]=0;
 if(input->text) {
 memset(text,0,48);
 sprintf(text,input->text);
 }
 InitializePacked999FieldsAndInvalidIndex(slot);
 Copy10RecordFields(slot,input);
 slot->payload=(Payload*)(self+0x6f0+index*32);
 slot->text=GetSelectedEmbeddedTextBufferPointer(self,index);
}
