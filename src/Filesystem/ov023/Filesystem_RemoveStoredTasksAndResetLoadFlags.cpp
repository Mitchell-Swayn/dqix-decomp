#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void RemoveNonnegativeStoredBackgroundTask(int*);
// Original: arm9/ov023 @ 0x021DCDF4; symbol: func_ov023_021dcdf4; size: 0x94.
extern "C" void Filesystem_RemoveStoredTasksAndResetLoadFlags(unsigned char* p){
 _ZN16BackgroundLoader11GetInstanceEv();
 if(p[0x776]){
 RemoveNonnegativeStoredBackgroundTask((int*)(p+0x734));
 for(int i=0;i<7;i++)RemoveNonnegativeStoredBackgroundTask((int*)(p+0x738+i*4));
 *(int*)(p+0x754)=0;
 *(unsigned short*)(p+0x774)|=1;
 }
 *(short*)(p+0x772)=-1;
 *(short*)(p+0x770)=-2;
 *(signed char*)(p+0x779)=-1;
 *(unsigned short*)(p+0x774)&=~4;
 *(unsigned short*)(p+0x774)&=~0x2000;
}
