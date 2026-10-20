#include <globaldefs.h>
ARM
struct Items {short* ids;signed char* flags;short count;};
// Original: arm9/main @ 0x020A0A60; symbol: func_020a0a60; size: 0x94.
extern "C" void Inventory_CompactOccupiedSlotsFromIndex(Items* p,int position) {short* ids=p->ids;signed char* flags=p->flags;int count=p->count;for(;position<count-1;position=(short)(position+1)) {if(flags[position]==0) {for(short i=(short)(position+1);i<count;i=(short)(i+1)) {if(flags[i]) {ids[position]=ids[i];flags[position]=flags[i];ids[i]=-1;flags[i]=0;break;} } } } }
