#include <globaldefs.h>
ARM
struct Values { int x,y; float z; unsigned short w,pad; };
struct ValueTable { Values entries[3]; };
extern "C" const ValueTable data_020e8d0c;
// Original: arm9/main @ 0x0208B788; symbol: func_0208b788; size: 0x13C.
extern "C" void Math_InterpolateAdjacentTableValues(int index,float t,Values* out,int alternate) {
 ValueTable table=data_020e8d0c;
 if(alternate) table.entries[0].z=1.2f;
 Values* a=&table.entries[index];
 Values* b=&table.entries[index+1];
 out->x=(int)((float)a->x+t*(float)(b->x-a->x));
 out->y=(int)((float)a->y+t*(float)(b->y-a->y));
 out->z=a->z+t*(b->z-a->z);
 out->w=(unsigned)((float)a->w+t*(float)(b->w-a->w));
}
