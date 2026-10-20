#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Object{unsigned char pad[14];unsigned char type;}; extern "C" void* Object_GetGlobalSixteenEntryDisplayState(); extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);
// Original: arm9/main @ 0x020DABD0; symbol: func_020dabd0; size: 0x70.
extern "C" int ActorEffectLoader_RemoveCurrentResources(Object*o){void*p=Object_GetGlobalSixteenEntryDisplayState();switch(o->type){case 1:RemoveMatchingNodeAndResetMatchingObjectSlots(p,20);RemoveMatchingNodeAndResetMatchingObjectSlots(p,21);break;case 2:RemoveMatchingNodeAndResetMatchingObjectSlots(p,20);RemoveMatchingNodeAndResetMatchingObjectSlots(p,21);break;case 3:RemoveMatchingNodeAndResetMatchingObjectSlots(p,22);break;}return 1;}
