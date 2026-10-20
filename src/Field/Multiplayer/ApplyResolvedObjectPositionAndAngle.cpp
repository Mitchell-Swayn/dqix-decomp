#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct Resolved {int a,b;char* object;};
extern "C" {int Field_ResolveSynchronizedMonster(void*,void*,int);void* Zone3D_GetMainInstance();int Zone3D_FindGroundHeightBelowPosition(void*,const Vec*);void* _ZN8Vector3iaSERKS_(void*,const void*);void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);bool Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);}
// Original: arm9/ov017 @ 0x021C949C; symbol: func_ov017_021c949c; size: 0xA8.
extern "C" void ApplyResolvedObjectPositionAndAngle(void* unused,char* message){
Resolved resolved;Vec position;
if(Field_ResolveSynchronizedMonster(message+4,&resolved,-1)){
position.x=*(int*)(message+12);position.y=*(short*)(message+10)<<4;position.z=*(int*)(message+16);
int angle=*(short*)(message+8);
char* zone=(char*)Zone3D_GetMainInstance();
if(*(unsigned short*)(message+4)==*(unsigned short*)zone && *(int*)(zone+0x424)==0)position.y=Zone3D_FindGroundHeightBelowPosition(zone,&position);
_ZN8Vector3iaSERKS_(resolved.object+0x44,&position);
Object3D_SetNormalizedAngleAndUpdatePosition(resolved.object,angle);
if(*(int*)(resolved.object+0x130)!=9)Object_InvokeStateMethodAndRecordSuccessfulTransition(resolved.object,1);
}
}
