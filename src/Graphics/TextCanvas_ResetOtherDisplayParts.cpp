#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(void*);struct Owner{char pad[48];char* items;char gap[5];unsigned char count;};
// Original: arm9/main @ 0x0207FDF0; symbol: func_0207fdf0; size: 0x54.
extern "C" ARM void TextCanvas_ResetOtherDisplayParts(Owner* owner,unsigned index){if(!owner->items)return;unsigned char count=owner->count;for(unsigned char i=0;i<count;++i){char* item=owner->items+i*224;if(index!=(unsigned char)item[196])TextCanvas_ResetLayoutAndDisplayFlags(item);}}
