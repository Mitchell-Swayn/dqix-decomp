#include <globaldefs.h>
ARM
struct Owner { unsigned char pad[0x48]; short** ids; unsigned char** counts; unsigned short* used; };
extern "C" { void* memcpy(void*,const void*,unsigned); extern unsigned short data_ov006_0215fffe[]; }
// Original: arm9/ov006 @ 0x02158FD8; symbol: func_ov006_02158fd8; size: 0xBC.
extern "C" void Util_AddCountToGroupedHalfwordEntry(Owner* owner,unsigned group,int value,int amount) {
 unsigned short limits[9];
 if(value>0 && amount) {
  short* ids=owner->ids[group];
  unsigned char* counts=owner->counts[group];
  unsigned short* used=&owner->used[group];
  memcpy(limits,data_ov006_0215fffe,18);
  unsigned max=limits[group];
  for(unsigned short i=0;i<max;++i) {
   int id=ids[i];
   if(id<=0) { ids[i]=value; counts[i]=amount; ++*used; break; }
   if(id==value) { counts[i]+=amount; break; }
  }
 }
}
