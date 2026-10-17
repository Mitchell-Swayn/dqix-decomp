#include <globaldefs.h>
ARM
struct Selection {char unknown00[0x4c];int pageSize;char unknown50[12];short first,last,current;char unknown62[6];short delay,elapsed;unsigned char state,flags,result,repeating,paging;};
extern "C" unsigned char data_02114e30[];
extern "C" int TestReleasedInputMask(void*,unsigned);
extern "C" int Input_PollKeyRepeatCountdown(void*,unsigned);
extern "C" int Object_TestNewlySetHalfwordMask(void*,unsigned);
extern "C" int Input_TestDirectionalKeyAndModeModifier(void*);
extern "C" int Input_TestModeDependentButtonCombination(void*);
extern "C" int* GetLinkedNodeByBoundedIndex(void*,int);
extern "C" void SetByteField6CAndInvokeCallbackOnce(void*);
extern "C" void ResetOwnerStateAndNotifyCallback(void*,int);
// Original: arm9/main @ 0x02029634; symbol: func_02029634; size: 0x354.
extern "C" void Selection_ProcessRepeatedNavigationPagingAndConfirmCancel(Selection* self,short delta) {
 if(self->state)return;
 if(!(self->flags&1)&&self->first>=0&&self->first<=self->last) {
 if(TestReleasedInputMask(data_02114e30,0x40)){self->repeating=0;self->delay=0;self->elapsed=0;}
 if(TestReleasedInputMask(data_02114e30,0x80)){self->repeating=0;self->delay=0;self->elapsed=0;}
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
 if(Input_PollKeyRepeatCountdown(data_02114e30,0x20)){self->current-=self->pageSize;if(self->current<self->first)self->current=self->first;}
 else if(Input_PollKeyRepeatCountdown(data_02114e30,0x10)){self->current+=self->pageSize;if(self->last<self->current)self->current=self->last;}
 }
 }
 int* entry=GetLinkedNodeByBoundedIndex(self,self->current);
 if(self->flags&1)return;
 if(Object_TestNewlySetHalfwordMask(data_02114e30,1)) {
 unsigned flags=self->flags;
 if(!(flags&2)&&!entry){SetByteField6CAndInvokeCallbackOnce(self);self->result=1;return;}
 if(entry) {
 if(self->current<0||*entry!=1) {
   if(flags&2)return;SetByteField6CAndInvokeCallbackOnce(self);self->result=1;return;
 }
 if(*entry==1&&entry[14]==0){ResetOwnerStateAndNotifyCallback(entry,1);self->state=4;}
 }
 }else {
 if(!(self->flags&4)&&Object_TestNewlySetHalfwordMask(data_02114e30,2)){self->result=0;SetByteField6CAndInvokeCallbackOnce(self);return;}
 if(Object_TestNewlySetHalfwordMask(data_02114e30,4)){self->result=0;SetByteField6CAndInvokeCallbackOnce(self);}
 }
}
