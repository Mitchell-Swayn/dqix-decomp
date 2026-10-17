#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
struct Item { char prefix[0x45]; unsigned char reserved:7; unsigned char enabled:1; };
// Original: arm9/ov011 @ 0x02188884; symbol: func_ov011_02188884; size: 0x68.
extern "C" unsigned func_ov011_02188884(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned value=func_ov011_02184c30((char*)self+8);
 Item* item=(Item*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id);
 if(!item) return 0;
 if(OV023_ReadHalfwordField04(item)!=8) return 0;
 item->enabled=(unsigned char)value;
 return 1;
}
