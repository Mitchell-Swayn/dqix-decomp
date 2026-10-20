#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void TextLayout_ComputeLinkedMenuDimensions(void*);struct Owner{unsigned char pad[108],state,gap[4],a,gap72,b,c,gap75[3];void(*callback)(Owner*);};
// Original: arm9/main @ 0x0202A8CC; symbol: func_0202a8cc; size: 0x50.
extern "C" ARM void DebugMenu_BeginOpen(Owner* owner,int notify){if(!owner->state)return;owner->state=2;TextLayout_ComputeLinkedMenuDimensions(owner);owner->a=0;owner->b=0;owner->c=0;if(notify&&owner->callback)owner->callback(owner);}
