#include <globaldefs.h>
ARM
struct GameState;struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(GameState*);
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_SetSpriteCellTouchRectangle(void*,unsigned short,unsigned short,unsigned short,unsigned);
// Original: arm9/ov004 @ 0x0216A810; symbol: func_ov004_0216a810; size: 0x200.
extern "C" int Graphics_UpdateLanguageSpecificRecordRectangles(State* self) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 void** head=(void**)Menu_GetDisplayRecordRegistry(self);
 void* rec=MenuRecordList_LocateByKey(head,30);
 if(!rec) return 0;
 if(MenuRecord_GetType(rec)!=1) return 0;
 switch(GameState_ReadSupportedFirmwareLanguage(game)) {
 case 1:Menu_SetSpriteCellTouchRectangle(rec,0,0,88,16);break;
 case 2:Menu_SetSpriteCellTouchRectangle(rec,0,0,80,16);break;
 case 3:Menu_SetSpriteCellTouchRectangle(rec,0,0,80,16);break;
 case 4:Menu_SetSpriteCellTouchRectangle(rec,0,0,96,16);break;
 case 5:Menu_SetSpriteCellTouchRectangle(rec,0,0,96,16);break;
 }
 rec=MenuRecordList_LocateByKey(head,31);
 if(!rec) return 0;
 if(MenuRecord_GetType(rec)!=1) return 0;
 switch(GameState_ReadSupportedFirmwareLanguage(game)) {
 case 1:Menu_SetSpriteCellTouchRectangle(rec,8,0,88,16);break;
 case 2:Menu_SetSpriteCellTouchRectangle(rec,16,0,80,16);break;
 case 3:Menu_SetSpriteCellTouchRectangle(rec,16,0,80,16);break;
 case 4:Menu_SetSpriteCellTouchRectangle(rec,0,0,96,16);break;
 case 5:Menu_SetSpriteCellTouchRectangle(rec,0,0,96,16);break;
 }
 return 0;
}
