#include <globaldefs.h>
ARM
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void CancelTwoBackgroundTasksAndResetObject(unsigned char*);
void ItemDetail_QueueQuantityModeArchive(char*,int);
}
#define W(o) (*(int*)(self+(o)))
// Original: arm9/ov006 @ 0x02155630; symbol: func_ov006_02155630; size: 0xE0.
// Installs pending zone selection pointers and resets both background task slots.
extern "C" void SetPendingZoneSelectionAndCancelTasks(unsigned char* self,void* entry,unsigned char* packed,void* counts) {
 if(!entry || !packed) {CancelTwoBackgroundTasksAndResetObject(self);return;}
 if(packed) {
  if((((unsigned)*(unsigned short*)(packed+2)<<30)>>31)==0) {CancelTwoBackgroundTasksAndResetObject(self);return;}
 }
 ItemDetail_QueueQuantityModeArchive((char*)self+0xae4,1);
 *(short*)(self+0x12b8)=0;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(W(0xad4)>=0) {_ZN16BackgroundLoader10RemoveTaskEi(loader,W(0xad4));W(0xad4)=-1;}
 W(0xad4)=-1;self[0xade]=0;
 *(void**)(self+0x1b8)=entry;*(void**)(self+0x1c0)=packed;*(void**)(self+0x1a8)=counts;
 *(unsigned short*)(self+0xae2)=(*(unsigned short*)(self+0xae2)|2)&~1;
 if(W(0xad8)>=0) {_ZN16BackgroundLoader10RemoveTaskEi(loader,W(0xad8));W(0xad8)=-1;}
 W(0xad8)=-1;self[0xadf]=0;
}
