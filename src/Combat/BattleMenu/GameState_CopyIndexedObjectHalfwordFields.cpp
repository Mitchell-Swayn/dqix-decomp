#include <globaldefs.h>
ARM
struct GameState; struct GameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameObject* GameState_GetValidObjectByIndex(GameState*,int);
// Original: arm9/ov000 @ 0x021710AC; symbol: func_ov000_021710ac; size: 0x8C.
extern "C" void GameState_CopyIndexedObjectHalfwordFields(char* self,int index,int enabled) {
 *(int*)(self+0x4c)=index;
 if(enabled) *(unsigned char*)(self+0x24)|=2;
 else *(unsigned char*)(self+0x24)&=~2;
 int valid;
 if(index>=0 && index<=3) valid=1; else valid=0;
 if(!valid) return;
 char* obj=(char*)GameState_GetValidObjectByIndex((GameState*)_ZN9GameState11GetInstanceEv(),index);
 if(!obj) return;
 *(unsigned short*)(self+8)=*(unsigned short*)(*(char**)(obj+0x134)+0x30);
 *(unsigned short*)(self+10)=*(unsigned short*)(*(char**)(obj+0x134)+0x32);
 *(unsigned short*)(self+12)=*(unsigned short*)(*(char**)(obj+0x130)+4);
 *(unsigned short*)(self+14)=*(unsigned short*)(*(char**)(obj+0x130)+6);
}
