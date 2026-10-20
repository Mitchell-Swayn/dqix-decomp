#include <globaldefs.h>
#include <Memory/HMRFAllocator.h>
ARM
extern "C"{int InitializeAllocatorListAndValidateState(void*,HMRFAllocator*);void Object_InvokeLockMutex();void SoundCommand_UnlockMutex();void* ComputeMaskedIndexPopulationStrideAndBase(void*,unsigned,const void*,int);}
#pragma force_active on
// Original: arm9/main @ 0x020D2EEC; symbol: func_020d2eec; size: 0x3C.
extern "C" char* ResolveRelativeOrAbsoluteTablePointerUnderLock(char* p,int index){Object_InvokeLockMutex();unsigned value=*(unsigned*)(p+60+index*4);char* result;if(value){if(value<0x2000000)result=p+value;else result=(char*)value;}else result=0;SoundCommand_UnlockMutex();return result;}
