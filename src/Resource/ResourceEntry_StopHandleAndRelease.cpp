#include <globaldefs.h>
ARM
extern "C" void SoundCommand_SubmitOpcodeSixWithModeTwo(int,int); extern "C" void DispatchCommandOneWithValue(unsigned); extern "C" void DetachOwnerLinksAndReturnChildToAllocatorList(void*);
// Original: arm9/main @ 0x020BC6FC; symbol: func_020bc6fc; size: 0x38.
extern "C" void ResourceEntry_StopHandleAndRelease(unsigned char* p){if(p[0x2c]==2)SoundCommand_SubmitOpcodeSixWithModeTwo(p[0x3c],-723);DispatchCommandOneWithValue(p[0x3c]);DetachOwnerLinksAndReturnChildToAllocatorList(p);}
