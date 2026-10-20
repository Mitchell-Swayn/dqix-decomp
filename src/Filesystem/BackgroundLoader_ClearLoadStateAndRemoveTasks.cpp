#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void BackgroundLoader_RemoveTaskAndInvalidateHandle(void*,int*);
// Original: arm9/main @ 0x02022BB0; symbol: func_02022bb0; size: 0x1C8.
extern "C" void BackgroundLoader_ClearLoadStateAndRemoveTasks(unsigned char* p){p[0x9c3]=0;p[0x9c2]=0;p[0x9c5]=0;p[0x9b8]=0;p[0xa34]=0xff;p[0x9c4]=0;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2508));*(int*)(p+2508)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2552));*(int*)(p+2552)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2512));*(int*)(p+2512)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2516));*(int*)(p+2516)=-1;
for(int i=0;i<8;i++)BackgroundLoader_RemoveTaskAndInvalidateHandle(p,(int*)(p+0x9d8+i*4));
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2556));*(int*)(p+2556)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2560));*(int*)(p+2560)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2564));*(int*)(p+2564)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2568));*(int*)(p+2568)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2576));*(int*)(p+2576)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2580));*(int*)(p+2580)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2584));*(int*)(p+2584)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2588));*(int*)(p+2588)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2592));*(int*)(p+2592)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2596));*(int*)(p+2596)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2600));*(int*)(p+2600)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2604));*(int*)(p+2604)=-1;
_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+2608));*(int*)(p+2608)=-1;
if(p[0x9c1]!=2)return;_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),*(int*)(p+0xa0c));*(int*)(p+0xa0c)=-1;}
