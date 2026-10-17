#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
struct Header {unsigned short mode;unsigned short id:15,flag:1;};
struct Config {Header* current;unsigned short id,mode,entry,pad;int x,y,z;short value;};
extern "C" Config data_ov017_021d83b0;
// Original: arm9/ov017 @ 0x021AB6B0; symbol: func_ov017_021ab6b0; size: 0x1B0.
extern "C" int Script_SelectProtagonistParameterRow(unsigned char* args,int count) {
 unsigned char* p;
 unsigned short id=_ZNK6Script9Parameter5ToIntEv(args);
 if(data_ov017_021d83b0.current->id!=id) return 0;
 if(id==data_ov017_021d83b0.id && data_ov017_021d83b0.mode) return 0;
 unsigned char* next=args+8; args+=16;
 unsigned short mode=_ZNK6Script9Parameter5ToIntEv(next);
 if(mode && mode!=data_ov017_021d83b0.current->mode) return 0;
 int rows=(count-2)/5;
 if(rows==0) {
  if(data_ov017_021d83b0.current->mode==mode) data_ov017_021d83b0.entry=0;
  return 0;
 }
 p=ReadWordFieldAtOffset150(_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv()));
 unsigned short entry;
 float value,x,y,z;
 int i=0;
 p+=0x500;
 for(;i<rows;++i) {
  entry=_ZNK6Script9Parameter5ToIntEv(args);
  value=_ZNK6Script9Parameter7ToFloatEv(args+8);
  x=_ZNK6Script9Parameter7ToFloatEv(args+16);
  y=_ZNK6Script9Parameter7ToFloatEv(args+24);
  next=args+32; args+=40;
  z=_ZNK6Script9Parameter7ToFloatEv(next);
  if(entry==*(unsigned short*)(p+0x66)) break;
 }
 data_ov017_021d83b0.id=id;
 data_ov017_021d83b0.mode=mode;
 data_ov017_021d83b0.entry=entry;
 data_ov017_021d83b0.value=(int)(4096.0f*value);
 data_ov017_021d83b0.x=(int)(4096.0f*x);
 data_ov017_021d83b0.y=(int)(4096.0f*y);
 data_ov017_021d83b0.z=(int)(4096.0f*z);
 return 1;
}
