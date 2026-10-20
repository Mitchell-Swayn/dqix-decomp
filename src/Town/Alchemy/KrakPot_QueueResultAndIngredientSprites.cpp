#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void KrakPot_ResetItemPreviewSprites(void*);void* _ZN16BackgroundLoader11GetInstanceEv();unsigned ZoneSerializedRecord_GetPreferredAttribute(void*,int);void __clear(void*,unsigned);int sprintf(char*,const char*,...);int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);extern char KrakPot_QueueResultAndIngredientSprites_PathDataAniDC03DSpr[];}
// Original: arm9/ov006 @ 0x02156F04; symbol: Resource_QueueFourIndexedModelRecords; size: 0xd8.
extern "C" void KrakPot_QueueResultAndIngredientSprites(unsigned char* self,unsigned char* records){KrakPot_ResetItemPreviewSprites(self);unsigned char* count;unsigned char* output=self+0x894;void* loader=_ZN16BackgroundLoader11GetInstanceEv();self[0x12bb]=0;count=self+0xbb;count+=0x1200;for(unsigned char i=0;i<4;++i){H(output,0x74)=H(records,0x70);if(H(output,0x74)>0){output[0x7a]=1;unsigned value=ZoneSerializedRecord_GetPreferredAttribute(records,0);char name[64];__clear(name,64);sprintf(name,KrakPot_QueueResultAndIngredientSprites_PathDataAniDC03DSpr,((unsigned)W(records,16)<<4)>>24,value);W(output,0x70)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,name,0);if(i)++*count;}records+=0x74;output+=0x7c;}}
