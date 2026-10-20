#pragma dont_inline on
#include "CartridgeService.h"
extern int ARM7_CheckCartridgeRemoval(void);
// Original: arm7/wram @ 0x03807390; symbol: ARM7_IsCartridgeRemoved.
int ARM7_IsCartridgeRemoved(void)
{
 {
  register SharedCartridgeMetadata *metadata=&ARM7_SharedCartridgeMetadata;
  if(metadata->id==0xffff)return 0;
  if(!metadata->flags.removed)ARM7_CheckCartridgeRemoval();
 }
 return ARM7_SharedCartridgeMetadata.flags.removed;
}
