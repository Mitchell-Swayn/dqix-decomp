#include <globaldefs.h>
ARM
struct Selection {char unknown00[0x4c];int pageSize;char unknown50[12];short first,last,current;char unknown62[6];short delay,elapsed;unsigned char state,flags,result,repeating,paging;};
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
extern "C" int Input_IsKeyMaskReleased(void*,unsigned);
extern "C" int Input_PollKeyRepeatCountdown(void*,unsigned);
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
extern "C" int Input_TestDirectionalKeyAndModeModifier(void*);
extern "C" int Input_TestModeDependentButtonCombination(void*);
extern "C" int* DebugMenu_GetEntryByIndex(void*,int);
extern "C" void DebugMenu_CloseAndNotify(void*);
extern "C" void DebugMenu_BeginOpen(void*,int);
// Original: arm9/main @ 0x02029634; symbol: func_02029634; size: 0x354.
extern "C" void DebugMenu_ProcessNavigationAndSelection(Selection* self,short delta) {
 if(self->state)return;
 if(!(self->flags&1)&&self->first>=0&&self->first<=self->last) {
 if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40)){self->repeating=0;self->delay=0;self->elapsed=0;}
 if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80)){self->repeating=0;self->delay=0;self->elapsed=0;}
 if(self->repeating)self->elapsed+=delta;
 if(Input_TestDirectionalKeyAndModeModifier(self)) {
 if(self->elapsed>=self->delay) {
 self->elapsed=0;self->delay-=5;if(self->delay<0)self->delay=0;
 if(self->current!=self->first||!self->repeating){--self->current;if(self->current<self->first)self->current=self->last;}
 }
 if(!self->repeating){self->delay=15;self->elapsed=0;}self->repeating=1;
 } else if(Input_TestModeDependentButtonCombination(self)) {
 if(self->elapsed>=self->delay) {
 self->elapsed=0;self->delay-=5;if(self->delay<0)self->delay=0;
 if(self->current!=self->last||!self->repeating){++self->current;if(self->last<self->current)self->current=self->first;}
 }
 if(!self->repeating){self->delay=15;self->elapsed=0;}self->repeating=1;
 }
 if(self->paging) {
 if(Input_PollKeyRepeatCountdown(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20)){self->current-=self->pageSize;if(self->current<self->first)self->current=self->first;}
 else if(Input_PollKeyRepeatCountdown(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10)){self->current+=self->pageSize;if(self->last<self->current)self->current=self->last;}
 }
 }
 int* entry=DebugMenu_GetEntryByIndex(self,self->current);
 if(self->flags&1)return;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1)) {
 unsigned flags=self->flags;
 if(!(flags&2)&&!entry){DebugMenu_CloseAndNotify(self);self->result=1;return;}
 if(entry) {
 if(self->current<0||*entry!=1) {
   if(flags&2)return;DebugMenu_CloseAndNotify(self);self->result=1;return;
 }
 if(*entry==1&&entry[14]==0){DebugMenu_BeginOpen(entry,1);self->state=4;}
 }
 }else {
 if(!(self->flags&4)&&Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){self->result=0;DebugMenu_CloseAndNotify(self);return;}
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4)){self->result=0;DebugMenu_CloseAndNotify(self);}
 }
}
