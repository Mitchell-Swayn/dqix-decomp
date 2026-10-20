#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
struct Flags { unsigned char low:4; unsigned char high:4; };
// Original: arm9/main @ 0x020941B0; symbol: func_020941b0; size: 0x48.
extern "C" ARM void BackgroundLoader_CancelTaskAndSetCleanupModeFlags(char* self) {
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 if (*(int*)(self+0x340)>=0) {loader->RemoveTask(*(int*)(self+0x340));*(int*)(self+0x340)=-1;}
 ((unsigned char*)self)[0x3c8]&=~0x7f;
 ((unsigned char*)self)[0x3cd]&=~15;
 ((unsigned char*)self)[0x3cd]|=8;
}
