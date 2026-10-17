#pragma opt_lifetimes off
#pragma optimize_for_size off
#pragma opt_propagation off
#include <globaldefs.h>
ARM
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
extern "C" void _Z9LockMutexP5Mutex(void*); extern "C" void _Z11UnlockMutexP5Mutex(void*); extern "C" void _Z17LockResourceMutexv(); extern "C" void _Z19UnlockResourceMutexv(); extern "C" void ProcessorContext_SleepOrYieldPriorityPeers(u32); extern "C" void ProcessOverlayAndReturnSuccess(void *);
extern "C" volatile u32 data_01ffd348; extern "C" volatile u8 data_01ffd344; extern "C" u8 data_020e8f20[]; extern "C" u8 data_01ffd34c[]; extern "C" u8 data_01ffd364[]; extern "C" volatile u8 data_01ffd340; extern "C" u8 data_01ffd394[];
// Original: arm9/main @ 0x020A1BB4; symbol: func_020a1bb4; size: 0x118.
extern "C" int RecordMappedIndexUnderOptionalMutex(u32 id) {
 int result=0; if(id>=35) return result;
 u8 *map=data_020e8f20; u32 slot=data_01ffd348;
 if(data_01ffd344) _Z9LockMutexP5Mutex(data_01ffd34c);
 volatile signed char *entry=(volatile signed char*)data_01ffd364+slot*6; entry[*(u32*)(map+id*8)]=id|0x40;
 if(data_01ffd344) _Z11UnlockMutexP5Mutex(data_01ffd34c);
 u32 zero=0; slot=(u32)&data_01ffd340; while(*(u8*)slot) ProcessorContext_SleepOrYieldPriorityPeers(zero);
 data_01ffd340=1; _Z17LockResourceMutexv(); ProcessOverlayAndReturnSuccess(data_01ffd394+id*44); _Z19UnlockResourceMutexv(); data_01ffd340=0;
 if(data_01ffd344) _Z9LockMutexP5Mutex(data_01ffd34c);
 entry[*(u32*)(map+id*8)]=-1;
 if(data_01ffd344) _Z11UnlockMutexP5Mutex(data_01ffd34c);
 return 1;
}
