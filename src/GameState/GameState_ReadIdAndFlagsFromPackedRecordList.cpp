#include <globaldefs.h>
ARM
typedef unsigned int u32; typedef int s32; typedef unsigned short u16; typedef short s16; typedef unsigned char u8;
extern "C" u8 *_ZN9GameState11GetInstanceEv(); extern "C" void *memcpy(void *, const void*,u32);
struct Record {s16 id; u16 first:1; u16 second:1; u16 :14;};
// Original: arm9/main @ 0x020AC2D4; symbol: func_020ac2d4; size: 0xF4.
extern "C" int GameState_ReadIdAndFlagsFromPackedRecordList(void *,s16 *ids,Record *output,int count) {
 Record local; // This routine writes id and two flag bits; it preserves the other storage bits.
 u8 *state=_ZN9GameState11GetInstanceEv()+0x2c4;
 for(int i=0;i<count;i++) { s16 id=ids[i]; if(id<0) continue;
 bool found=false; u16 *p=(u16*)(state+0x7800);
 for(u32 j=0;j<0x1d7;j++) { int current=(*p&0xfffc)>>2; if(current<=0){found=true;break;} if(current==id){found=true;break;}p++; }
 if(found) {local.id=id;local.first=(*p&2)>>1;local.second=(*p&1);memcpy(output+i,&local,4);}
 }return 1;
}
