#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{short pad;unsigned char a;signed char b;unsigned int x:3,y:3,z:3,w:3,v:3;};
// Original: arm9/main @ 0x020795E8; symbol: func_020795e8; size: 0x64.
void FieldMonster_ApplyPackedBehaviorParameters(char *p,A *q){p[0x138]=q->x;p[0x139]=q->y;p[0x13a]=q->z;p[0x13b]=q->w;p[0x13c]=q->v;*(unsigned int *)(p+0x140)=q->a;*(int *)(p+0x144)=q->b;}
}
