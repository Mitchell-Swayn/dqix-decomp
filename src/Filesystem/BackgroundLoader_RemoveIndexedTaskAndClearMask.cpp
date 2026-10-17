#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
struct Tasks { char pad[8]; unsigned short mask,pad2; int ids[1]; };
// Original: arm9/main @ 0x020DA034; symbol: func_020da034; size: 0x40.
extern "C" void BackgroundLoader_RemoveIndexedTaskAndClearMask(Tasks* self,unsigned index) { BackgroundLoader::GetInstance()->RemoveTask(self->ids[index]); self->ids[index]=-1; self->mask &= ~(1u<<index); }
