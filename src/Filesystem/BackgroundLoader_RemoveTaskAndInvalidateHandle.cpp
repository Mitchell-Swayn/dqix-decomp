#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(); extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
// Original: arm9/main @ 0x02022B90; symbol: func_02022b90; size: 0x20.
 extern "C" void BackgroundLoader_RemoveTaskAndInvalidateHandle(void*,int* handle) { void* loader=_ZN16BackgroundLoader11GetInstanceEv(); _ZN16BackgroundLoader10RemoveTaskEi(loader,*handle); *handle=-1; }
