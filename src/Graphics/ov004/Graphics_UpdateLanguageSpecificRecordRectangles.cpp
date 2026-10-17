#include <globaldefs.h>
ARM
struct GameState;struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(GameState*);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* func_ov023_021f6880(void**,unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov023_021fb25c(void*,unsigned short,unsigned short,unsigned short,unsigned);
// Original: arm9/ov004 @ 0x0216A810; symbol: func_ov004_0216a810; size: 0x200.
extern "C" int Graphics_UpdateLanguageSpecificRecordRectangles(State* self) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 void** head=(void**)func_ov011_021849c8(self);
 void* rec=func_ov023_021f6880(head,30);
 if(!rec) return 0;
 if(OV023_ReadHalfwordField04(rec)!=1) return 0;
 switch(GameState_ReadSupportedFirmwareLanguage(game)) {
 case 1:func_ov023_021fb25c(rec,0,0,88,16);break;
 case 2:func_ov023_021fb25c(rec,0,0,80,16);break;
 case 3:func_ov023_021fb25c(rec,0,0,80,16);break;
 case 4:func_ov023_021fb25c(rec,0,0,96,16);break;
 case 5:func_ov023_021fb25c(rec,0,0,96,16);break;
 }
 rec=func_ov023_021f6880(head,31);
 if(!rec) return 0;
 if(OV023_ReadHalfwordField04(rec)!=1) return 0;
 switch(GameState_ReadSupportedFirmwareLanguage(game)) {
 case 1:func_ov023_021fb25c(rec,8,0,88,16);break;
 case 2:func_ov023_021fb25c(rec,16,0,80,16);break;
 case 3:func_ov023_021fb25c(rec,16,0,80,16);break;
 case 4:func_ov023_021fb25c(rec,0,0,96,16);break;
 case 5:func_ov023_021fb25c(rec,0,0,96,16);break;
 }
 return 0;
}
