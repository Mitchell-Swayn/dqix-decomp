#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma always_inline on
extern "C" int TestContextModeAndZeroSlot();
struct Entry { char text[111]; unsigned char category:6,flag2:1,flag1:1; };
struct Queue { Entry entries[3]; unsigned char count:6,other:2; unsigned char pad; unsigned short timer;
 void Append(const char* text,int category,int flag1,unsigned char flag2) {
 strcpy(entries[count].text,text);
 entries[count].category=category;
 entries[count].flag1=flag1;
 entries[count].flag2=flag2;
 count=(unsigned char)(count+1);
 }
};
// Original: arm9/main @ 0x020D7E10; symbol: func_020d7e10; size: 0x24C.
extern "C" void Text_EnqueueThreeEntryMessage(Queue* self,const char* text,unsigned char category,unsigned char flag1,unsigned char deduplicate,unsigned char flag2) {
 if(TestContextModeAndZeroSlot()) return;
 unsigned count=self->count;
 if(count && deduplicate) {
 if(!strcmp(self->entries[0].text,text)) return;
 }
 if(count<3) {
 strcpy(self->entries[count].text,text);
 self->entries[self->count].category=category;
 self->entries[self->count].flag1=flag1;
 self->entries[self->count].flag2=flag2;
 self->count=(unsigned char)(self->count+1);
 if(self->timer>1000) self->timer=(int)self->timer%1000;
 } else {
 if(self->timer) {
 self->timer=0;
 if(self->count) {
 memcpy(&self->entries[0],&self->entries[1],112);
 memcpy(&self->entries[1],&self->entries[2],112);
 self->count=(unsigned char)(self->count+255);
 }
 }
 count=self->count;
 if(count<3) {
 strcpy(self->entries[count].text,text);
 self->entries[self->count].category=category;
 self->entries[self->count].flag1=flag1;
 self->entries[self->count].flag2=flag2;
 self->count=(unsigned char)(self->count+1);
 }
 }
}
