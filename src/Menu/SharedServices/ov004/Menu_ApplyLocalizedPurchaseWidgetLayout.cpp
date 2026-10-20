#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct State; struct GameState;
extern "C" {
extern "C" unsigned int GameState_ReadSupportedFirmwareLanguage(GameState* state);
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value);
extern "C" unsigned MenuRecord_GetType(void* self);
extern "C" void Menu_SetSpriteCellTouchRectangle(void* p, unsigned short a, unsigned short b, unsigned short c, unsigned int d);
}
struct Position { int x,y,z; Position(int a,int b):y(a),z(b){} };
struct Widget { virtual void Reserved0(); virtual void Reserved1(); virtual void Reserved2(); virtual void Reserved3(); virtual void Reserved4(); virtual void Reserved5(); virtual void Reserved6(); virtual void SetPosition(int*); };
// Original: arm9/ov004 @ 0x0215DE9C; symbol: Menu_ApplyLocalizedPurchaseWidgetLayout; size: 0x2AC.
// Adjusts positions and extents of widgets 702/703 for the supported firmware language.
extern "C" int Menu_ApplyLocalizedPurchaseWidgetLayout(State* self){
 GameState* state=(GameState*)((void*)GameState::GetInstance());
 void** head=(void**)Menu_GetDisplayRecordRegistry(self);
 Widget* widget=(Widget*)MenuRecordList_LocateByKey(head,702);
 if(!widget) return 0;
 if(MenuRecord_GetType(widget)!=1) return 0;
 Position position(0x5a000,0);
 switch(GameState_ReadSupportedFirmwareLanguage(state)){
 case 1: position.x=0x90000; widget->SetPosition(&position.x); Menu_SetSpriteCellTouchRectangle(widget,0,0,44,12); break;
 case 2: position.x=0x90000; widget->SetPosition(&position.x); Menu_SetSpriteCellTouchRectangle(widget,0,0,44,12); break;
 case 3: position.x=0x98000; widget->SetPosition(&position.x); Menu_SetSpriteCellTouchRectangle(widget,0,0,32,12); break;
 case 4: position.x=0x8c000; widget->SetPosition(&position.x); Menu_SetSpriteCellTouchRectangle(widget,0,0,50,12); break;
 case 5: position.x=0x8c000; widget->SetPosition(&position.x); Menu_SetSpriteCellTouchRectangle(widget,0,0,50,12); break;
 }
 widget=(Widget*)MenuRecordList_LocateByKey(head,703);
 if(!widget) return 0;
 if(MenuRecord_GetType(widget)!=1) return 0;
 switch(GameState_ReadSupportedFirmwareLanguage(state)){
 case 1: Menu_SetSpriteCellTouchRectangle(widget,0,0,44,12); break;
 case 2: Menu_SetSpriteCellTouchRectangle(widget,0,0,44,12); break;
 case 3: Menu_SetSpriteCellTouchRectangle(widget,0,0,36,12); break;
 case 4: Menu_SetSpriteCellTouchRectangle(widget,0,0,48,12); break;
 case 5: Menu_SetSpriteCellTouchRectangle(widget,0,0,48,12); break;
 }
 return 0;
}
