#include <globaldefs.h>
ARM
extern "C" char* ResolveRelativeOrAbsoluteTablePointerUnderLock(void*,void*);extern "C" void SoundCommand_SetCachedIndexedWordUnderLock(void*,void*,int);extern "C" void DispatchCommandThirtyTwoWithTwoValues(char*,char*);
// Original: arm9/main @ 0x020BE4F4; symbol: func_020be4f4; size: 0x48.
extern "C" void ResourceManager_ClearMatchingRangeAndSubmit(char* start,int length,void* a,void* b){if(start==ResolveRelativeOrAbsoluteTablePointerUnderLock(a,b))SoundCommand_SetCachedIndexedWordUnderLock(a,b,0);DispatchCommandThirtyTwoWithTwoValues(start,start+length);}
