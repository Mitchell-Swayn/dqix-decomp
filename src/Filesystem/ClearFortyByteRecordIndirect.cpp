#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void ActorSpriteResource_Reset(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0203FCD4; symbol: func_0203fcd4; size: 0xC.
extern "C" void ClearFortyByteRecordIndirect(void* a){ActorSpriteResource_Reset(a);}
