#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
class Vector3i {public:int x,y,z;Vector3i& operator=(const Vector3i&);};
extern "C" {
void Camera_DisableParentTransform(void*);void Camera_SetRollAndStopTransition(void*,int);void Camera_SetProjectionAngle(void*,int);void Camera_StopTargetRotation(void*);void Camera_ClearYawTransition(void*);void Camera_StopEyeMovement(void*);void Camera_StopTargetMovement(void*);void Camera_StopOrbitMovement(void*);void* memset(void*,int,unsigned);
}
// Original: arm9/ov000 @ 0x0216D370; symbol: func_ov000_0216d370; size: 0xf4.
// Restores saved camera vectors and stops shot, parent and movement transitions.
extern "C" void BattleCamera_ResetShotAndTransitions(unsigned char* camera,int roll,int projection,int yaw) {
 camera[0x220]=0;
 if(*(int*)(camera+0x224)>=0) {
  Vec target=*(Vec*)(camera+0x12c);
  Vec eye=*(Vec*)(camera+0x120);
  *(Vector3i*)(camera+0x10)=*(Vector3i*)&target;
  *(Vector3i*)(camera+4)=*(Vector3i*)&eye;
 }
 *(int*)(camera+0x224)=-1;
 *(int*)(camera+0x238)=0;
 *(int*)(camera+0x23c)=0;
 Camera_DisableParentTransform(camera);
 camera[0x260]=0;
 if(roll) Camera_SetRollAndStopTransition(camera,0);
 if(projection) Camera_SetProjectionAngle(camera,0xf000);
 if(yaw){Camera_StopTargetRotation(camera);Camera_ClearYawTransition(camera);}
 memset(camera+0x264,0,0x14);
 Camera_StopEyeMovement(camera);Camera_StopTargetMovement(camera);Camera_StopOrbitMovement(camera);
}
