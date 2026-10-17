#include <globaldefs.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Object_InitializeEmbeddedGraphicsStateWrapper(void*);
extern "C" unsigned Object_ReadGlobalDisplayContextWord();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void RemoveNonnegativeStoredBackgroundTask(int*);
extern "C" void Resource_InitializeSharedRecordState(char*,int,int);
extern "C" void func_ov023_021dcd18(void*);
extern "C" void* data_ov023_021ff9e0[];
extern "C" unsigned char data_02114e20[];
struct Bits {unsigned char retain:1,rest:7;};
// Original: arm9/ov023 @ 0x021DC354; symbol: func_ov023_021dc354; size: 0x134.
extern "C" void Resource_DestroyAndResetSharedRecordState(char* self) {
 RemoveNonnegativeStoredBackgroundTask((int*)(self+0x780));
 self[0x77e]=-1;
 if(!(*(unsigned short*)(self+0x774)&16)) BackgroundLoader_CancelEightTasksAndResetState(Object_ReadGlobalDisplayContextWord());
 RemoveNonnegativeStoredBackgroundTask((int*)(self+0x734));
 int* tasks=(int*)(self+0x338);
 int i=0;
 tasks+=0x100;
 for(;i<7;++i) RemoveNonnegativeStoredBackgroundTask(tasks+i);
 if(*(void**)(self+0xc8)) Object_InitializeEmbeddedGraphicsStateWrapper(*(void**)(self+0xc8));
 if(*(void**)(self+0xc4)) Object_InitializeEmbeddedGraphicsStateWrapper(*(void**)(self+0xc4));
 if(self[0x77b]!=1) func_ov023_021dcd18(self);
 if(*(void**)(self+0x44)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x44));
 if(*(void**)(self+0x40)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x40));
 if(*(void**)(self+0x3c)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x3c));
 _ZN13SafeAllocator7DestroyEv(self+0x28);
 _ZN13SafeAllocator7DestroyEv(self+0x14);
 _ZN13SafeAllocator7DestroyEv(self);
 if(data_ov023_021ff9e0[1]) {
  if(!((Bits*)(self+0x79b))->retain) Memory_FreeThroughAllocatorUnion(data_02114e20,data_ov023_021ff9e0[1]);
  data_ov023_021ff9e0[1]=0;
 }
 Resource_InitializeSharedRecordState(self,-1,self[0x77b]);
}
