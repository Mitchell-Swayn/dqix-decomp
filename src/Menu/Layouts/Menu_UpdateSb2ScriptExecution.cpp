#include <globaldefs.h>
struct State { char prefix[0xb8]; char memberb8[0x3c]; unsigned active; char padf8[0x14]; int pending,current; char pad114[0xbc]; unsigned ticks; };
struct GameState { char prefix[0x7f71]; unsigned char cycle; };
extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" unsigned GameState_ReadByteAtOffset4(GameState*);
extern "C" unsigned GameState_ReadUnknown7f70(GameState*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" int ContainsKeyInRelativeEightByteRecordTable(void*,int);
extern "C" void Script_StartArchiveEntry(void*,int);
extern "C" void GameState_ProcessPendingOperationIfPresent(void*);
// Original: arm9/ov011 @ 0x021848A8; symbol: func_ov011_021848a8; size: 0x104.
extern "C" void Menu_UpdateSb2ScriptExecution(State* self) {
 GameState* game=_ZN9GameState11GetInstanceEv();
 if(GameState_ReadByteAtOffset4(game)==6) {
  if(GameState_ReadUnknown7f70(game)==1) {
   self->ticks+=_ZNK9GameState12GetTickCountEv(game);
   if(self->ticks>0xe10) {
    self->ticks=0;
    self->pending=999;
    game->cycle=(unsigned char)(game->cycle+1)%3;
   }
  } else self->ticks=0;
 }
 if(self->pending>=0) {
  if(!ContainsKeyInRelativeEightByteRecordTable(self->memberb8,self->pending)) { self->pending=-1; return; }
  self->current=self->pending;
  self->pending=-1;
  Script_StartArchiveEntry(self->memberb8,self->current);
  if(self->active) self->current=-1;
  return;
 }
 if(self->current<0) return;
 GameState_ProcessPendingOperationIfPresent(self->memberb8);
 if(self->active) self->current=-1;
}
