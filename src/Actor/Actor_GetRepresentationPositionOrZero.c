#include <globaldefs.h>
typedef struct Vec {int x,y,z;} Vec;
typedef struct Small {int a;Vec v;} Small;
typedef struct Large {int a[17];Vec v;} Large;
typedef struct Object {int pad[5];Small* a;Large*b;Large*c;} Object;
// Original: arm9/main @ 0x020406F8; symbol: func_020406f8; size: 0x7C.
ARM void Actor_GetRepresentationPositionOrZero(Vec* out,Object* p){
 if(p->a){*out=p->a->v;}else if(p->b){*out=p->b->v;}else if(p->c){*out=p->c->v;}else{Vec zero;zero.x=0;zero.y=0;zero.z=0;*out=zero;}
}
