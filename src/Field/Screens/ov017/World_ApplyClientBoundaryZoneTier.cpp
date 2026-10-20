#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void* Zone3D_GetMainInstance();
extern "C" bool Network_IsClientSession(unsigned int*);
extern "C" void Field_MarkClientZoneRefreshPending(void*);
struct StateTail { char padding[0xb3c]; unsigned value; };
// Original: arm9/ov017 @ 0x021D3E7C; symbol: World_ApplyClientBoundaryZoneTier; size: 0x38.
// On an active state, copies source byte4 to the global word237c and activates the context.
extern "C" void World_ApplyClientBoundaryZoneTier(void*,const unsigned char* source,void*,void* context,unsigned* active) {
 if(!Network_IsClientSession(active))return;
 char* global=(char*)Zone3D_GetMainInstance();
 unsigned value=source[4];
 StateTail* tail=(StateTail*)(global+0x1840);
 tail->value=value;
 Field_MarkClientZoneRefreshPending(context);
}
