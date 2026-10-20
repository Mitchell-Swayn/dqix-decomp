#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* strcpy(char*,const char*);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned*);
struct Global {char pad[4];unsigned short sequence;char pad6[6];int pending;char pad10[8];int filter;char pad1c[4];char* entry;};
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Global ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02071208; symbol: func_02071208; size: 0x280.
extern "C" int EventListScript_ReadMatchingEventDescriptor(char* args) {
 ++ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.sequence;
 if(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.pending) return 1;
 int a=_ZNK6Script9Parameter5ToIntEv(args);
 int b=_ZNK6Script9Parameter5ToIntEv(args+8);
 int c=_ZNK6Script9Parameter5ToIntEv(args+16);
 int d=_ZNK6Script9Parameter5ToIntEv(args+24);
 int e=_ZNK6Script9Parameter5ToIntEv(args+32);
 int f=_ZNK6Script9Parameter5ToIntEv(args+40);
 if(f==ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.filter) {
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[0]=a;
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[2]=c;
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[1]=b;
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[3]=d;
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0xe)=e;
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0xa)=f;
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0xc)=_ZNK6Script9Parameter5ToIntEv(args+48);
  const char* text=_ZNK6Script9Parameter8ToStringEv(args+56);
  if(text) {memcpy(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x12,text,32);ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[0x31]=0;}
  text=_ZNK6Script9Parameter8ToStringEv(args+64);
  if(!text) return 0;
  strcpy(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x32,text);
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x3e)=_ZNK6Script9Parameter5ToIntEv(args+72);
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x40)=_ZNK6Script9Parameter5ToIntEv(args+80);
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x42)=_ZNK6Script9Parameter5ToIntEv(args+88);
  args=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args+96,ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x48);
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x54)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args));
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[5]=_ZNK6Script9Parameter5ToIntEv(args+8);
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x46)=_ZNK6Script9Parameter5ToIntEv(args+16);
  if(*(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x46)>=0) *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x46)=ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.sequence-1;
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[4]=_ZNK6Script9Parameter5ToIntEv(args+24);
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[6]=_ZNK6Script9Parameter5ToIntEv(args+32);
  text=_ZNK6Script9Parameter8ToStringEv(args+40);
  if(text) {memcpy(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x56,text,16);ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry[0x65]=0;}
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x44)=_ZNK6Script9Parameter5ToIntEv(args+48);
  if(Network_IsClientSession((unsigned*)Network_GetConnectionManager())) *(unsigned short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x44)&=~8;
  *(short*)(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entry+0x10)=_ZNK6Script9Parameter5ToIntEv(args+56);
  ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.pending=1;
 }
 return 1;
}
