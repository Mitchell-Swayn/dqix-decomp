#include <globaldefs.h>
ARM
#pragma always_inline on
struct Entry { unsigned char id,a,b; signed char x,y; unsigned char c,d; };
extern "C" Entry data_ov023_021fd7fc[];
inline void SetPair(short* out,int a,int b) { out[0]=a; out[1]=b; }
// Original: arm9/ov023 @ 0x021E7CEC; symbol: func_ov023_021e7cec; size: 0xA0.
extern "C" void Graphics_ConfigureRecordFromByteLayoutTable(unsigned char* self,int id,int x,int y) {
 for(int i=0;data_ov023_021fd7fc[i].id!=255;i++) {
  Entry* entry=&data_ov023_021fd7fc[i];
  if(entry->id==id) {
   self[0x129]=entry->id;
   *(short*)(self+0x11c)=x;
   *(short*)(self+0x11e)=y;
   SetPair((short*)(self+0x120),entry->a,entry->b);
   SetPair((short*)(self+0x118),entry->x,entry->y);
   SetPair((short*)(self+0x124),entry->c,entry->d);
   self[0x12d]=0;
   self[0x12e]=0;
   if(entry->id==16) { self[0x12d]=1; self[0x12e]=1; }
   return;
  }
 }
}
