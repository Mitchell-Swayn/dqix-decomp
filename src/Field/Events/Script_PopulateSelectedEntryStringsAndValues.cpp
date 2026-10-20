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
// Original data: arm9/ov017 @ 0x21d83cc; symbol: data_ov017_021d83cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Global ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021ACA2C; symbol: func_ov017_021aca2c; size: 0x260.
extern "C" int Script_PopulateSelectedEntryStringsAndValues(char* args,int count) {
 int id=_ZNK6Script9Parameter5ToIntEv(args);
 if(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->id!=id) return 1;
 int index=_ZNK6Script9Parameter5ToIntEv(args+8);
 if(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->index!=index) return 1;
 if(index<0) return 1;
 ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->a=_ZNK6Script9Parameter5ToIntEv(args+16);
 ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->b=_ZNK6Script9Parameter5ToIntEv(args+24);
 unsigned length;
 const char* text=_ZNK6Script9Parameter8ToStringEv(args+32);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[0]=_ZN13SafeAllocator8AllocateEj(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.allocator,length+1);
   memset(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[0],0,length+1);
   memcpy(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[0],text,length);
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[0][length]=0;
  }
 }
 text=_ZNK6Script9Parameter8ToStringEv(args+40);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[1]=_ZN13SafeAllocator8AllocateEj(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.allocator,length+1);
   memset(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[1],0,length+1);
   memcpy(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[1],text,length);
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[1][length]=0;
  }
 }
 char* next=args+48;args+=56;
 text=_ZNK6Script9Parameter8ToStringEv(next);
 if(text) {
  length=String_CountBytesUntilTerminator((const signed char*)text);
  if(length) {
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[2]=_ZN13SafeAllocator8AllocateEj(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.allocator,length+1);
   memset(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[2],0,length+1);
   memcpy(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[2],text,length);
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->text[2][length]=0;
  }
 }
 int remaining=count-7;
 if(remaining) {
  ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->valueCount=remaining;
  ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->values=(short*)_ZN13SafeAllocator8AllocateEj(ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.allocator,remaining*2);
  for(int i=0;i<count-7;++i) {
   ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->values[i]=_ZNK6Script9Parameter5ToIntEv(args);
   args+=8;
  }
 }
 ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage.entry->ready=1;
 return 1;
}
