#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" char* KrakPot_FindLayoutHitRegion(void*,int);
// Original: arm9/ov006 @ 0x0215729C; symbol: ConfigureSevenIndexedRecordEnableBits; size: 0xCC.
extern "C" void KrakPot_ConfigureRecipeBrowserHitRegions(void* self){char* record;record=KrakPot_FindLayoutHitRegion(self,80);if(record)B(record,0x16)&=~1;record=KrakPot_FindLayoutHitRegion(self,79);if(record)B(record,0x16)|=1;record=KrakPot_FindLayoutHitRegion(self,14);if(record)B(record,0x16)&=~1;record=KrakPot_FindLayoutHitRegion(self,15);if(record)B(record,0x16)|=1;record=KrakPot_FindLayoutHitRegion(self,21);if(record)B(record,0x16)&=~1;record=KrakPot_FindLayoutHitRegion(self,65);if(record)B(record,0x16)&=~1;record=KrakPot_FindLayoutHitRegion(self,66);if(record)B(record,0x16)&=~1;}
