#include <globaldefs.h>
ARM
extern "C" {
int sprintf(char*,const char*,...);
extern char KrakPot_QueueResultItemSprite_PathDataAniDC03DSpr[];
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
void* Graphics_GetGlobalOamTransferState();
unsigned char* Graphics_GetSubOamStagingBuffer();
void Graphics_ResetTilePayloadWithUnitScale(unsigned*);
unsigned ZoneSerializedRecord_GetPreferredAttribute(void*,int);
}
struct Fields { unsigned low:20; unsigned file:8; unsigned high:4; };
// Original: arm9/ov006 @ 0x0215FE34; symbol: func_ov006_0215fe34; size: 0x98.
extern "C" void KrakPot_QueueResultItemSprite(unsigned char* object,unsigned char* source) {
 char path[64];
 if(source) {
  void* loader=_ZN16BackgroundLoader11GetInstanceEv();
  Graphics_ResetTilePayloadWithUnitScale((unsigned*)(object+0x3b8));
  *(int*)(object+0x3f4)=5;
  object[0x416]=1;
  Graphics_GetGlobalOamTransferState();
  *(void**)(object+0x3cc)=Graphics_GetSubOamStagingBuffer()+0x1b8;
  *(int*)(object+0x3f0)=0x10000;
  *(int*)(object+0x3f8)=0;
  unsigned index=ZoneSerializedRecord_GetPreferredAttribute(source,0);
  sprintf(path,KrakPot_QueueResultItemSprite_PathDataAniDC03DSpr,((Fields*)(source+16))->file,index);
  *(unsigned*)(object+0x428)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
 }
}
