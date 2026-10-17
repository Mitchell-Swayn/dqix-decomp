#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" void* memset(void*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
struct Entry {char* text[3];short* values;unsigned short id;short index;char a,b,valueCount,ready;};
struct Global {unsigned allocator;Entry* entry;};
extern "C" Global data_ov017_021d83cc;
// Original: arm9/ov017 @ 0x021ACA2C; symbol: func_ov017_021aca2c; size: 0x260.
extern "C" int Script_PopulateSelectedEntryStringsAndValues(char* args,int count) {
 int id=_ZNK6Script9Parameter5ToIntEv(args);
 if(data_ov017_021d83cc.entry->id!=id) return 1;
 int index=_ZNK6Script9Parameter5ToIntEv(args+8);
 if(data_ov017_021d83cc.entry->index!=index) return 1;
 if(index<0) return 1;
 data_ov017_021d83cc.entry->a=_ZNK6Script9Parameter5ToIntEv(args+16);
 data_ov017_021d83cc.entry->b=_ZNK6Script9Parameter5ToIntEv(args+24);
 unsigned length;
 const char* text=_ZNK6Script9Parameter8ToStringEv(args+32);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   data_ov017_021d83cc.entry->text[0]=_ZN13SafeAllocator8AllocateEj(data_ov017_021d83cc.allocator,length+1);
   memset(data_ov017_021d83cc.entry->text[0],0,length+1);
   memcpy(data_ov017_021d83cc.entry->text[0],text,length);
   data_ov017_021d83cc.entry->text[0][length]=0;
  }
 }
 text=_ZNK6Script9Parameter8ToStringEv(args+40);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   data_ov017_021d83cc.entry->text[1]=_ZN13SafeAllocator8AllocateEj(data_ov017_021d83cc.allocator,length+1);
   memset(data_ov017_021d83cc.entry->text[1],0,length+1);
   memcpy(data_ov017_021d83cc.entry->text[1],text,length);
   data_ov017_021d83cc.entry->text[1][length]=0;
  }
 }
 char* next=args+48;args+=56;
 text=_ZNK6Script9Parameter8ToStringEv(next);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   data_ov017_021d83cc.entry->text[2]=_ZN13SafeAllocator8AllocateEj(data_ov017_021d83cc.allocator,length+1);
   memset(data_ov017_021d83cc.entry->text[2],0,length+1);
   memcpy(data_ov017_021d83cc.entry->text[2],text,length);
   data_ov017_021d83cc.entry->text[2][length]=0;
  }
 }
 int remaining=count-7;
 if(remaining) {
  data_ov017_021d83cc.entry->valueCount=remaining;
  data_ov017_021d83cc.entry->values=(short*)_ZN13SafeAllocator8AllocateEj(data_ov017_021d83cc.allocator,remaining*2);
  for(int i=0;i<count-7;++i) {
   data_ov017_021d83cc.entry->values[i]=_ZNK6Script9Parameter5ToIntEv(args);
   args+=8;
  }
 }
 data_ov017_021d83cc.entry->ready=1;
 return 1;
}
