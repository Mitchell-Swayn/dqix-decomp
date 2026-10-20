#include <globaldefs.h>
ARM
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
struct Vec {int x,y,z;};
extern "C" void Field_QueueMonsterPositionEffectState(unsigned,int,int,int,int,Vec,int,int,int);
// Original: arm9/main @ 0x020794F8; symbol: SubmitObjectPositionForRemainderIndex; size: 0x94.
// Submits identifier, position and rotation with the nonnegative remainder of field4 minus112 modulo12.
extern "C" void Object3D_SubmitPositionForRemainderIndex(char* object,int a,int b){
 unsigned id=_ZNK8Object3D10GetField06Ev(object);
 int field4=*(volatile short*)(object+4);int field2=*(short*)(object+2);
 Vec pos=*(Vec*)(object+0x44);
 int index=field4-0x70;int angle=*(short*)(object+0xae);index=index%12;
 if(index>=0&&index<12)Field_QueueMonsterPositionEffectState(id,index,field2,1,-1,pos,angle,a,b);
}
