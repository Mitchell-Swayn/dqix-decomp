#include "globaldefs.h"
#pragma optimize_for_size off
ARM
union Vec{struct{int x,y,z;};int v[3];};struct Object{unsigned char pad[0x44];Vec position;unsigned char pad2[0xf0];int height;};extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" Vec* _ZN8Vector3iaSERKS_(Vec*,const Vec*);extern "C" void Object3D_DrawWithTemporaryHeightAndCameraDisplacement(Object*,int,int);
// Original: arm9/main @ 0x020A7EB8; symbol: func_020a7eb8; size: 0x7C.
extern "C" void FieldVisualActor_DrawWithHeightOffset(Object*p){_ZN9GameState11GetInstanceEv();Vec temp=p->position;temp.y+=p->height;_ZN8Vector3iaSERKS_(&p->position,&temp);Object3D_DrawWithTemporaryHeightAndCameraDisplacement(p,1,0);_ZN8Vector3iaSERKS_(&temp,&p->position);temp.y-=p->height;_ZN8Vector3iaSERKS_(&p->position,&temp);}
