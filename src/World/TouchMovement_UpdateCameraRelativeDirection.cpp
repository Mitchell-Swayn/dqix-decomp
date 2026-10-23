#include <globaldefs.h>
#include <Graphics/Vector.h>
#include <Graphics/NSBXX/RenderConfig.h>
#define ROUND_FIXED(v) (int)((v)>0.0f ? (0.5f+4096.0f*(v)) : (4096.0f*(v)-0.5f))
// Original: arm9/main @ 0x02096a20; symbol: TouchMovement_UpdateCameraRelativeDirection; size: 0x218.
extern "C" ARM void TouchMovement_UpdateCameraRelativeDirection(unsigned char* self) {
Vector3fix direction={0,0,0};
{ unsigned from,to; to=self[0x222];from=self[0x220]; direction.x=ROUND_FIXED((float)to-(float)from); }
{ unsigned from,to; to=self[0x223];from=self[0x221]; direction.z=ROUND_FIXED((float)to-(float)from); }
Vector3fix_Normalize(&direction,&direction);
const Matrix4x3* view=&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix;
Vector3fix camera={0,0,0}; camera.x=view->entries[6];camera.z=view->entries[8];Vector3fix_Normalize(&camera,&camera);
short touchAngle=fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x,direction.z));
short cameraAngle=fix32ReduceAngle0To2Pi(-fix32_Atan2(camera.x,camera.z));
*(short*)(self+0x22e)=fix32ReduceAngle0To2Pi(touchAngle+cameraAngle);
*(short*)(self+0x228)=fix32sin(*(short*)(self+0x22e)); *(short*)(self+0x22a)=0; *(short*)(self+0x22c)=fix32cos(*(short*)(self+0x22e));
}
