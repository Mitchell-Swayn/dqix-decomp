#include <globaldefs.h>
#include <Graphics/Vector.h>
// Original: arm9/main @ 0x020322C0; symbol: func_020322c0; size: 0x6C.
extern "C" ARM int Object_ComputeHeadingDotProduct(char *p,const int *angle){Vector3fix a=*(Vector3fix*)(p+0x24);Vector3fix_Normalize(&a,&a);int c=fix32cos(*angle);Vector3fix b; b.x=fix32sin(*angle);b.y=0;b.z=c;Vector3fix_Normalize(&b,&b);return Vector3fix_InnerProduct(&b,&a);}
