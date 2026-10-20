#include <globaldefs.h>
struct ResourceTag{signed char index;unsigned char flags,first,second;};extern "C" void LinkedQueue_InitializeNodeStatus(ResourceTag*);
#pragma dont_inline on
// Original: arm9/ov030 @ 0x021D92C8; symbol: func_ov030_021d92c8; size: 0x14.
extern "C" ARM ResourceTag* GameResources_ConstructActorLevelChangeNode(ResourceTag* p){LinkedQueue_InitializeNodeStatus(p);return p;}
