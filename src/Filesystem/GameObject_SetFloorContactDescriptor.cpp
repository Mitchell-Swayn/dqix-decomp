#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void GameObject_CopyContactDescriptor(void*,const unsigned short*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x02033F6C; symbol: func_02033f6c; size: 0x10.
extern "C" void GameObject_SetFloorContactDescriptor(char* a,const unsigned short* b){GameObject_CopyContactDescriptor(a+276,b);}
