#include <globaldefs.h>
ARM
struct Stats {unsigned pad:10,a:10,b:10,rest:2;};
struct Bounds {unsigned pad:12,lo:10,hi:10;};
struct Values {unsigned pad:7,lo:7,hi:7,rest:11;};
struct Mode {unsigned pad:16,mode:2,rest:14;};
struct Record {unsigned first;Bounds bounds;char pad[8];unsigned flags;Values values;Mode mode;};
struct Linked {char pad[16];Stats stats;};
struct Object {char pad[0x138];Linked* linked;};
// Original: arm9/ov024 @ 0x021F8BD8; symbol: func_ov024_021f8bd8; size: 0x1A8.
extern "C" void Combat_ComputeClampedStatPercentage(void* unused,float* output,Object* object,Record* record) {
 unsigned short a=object->linked->stats.a;
 unsigned short b=object->linked->stats.b;
 float result=100.0f;
 if(record->mode.mode==1) {
 if(record->flags&0x4000) {
 if(a<=record->bounds.lo)result=(float)record->values.lo;
 else if(a>=record->bounds.hi)result=(float)record->values.hi;
 else {
 unsigned low=record->values.lo;
 float distance=(float)(a-record->bounds.lo);
 result=(float)((int)(distance*((float)(record->values.hi-low)/(float)(record->bounds.hi-record->bounds.lo)))+low);
 }
 } else if(record->flags&0x8000) {
 if(b<=record->bounds.lo)result=(float)record->values.lo;
 else if(b>=record->bounds.hi)result=(float)record->values.hi;
 else {
 unsigned low=record->values.lo;
 float distance=(float)(b-record->bounds.lo);
 result=(float)((int)(distance*((float)(record->values.hi-low)/(float)(record->bounds.hi-record->bounds.lo)))+low);
 }
 }
 }
 *output=result;
}
