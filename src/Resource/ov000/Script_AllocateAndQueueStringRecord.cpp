#include <globaldefs.h>
ARM
struct Parameter { unsigned type,value; };
struct Record { unsigned type,next; char* text; unsigned short count; unsigned char mode,flag; };
extern "C" {
extern void* data_ov000_02184264[];
void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
const char* _ZNK6Script9Parameter8ToStringEv(const void*);
int _ZNK6Script9Parameter5ToIntEv(const void*);
unsigned strlen(const char*);
char* strcpy(char*,const char*);
void Overlay_EnqueueLinkedNode(void*);
}
// Original: arm9/ov000 @ 0x02169D08; symbol: func_ov000_02169d08; size: 0x14C.
extern "C" int Script_AllocateAndQueueStringRecord(Parameter* args,int argc) {
 Record* record=(Record*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],16);
 record->type=3;
 if(args->type==0) {
  const char* text=_ZNK6Script9Parameter8ToStringEv(args++);
  int repeat=1;
  if(argc>=2)repeat=_ZNK6Script9Parameter5ToIntEv(args++);
  unsigned length=strlen(text);
  record->text=(char*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],length+1);
  strcpy(record->text,text);
  record->count=repeat;
  record->mode=7;
  int flag=0;
  if(argc>=3)flag=_ZNK6Script9Parameter5ToIntEv(args);
  record->flag=flag;
 } else if(args->type==1) {
  record->mode=_ZNK6Script9Parameter5ToIntEv(args++);
  const char* text=_ZNK6Script9Parameter8ToStringEv(args++);
  int repeat=1;
  if(argc>=3)repeat=_ZNK6Script9Parameter5ToIntEv(args++);
  unsigned length=strlen(text);
  record->text=(char*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],length+1);
  strcpy(record->text,text);
  record->count=repeat;
  int flag=0;
  if(argc>=4)flag=_ZNK6Script9Parameter5ToIntEv(args);
  record->flag=flag;
 } else return 0;
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
