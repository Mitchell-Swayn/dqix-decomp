#include <globaldefs.h>
struct ResourceTag{signed char index;unsigned char flags,first,second;};extern "C" void LinkedQueue_InitializeNodeStatus(ResourceTag*);
#pragma dont_inline on
// Original: arm9/ov030 @ 0x021D9264; symbol: func_ov030_021d9264; size: 0x14.
extern "C" ARM ResourceTag* GameResources_DestructEquipmentRefreshNode(ResourceTag* p){LinkedQueue_InitializeNodeStatus(p);return p;}
