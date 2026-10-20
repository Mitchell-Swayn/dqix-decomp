#include <globaldefs.h>
#include <System/Matrix.h>
extern "C" unsigned* ActorPool_GetActiveSlot(void*,int);extern "C" unsigned char* Actor_GetMotionDescriptor(void*);extern "C" void Actor_GetRepresentationPositionOrZero(Vector3fix*,void*);
// Original: arm9/main @ 0x0203E524; symbol: func_0203e524; size: 0xB4.
extern "C" ARM unsigned FindNearestActiveEntryAndWriteReducedPosition(void* p,const Vector3fix* pos,short* out){int best=0x400000;unsigned result=-1;for(int i=0;i<32;i++){unsigned* object=ActorPool_GetActiveSlot(p,i);if(object && !(*object&0x8000)){unsigned char* entry=Actor_GetMotionDescriptor(object);if(entry){int distance=Vector3fix_Distance(pos,(Vector3fix*)(entry+16));if(distance<best){result=*entry;best=distance;Vector3fix point;Actor_GetRepresentationPositionOrZero(&point,object);out[0]=point.x>>4;out[1]=point.y>>4;out[2]=point.z>>4;}}}}return result;}
