#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Object;struct Output {int index;void* record;unsigned char* monster;};
extern "C" int Field_ResolveSynchronizedMonster(void*,Output*,int);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
extern "C" bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object*,int);
// Original: arm9/ov017 @ 0x021C91F4; symbol: func_ov017_021c91f4; size: 0x88.
extern "C" void GameState_ApplyResolvedMonsterPositionAndTransition(void*,unsigned char* source){
 Output out;Vector3fix position;
 if(Field_ResolveSynchronizedMonster(source+4,&out,-1) && *(int*)(out.monster+0x130)!=9){
 position.x=*(int*)(source+0xc);
 position.z=*(int*)(source+0x10);
 int angle=*(short*)(source+0xa);
 unsigned short value=*(unsigned short*)(source+8);
 position.y=*(int*)(out.monster+0x48);
 *(Vector3fix*)(out.monster+0x44)=position;
 Object3D_SetNormalizedAngleAndUpdatePosition((char*)out.monster,angle);
 *(unsigned short*)(out.monster+0x164)=value;
 Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)out.monster,2);
 }
}
