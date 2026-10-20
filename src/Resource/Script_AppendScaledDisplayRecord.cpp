#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct DisplayRecord {signed char id;char pad[3];char* name;unsigned char kind;char gap;short fieldA;int fieldC;unsigned char field10,field11,field12,pad13;float xScale,yScale;short halfwords[10];unsigned char bytes[13],last[3];};
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20e8c58; symbol: data_020e8c58.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex b80e0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8c5c; symbol: data_020e8c5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9f100000350e0000281000000a0f0000ae0f000024100000330f00001e0f0000b40e0000b80e000051100000390e0000fb0f0000e10e0000850f000024100000 ...; full span in module reference.
// Observed span: 78 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int ScriptAppendScaledDisplayRecord_UnknownRoleInitializedBytes[],ScriptAppendScaledDisplayRecord_UnknownRoleInitializedBytes_Variant2[];
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" void CharacterTemplate_AppendEntry(char*,char*);
// Original: arm9/main @ 0x02089B90; symbol: func_02089b90; size: 0x224.
// Builds a 64-byte display record from script parameters, with copied optional name.
extern "C" int Script_AppendScaledDisplayRecord(unsigned char* params) {
 DisplayRecord record;
 record.id=-1;record.name=0;record.kind=0;record.fieldA=0;record.fieldC=0;
 record.field10=0;record.field11=0;record.field12=0;record.xScale=1.0f;record.yScale=1.0f;
 memset(record.halfwords,-1,20);memset(record.bytes,-1,13);
 record.last[0]=0;record.last[1]=0;record.last[2]=0;
 if(*(short*)(*(char**)ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage+8)==1) {
  record.id=_ZNK6Script9Parameter5ToIntEv(params);
  const char* name=_ZNK6Script9Parameter8ToStringEv(params+8);
  if(name) {
   unsigned length=String_CountBytesUntilTerminator((const signed char*)name);
   record.name=_ZN13SafeAllocator8AllocateEj(*(unsigned*)(ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage+12),length+1);
   memset(record.name,0,length+1);memcpy(record.name,name,length);
  }
  record.kind=_ZNK6Script9Parameter5ToIntEv(params+16);
  record.fieldA=_ZNK6Script9Parameter5ToIntEv(params+24);
  record.fieldC=_ZNK6Script9Parameter5ToIntEv(params+32);
  record.field10=_ZNK6Script9Parameter5ToIntEv(params+40);
  record.field11=_ZNK6Script9Parameter5ToIntEv(params+48);
  record.field12=_ZNK6Script9Parameter5ToIntEv(params+56);
  unsigned char* selector=params+64;
  params+=72;
  int index=_ZNK6Script9Parameter5ToIntEv(selector);
  if(index>=0 && index<=5) {
   record.xScale=(float)*(int*)((char*)ScriptAppendScaledDisplayRecord_UnknownRoleInitializedBytes+record.kind*40+index*8)/4096.0f;
   record.yScale=(float)*(int*)((char*)ScriptAppendScaledDisplayRecord_UnknownRoleInitializedBytes_Variant2+record.kind*40+index*8)/4096.0f;
  }
  for(int i=0;i<10;++i) {record.halfwords[i]=_ZNK6Script9Parameter5ToIntEv(params);params+=8;}
  for(int i=0;i<13;++i) {record.bytes[i]=_ZNK6Script9Parameter5ToIntEv(params);params+=8;}
  record.last[0]=_ZNK6Script9Parameter5ToIntEv(params);
  record.last[1]=_ZNK6Script9Parameter5ToIntEv(params+8);
  record.last[2]=_ZNK6Script9Parameter5ToIntEv(params+16);
 }
 CharacterTemplate_AppendEntry(*(char**)ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage,(char*)&record);
 return 1;
}
