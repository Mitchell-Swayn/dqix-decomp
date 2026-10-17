#include <globaldefs.h>
ARM
#include <System/Cache.h>
extern "C" void Object_InvokeLockMutex();extern "C" void UnlockGlobalCommandMutex();
// Original: arm9/main @ 0x020D2EB8; symbol: func_020d2eb8; size: 0x34.
extern "C" void SoundCommand_SetCachedIndexedWordUnderLock(unsigned char* object,int index,unsigned value){Object_InvokeLockMutex();*(unsigned*)(object+index*4+0x3c)=value;CleanCacheRange(object+0x3c+index*4,4);UnlockGlobalCommandMutex();}
