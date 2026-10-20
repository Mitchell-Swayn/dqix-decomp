#include <globaldefs.h>
struct State { char header[0x10c]; unsigned current; char padding110[0xb0]; unsigned short field1c0,field1c2,field1c4,field1c6; };
struct Global { char header[0x998]; unsigned busy; };
extern "C" Global* TextContext_GetSharedInstance();
extern "C" unsigned TextWindow_GetChoiceResult(Global*);
extern "C" void Menu_StartIndexedCallback(State*,unsigned);
// Original: arm9/ov011 @ 0x02184AE4; symbol: func_ov011_02184ae4; size: 0xE8.
extern "C" void Menu_DispatchCompletedChoiceActions(State* self) {
 if(!self->field1c4 && !self->field1c6 && !self->field1c0 && !self->field1c2) return;
 Global* global=TextContext_GetSharedInstance();
 if(global->busy) return;
 switch(TextWindow_GetChoiceResult(global)) {
 case 0:
  if(self->field1c4) { self->current=self->field1c4; self->field1c4=0; self->field1c6=0; }
  if(self->field1c0) { Menu_StartIndexedCallback(self,self->field1c0); self->field1c0=0; self->field1c2=0; }
  break;
 case 1:
  if(self->field1c6) { self->current=self->field1c6; self->field1c4=0; self->field1c6=0; }
  if(self->field1c2) { Menu_StartIndexedCallback(self,self->field1c2); self->field1c0=0; self->field1c2=0; }
  break;
 }
}
