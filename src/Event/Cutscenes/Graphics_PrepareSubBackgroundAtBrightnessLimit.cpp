#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <System/BGBases.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void *Network_GetConnectionManager();
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" int GameResources_GetSelectedScreenBrightness(char*,int);
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void GameState_EnableGlobalFlag64();
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define V(o) (*(volatile unsigned short*)(0x04001000+(o)))
// Original: arm9/ov001 @ 0x0215686C; symbol: func_ov001_0215686c; size: 0x2B4.
// Prepares sub-background palette, character data and screen at a brightness endpoint.
extern "C" void Graphics_PrepareSubBackgroundAtBrightnessLimit() {
 int enabled=1;
 if(((*(volatile unsigned short*)0x04000304&0x8000)>>15)==1) enabled=0;
 GameResources *resources=GameResources_GetInstance();
 int brightness=GameResources_GetSelectedScreenBrightness((char*)resources,1);
 if(!enabled) brightness=Graphics_DecodeSignedBrightness((volatile unsigned short*)0x0400006c);
 if((brightness==-16 || brightness==16) && enabled) {
  char *state=*(char**)((char*)resources+0x3734);
  char *connection=*(char**)(state+0x120);
  Network_GetConnectionManager();
  if((H(state,0x50)&0x20) || GameResources_GetMaskedPrimaryFlags(resources,0x1000)) {
   if(!(H(state,0x50)&0x100)) {
    if(!((H(state,0x50)&2) && connection && *(short*)(connection+0xd2)<0)) {
     if(H(state,0xa)!=5) return;
    }
   }
  }
  unsigned kind=H(state,0x16);
  if(kind==0xc69a || kind==0xc9e1) return;
  if(kind==1 && B(state,0xcf)==2 && B(state,0x109)!=0) return;
  SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(),1);
  GameState_EnableGlobalFlag64();
  *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1800;
  V(0xe)=(V(0xe)&0x43)|0xd00;
  V(8)=V(8)&~3;
  V(0xa)=(V(0xa)&~3)|2;
  V(0xc)=(V(0xc)&~3)|3;
  V(0xe)=(V(0xe)&~3)|1;
  *(volatile unsigned*)0x04001010=0;
  *(volatile unsigned*)0x04001014=0;
  *(volatile unsigned*)0x04001018=0;
  *(volatile unsigned*)0x0400101c=0;
  V(0x50)=0;
  char canvas[32];
  Graphics_InitializeCanvasTransferState(canvas);
  B(canvas,28)=(B(canvas,28)&~15)|3;
  char *palette=*(char**)((char*)resources+0x2c);
  CleanInvalidateCacheRange(palette+12,32);
  LoadToSubBGStandardPalette(palette+12,0,32);
  CleanCacheRange(palette+12,32);
  char tile[32];
  memset(tile,255,32);
  if(brightness==-16) memset(tile,17,32);
  CleanInvalidateCacheRange(tile,32);
  LoadToSubBG3CharacterData(tile,0x6000,32);
  CleanCacheRange(tile,32);
  unsigned short *screen=(unsigned short*)GetSubBG3ScreenBase();
  for(unsigned short i=0;i<0x300;++i) *screen++=0x300;
  B(state,0x104)=1;
  int absent;
  if(!connection || (connection && *(short*)(connection+0xd2)<0)) absent=1;
  else absent=0;
  if(H(state,0xa)>=3 && absent) {
   _Z16SetSubBrightnessP13GameResourcesii(resources,0,0);
   B(state,0x109)=1;
  }
 }
}
