#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* strcpy(char*,const char*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned*);
struct Global {char pad[4];unsigned short sequence;char pad6[6];int pending;char pad10[8];int filter;char pad1c[4];char* entry;};
extern "C" Global data_02108d70;
// Original: arm9/main @ 0x02071208; symbol: func_02071208; size: 0x280.
extern "C" int Script_PopulatePendingRecordFromParameters(char* args) {
 ++data_02108d70.sequence;
 if(data_02108d70.pending) return 1;
 int a=_ZNK6Script9Parameter5ToIntEv(args);
 int b=_ZNK6Script9Parameter5ToIntEv(args+8);
 int c=_ZNK6Script9Parameter5ToIntEv(args+16);
 int d=_ZNK6Script9Parameter5ToIntEv(args+24);
 int e=_ZNK6Script9Parameter5ToIntEv(args+32);
 int f=_ZNK6Script9Parameter5ToIntEv(args+40);
 if(f==data_02108d70.filter) {
  data_02108d70.entry[0]=a;
  data_02108d70.entry[2]=c;
  data_02108d70.entry[1]=b;
  data_02108d70.entry[3]=d;
  *(short*)(data_02108d70.entry+0xe)=e;
  *(short*)(data_02108d70.entry+0xa)=f;
  *(short*)(data_02108d70.entry+0xc)=_ZNK6Script9Parameter5ToIntEv(args+48);
  const char* text=_ZNK6Script9Parameter8ToStringEv(args+56);
  if(text) {memcpy(data_02108d70.entry+0x12,text,32);data_02108d70.entry[0x31]=0;}
  text=_ZNK6Script9Parameter8ToStringEv(args+64);
  if(!text) return 0;
  strcpy(data_02108d70.entry+0x32,text);
  *(short*)(data_02108d70.entry+0x3e)=_ZNK6Script9Parameter5ToIntEv(args+72);
  *(short*)(data_02108d70.entry+0x40)=_ZNK6Script9Parameter5ToIntEv(args+80);
  *(short*)(data_02108d70.entry+0x42)=_ZNK6Script9Parameter5ToIntEv(args+88);
  args=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args+96,data_02108d70.entry+0x48);
  *(short*)(data_02108d70.entry+0x54)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args));
  data_02108d70.entry[5]=_ZNK6Script9Parameter5ToIntEv(args+8);
  *(short*)(data_02108d70.entry+0x46)=_ZNK6Script9Parameter5ToIntEv(args+16);
  if(*(short*)(data_02108d70.entry+0x46)>=0) *(short*)(data_02108d70.entry+0x46)=data_02108d70.sequence-1;
  data_02108d70.entry[4]=_ZNK6Script9Parameter5ToIntEv(args+24);
  data_02108d70.entry[6]=_ZNK6Script9Parameter5ToIntEv(args+32);
  text=_ZNK6Script9Parameter8ToStringEv(args+40);
  if(text) {memcpy(data_02108d70.entry+0x56,text,16);data_02108d70.entry[0x65]=0;}
  *(short*)(data_02108d70.entry+0x44)=_ZNK6Script9Parameter5ToIntEv(args+48);
  if(TestActiveWordAndGlobalStateNonzero((unsigned*)Object_GetGlobalConnectionState())) *(unsigned short*)(data_02108d70.entry+0x44)&=~8;
  *(short*)(data_02108d70.entry+0x10)=_ZNK6Script9Parameter5ToIntEv(args+56);
  data_02108d70.pending=1;
 }
 return 1;
}
