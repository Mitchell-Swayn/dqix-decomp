#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void Graphics_GetGlobalBackgroundState(),ReadGlobalValueAt020FB3F0();
extern "C" void* GetGlobalStatePointer();
extern "C" int TestWordMaskNonzero(void*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" void Object_ConfigureAndSubmitIndexedRecord(char*,unsigned int,unsigned int,int,unsigned char,unsigned char,unsigned short,unsigned char,unsigned int,unsigned int);
// Original: arm9/main @ 0x020E0F74; symbol: func_020e0f74; size: 0x1A0.
extern "C" ARM void Graphics_DrawConditionalSubDisplaySprites(unsigned char* self) {
 GameState::GetInstance();Graphics_GetGlobalBackgroundState();ReadGlobalValueAt020FB3F0();
 if(!TestWordMaskNonzero(GetGlobalStatePointer(),0x41)) {
  volatile unsigned int* display=(volatile unsigned int*)0x04001000;
  if(self[0x768])*display=(*display&~0x1f00)|0x1300;else *display=(*display&~0x1f00)|0x200;
  if(self[0x765]) {
   void* state=Object_GetGlobalConnectionState();int x=5;if(IsFirstWordNonzero(state))x+=0xe;
   Object_ConfigureAndSubmitIndexedRecord((char*)self,x<<12,0x5000,0,0x1f,1,255,255,0x1000,0x1000);
   Object_ConfigureAndSubmitIndexedRecord((char*)self,0x6a000,0x82000,1,0x26,1,255,255,0x1000,0x1000);
   if(*(unsigned short*)(self+0x766)<1000 && *(unsigned short*)(self+0x766)) {
    int y=0x1e;if(IsFirstWordNonzero(state))y+=0xb;
    Object_ConfigureAndSubmitIndexedRecord((char*)self,0x5000,y<<12,2,0x33,1,255,255,0x1000,0x1000);
   }
   Object_ConfigureAndSubmitIndexedRecord((char*)self,0,0x81000,3,0x41,1,255,255,0x1000,0x1000);
  }
 }
}
