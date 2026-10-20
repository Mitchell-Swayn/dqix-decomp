#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void Graphics_GetGlobalBackgroundState(),Zone3D_GetMainInstance();
extern "C" void* SystemState_GetGlobalFlags();
extern "C" int SystemState_TestAnyFlags(void*,int);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void WorldMap_SubmitMarkerSprite(char*,unsigned int,unsigned int,int,unsigned char,unsigned char,unsigned short,unsigned char,unsigned int,unsigned int);
// Original: arm9/main @ 0x020E0F74; symbol: func_020e0f74; size: 0x1A0.
extern "C" ARM void Graphics_DrawConditionalSubDisplaySprites(unsigned char* self) {
 GameState::GetInstance();Graphics_GetGlobalBackgroundState();Zone3D_GetMainInstance();
 if(!SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),0x41)) {
  volatile unsigned int* display=(volatile unsigned int*)0x04001000;
  if(self[0x768])*display=(*display&~0x1f00)|0x1300;else *display=(*display&~0x1f00)|0x200;
  if(self[0x765]) {
   void* state=Network_GetConnectionManager();int x=5;if(Network_IsSessionActive(state))x+=0xe;
   WorldMap_SubmitMarkerSprite((char*)self,x<<12,0x5000,0,0x1f,1,255,255,0x1000,0x1000);
   WorldMap_SubmitMarkerSprite((char*)self,0x6a000,0x82000,1,0x26,1,255,255,0x1000,0x1000);
   if(*(unsigned short*)(self+0x766)<1000 && *(unsigned short*)(self+0x766)) {
    int y=0x1e;if(Network_IsSessionActive(state))y+=0xb;
    WorldMap_SubmitMarkerSprite((char*)self,0x5000,y<<12,2,0x33,1,255,255,0x1000,0x1000);
   }
   WorldMap_SubmitMarkerSprite((char*)self,0,0x81000,3,0x41,1,255,255,0x1000,0x1000);
  }
 }
}
