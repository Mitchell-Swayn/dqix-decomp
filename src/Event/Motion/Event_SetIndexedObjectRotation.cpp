#include <globaldefs.h>
ARM
extern "C" int Object3D_SetRotationComponents(...);
extern "C" int Actor_SetRepresentationCurrentAndTargetYaw(...);
extern "C" int Actor_SetRepresentationRotationAndTargetYaw(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x02164320; symbol: SetIndexedObjectCoordinatesByRepresentationType.
extern "C" int Event_SetIndexedObjectRotation(char*table,int index,int x,int y,int z){
if(index<0||index>=32)return 0;char*entry=table+index*16;switch(W(entry,0)){case 4:case 5:if(!P(entry,12))return 0;Object3D_SetRotationComponents(P(entry,12),x,y,z);return 1;case 0:if(!P(entry,12))return 0;Object3D_SetRotationComponents(P(entry,12),x,y,z);return 1;case 1:if(!P(entry,12))return 0;Object3D_SetRotationComponents(P(entry,12),x,y,z);return 1;case 2:case 6:if(!P(entry,12))return 0;Actor_SetRepresentationRotationAndTargetYaw(P(entry,12),x,y,z);Actor_SetRepresentationCurrentAndTargetYaw(P(entry,12),y);return 1;default:return 0;}
}
