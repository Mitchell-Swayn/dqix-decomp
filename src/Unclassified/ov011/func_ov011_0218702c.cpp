#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
struct Item { char header[0x42]; unsigned short field42; unsigned char field44; unsigned char reserved:1; unsigned char value:6; unsigned char enabled:1; };
// Original: arm9/ov011 @ 0x0218702C; symbol: func_ov011_0218702c; size: 0x78.
extern "C" unsigned func_ov011_0218702c(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned value=func_ov011_02184c30((char*)self+8);
 unsigned last=func_ov011_02184c30((char*)self+16);
 Item* item=(Item*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id);
 if(!item) return 0;
 if(OV023_ReadHalfwordField04(item)!=8) return 0;
 item->value=(unsigned char)value;
 item->field42=last;
 return 1;
}
