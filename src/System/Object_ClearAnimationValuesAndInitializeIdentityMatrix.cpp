#include <globaldefs.h>
ARM
#include <System/Matrix.h>
struct State {
 int unknown,a,b,gapC,values[6];char pad28[16];unsigned char flag;char pad39[3];short index;char pad3e[14];int transform[4];short bounds[4];int pos[3],angle[3],scale[3];short position[3],rotation[3],scaling[3];char pad9a[2];int value9c;short valuea0;char pada2[2];int p[3],q[3];short r[3],c2;char padc4[36];Matrix4x3 matrix;int values118[4],x[3],y[3],z[3];char pad14c[4];int value150;char pad154[4];int first[3],second[3];
};
// Original: arm9/main @ 0x02056B48; symbol: func_02056b48; size: 0xF4.
extern "C" void Object_ClearAnimationValuesAndInitializeIdentityMatrix(State* s){
 s->flag=0;s->a=0;s->b=0;s->values[0]=0;s->values[1]=0;s->values[2]=0;s->values[3]=0;s->values[4]=0;s->values[5]=0;s->index=0;
 s->transform[0]=0;s->transform[1]=0;s->transform[2]=0;s->transform[3]=0;
 s->values118[0]=0;s->values118[1]=0;s->values118[2]=0;s->values118[3]=0;
 s->bounds[0]=0;s->bounds[1]=0;s->bounds[2]=0;s->bounds[3]=0;s->value9c=0;s->valuea0=0;s->value150=0;
 for(int i=0;i<3;++i){s->x[i]=0;s->y[i]=0;s->z[i]=0;s->pos[i]=0;s->angle[i]=0;s->scale[i]=0;s->position[i]=0;s->rotation[i]=0;s->scaling[i]=0;}
 for(int i=0;i<3;++i){s->first[i]=0;s->second[i]=0;s->p[i]=0;s->q[i]=0;s->r[i]=0;}
 s->c2=0;MTX_Identity43_(&s->matrix);
}
