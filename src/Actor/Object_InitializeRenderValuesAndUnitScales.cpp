#include <globaldefs.h>
struct State
{
    unsigned char first,pad[15],enabled;
    unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;
    short unused,v1,v2,v3,v4,palette,pad2;
    unsigned values[12];
};
// Original: arm9/main @ 0x02078484; symbol: func_02078484; size: 0xB8.
extern "C" ARM void Object_InitializeRenderValuesAndUnitScales(State* p)
{
    p->first=0;
    p->enabled=1;
    p->unused=0;
    p->v1=-1;
    p->v2=-1;
    p->v3=-1;
    p->v4=-1;
    p->palette=-0x1000;
    p->values[0]=0;
    p->values[1]=0;
    p->values[2]=0;
    p->values[3]=0;
    p->values[4]=0;
    p->values[5]=0;
    p->values[6]=0;
    p->values[7]=0;
    p->values[8]=0;
    p->values[9]=0x1000;
    p->values[10]=0x1000;
    p->values[11]=0x1000;
    p->a=0;
    p->b=0;
    p->c=1;
    p->d=0;
    p->e=0;
    p->f=0;
    p->g=0;
    p->h=0;
}
