#include <globaldefs.h>
struct Object {char pad[0x44];char context[1];};
extern "C" unsigned Vector3fix_ComputeReverseXZHeading(unsigned,void*);
extern "C" void SetObjectAngleAndClearFlagC48000(Object*,unsigned);
// Original: arm9/main @ 0x020338B0; symbol: func_020338b0; size: 0x24.
extern "C" void GameObject_FacePosition(Object* p,unsigned value) {unsigned result=Vector3fix_ComputeReverseXZHeading(value,p->context);SetObjectAngleAndClearFlagC48000(p,result);}
