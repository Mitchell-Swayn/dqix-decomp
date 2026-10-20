#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
struct Vec{int x,y,z;};extern "C" void _ZNK8Object3D8GetScaleEv(Vec*,const void*);
// Original: arm9/ov001 @ 0x02164808; symbol: Graphics_ReadIndexedObjectScale; size: 0x100.
// Reads scale vector from supported indexed object kinds, preserving canonical explicit-output ABI through typed hidden-result cast.
extern "C" int Graphics_ReadIndexedObjectScale(unsigned char* entries,int index,Vec* output){if(index<0||index>=32)return 0;unsigned char* entry=entries+index*16;switch(W(entry,0)){case 0:case 1:case 4:case 5:{void* object=P(entry,12);if(!object)return 0;Vec scale=((Vec(*)(const void*))_ZNK8Object3D8GetScaleEv)(object);output->x=scale.x;output->y=scale.y;output->z=scale.z;return 1;}case 6:{unsigned char* holder=P(entry,12);if(!holder)return 0;void* object=P(holder,24);if(!object)return 0;Vec scale=((Vec(*)(const void*))_ZNK8Object3D8GetScaleEv)(object);output->x=scale.x;output->y=scale.y;output->z=scale.z;return 1;}default:return 0;}}
