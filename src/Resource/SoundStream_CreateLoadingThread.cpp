#include <globaldefs.h>
ARM
#include <System/ProcessorContext.h>
#include <System/Mutex.h>
#include <Memory/SignedAllocator.h>
extern "C" void BlockUntilWorkNodeAvailableAndProcessUnderMutex();
// Original: arm9/main @ 0x020BF2F8; symbol: func_020bf2f8; size: 0x60.
extern "C" void SoundStream_CreateLoadingThread(char* p,unsigned priority){PopulateProcessorContext((ProcessorContext*)p,(unsigned)BlockUntilWorkNodeAvailableAndProcessUnderMutex,(unsigned)p,(unsigned)(p+0x4c0),0x400,priority);((SignedAllocatorList*)(p+0x4e0))->Initialize(0);ZeroInitializeMutex((Mutex*)(p+0x4c8));*(unsigned*)(p+0x4c4)=0;*(unsigned*)(p+0x4c0)=0;MarkContextReadyAndSwitch((ProcessorContext*)p);}
