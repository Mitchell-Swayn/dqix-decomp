#include <globaldefs.h>
ARM
struct RatioObject { signed char kind:6; unsigned char flags:2; char pad[0x153]; unsigned int unused:10; unsigned int current:10; unsigned int rest:12; unsigned int maximum:10; unsigned int rest2:22; };
// Original: arm9/ov003 @ 0x0215F56C; symbol: func_ov003_0215f56c; size: 0x7C.
extern "C" int SelectPackedRatioLevel(RatioObject* p) {
 int result=15;
 if(p && p->kind>=0) {
 float ratio=(float)p->current/(float)p->maximum;
 if(ratio<=0.25f) result=13;
 if(ratio<=0.08f) result=11;
 }
 return result;
}
