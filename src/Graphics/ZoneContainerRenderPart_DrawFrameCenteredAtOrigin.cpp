#include <globaldefs.h>
ARM
extern "C" int ZoneContainerRenderPart_DrawTexturedQuad(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/main @ 0x02047648; symbol: DrawEnabledIndexedRecordEntriesWithGeometryReset.
extern "C" void ZoneContainerRenderPart_DrawFrameCenteredAtOrigin(char* self,int index,int argument){
struct Flags{unsigned char enabled:1;unsigned char visible:1;unsigned char rest:6;};if(!((Flags*)(self+0x84))->enabled||!((Flags*)(self+0x84))->visible||S(self,0x82)<=0)return;char* record=P(self,8)+index*8;if(!P(record,4)||!B(record,2))return;volatile unsigned* geometry=(volatile unsigned*)0x04000444;geometry[0]=0;geometry[31]=0x7fffffff;geometry[32]=0x4210;geometry[11]=(-(B(record,0)<<12))>>1;geometry[11]=0;geometry[11]=0;char* entry=P(record,4);for(int i=0;i<B(record,2);i++,entry+=8)ZoneContainerRenderPart_DrawTexturedQuad(self,entry,argument);*(volatile unsigned*)0x04000448=1;
}
