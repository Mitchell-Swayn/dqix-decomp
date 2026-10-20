#include <globaldefs.h>
ARM
struct Values { int x,y; float z; unsigned short w,pad; };
struct ValueTable { Values entries[3]; };
// Original data: arm9/main @ 0x20e8d0c; symbol: data_020e8d0c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 80000000600000006666a63f0000000080000000600000000000803f00000000d3000000210000000000803fa8160000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const ValueTable MathInterpolateAdjacentTableValues_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x0208B788; symbol: func_0208b788; size: 0x13C.
extern "C" void Math_InterpolateAdjacentTableValues(int index,float t,Values* out,int alternate) {
 ValueTable table=MathInterpolateAdjacentTableValues_UnknownRoleInitializedBytes;
 if(alternate) table.entries[0].z=1.2f;
 Values* a=&table.entries[index];
 Values* b=&table.entries[index+1];
 out->x=(int)((float)a->x+t*(float)(b->x-a->x));
 out->y=(int)((float)a->y+t*(float)(b->y-a->y));
 out->z=a->z+t*(b->z-a->z);
 out->w=(unsigned)((float)a->w+t*(float)(b->w-a->w));
}
