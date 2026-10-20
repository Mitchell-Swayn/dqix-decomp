#include <globaldefs.h>
ARM
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);}
// Original: arm9/ov006 @ 0x02155508; symbol: func_ov006_02155508; size: 0xA8.
extern "C" void CancelTwoBackgroundTasksAndResetObject(unsigned char* p){
if(*(unsigned short*)(p+0xae2)&1)return;
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
if(*(int*)(p+0xad4)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0xad4));*(int*)(p+0xad4)=-1;}
*(int*)(p+0xad4)=-1;p[0xade]=0;*(unsigned short*)(p+0xae2)&=~2;
if(*(int*)(p+0xad8)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0xad8));*(int*)(p+0xad8)=-1;}
*(int*)(p+0xad8)=-1;p[0xadf]=0;
*(unsigned*)(p+0x1b4)=0;*(unsigned*)(p+0x1b8)=0;*(unsigned*)(p+0x1c0)=0;
*(unsigned short*)(p+0xae2)=(*(unsigned short*)(p+0xae2)|1)&~4;
}
