#include <globaldefs.h>
ARM
extern "C" void Camera_ApplyManualInput(void*);
extern "C" int Camera_GetManualControlMode(void*);
extern "C" void BattleCamera_UpdateNearbyCombatantAlpha(void*);
extern "C" void BattleCamera_UpdateActionPairTracking(void*);
extern "C" void BattleCamera_UpdateOrbitInterpolation(void*);
extern "C" int Camera_GetOrbitHeading(void*);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void Camera_SetOrbitHeading(void*,int);
extern "C" int Camera_GetOrbitDistance(void*);
extern "C" void Camera_SetClampedOrbitDistance(void*,int);
extern "C" void BattleCamera_ClampEyeToArenaBounds(void*);
// Original: arm9/ov000 @ 0x0216D464; symbol: Camera_UpdateManualRotationAndClampedDistance; size: 0xa8.
extern "C" void Camera_UpdateManualRotationAndClampedDistance(char* self) {
 Camera_ApplyManualInput(self);if(Camera_GetManualControlMode(self)){BattleCamera_UpdateNearbyCombatantAlpha(self);return;}
 BattleCamera_UpdateActionPairTracking(self);BattleCamera_UpdateOrbitInterpolation(self);
 if(*(int*)(self+0x238)){int angle=Camera_GetOrbitHeading(self);angle+=*(int*)(self+0x238);Camera_SetOrbitHeading(self,_Z22fix32ReduceAngle0To2Pii(angle));}
 if(*(int*)(self+0x23c)){int distance=Camera_GetOrbitDistance(self);int delta=*(int*)(self+0x23c);int next=delta<distance?distance+delta:0;if(next<0x3000)next=0x3000;Camera_SetClampedOrbitDistance(self,next);}
 BattleCamera_ClampEyeToArenaBounds(self);BattleCamera_UpdateNearbyCombatantAlpha(self);
}
