#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
extern "C" void Object3D_CopyPosition(char*,int*);
// Original: arm9/ov025 @ 0x021EEB8C; symbol: func_ov025_021eeb8c; size: 0x118.
extern "C" ARM int Combat_InterpolateCommandObjectPosition(unsigned char*self){int step;GameState*state=GameState::GetInstance();unsigned delta=state->GetEffectiveDeltaTime();GameObject*object=state->GetGameObjectByIndex(H(self,8));if(!object)return 1;if(H(self,10)<=delta){Object3D_CopyPosition((char*)object,(int*)(self+12));return 1;}Vector3i current=*(Vector3i*)((unsigned char*)object+0x44);int distance=Vector3fix_Distance(&current,(Vector3i*)(self+12));step=FIX32_MULTIPLY(distance,(int)(4096.0f*((float)delta/(float)(unsigned)H(self,10))));Vector3i difference;Vector3fix_Subtract((Vector3i*)(self+12),&current,&difference);Vector3fixMultiplyScalar(&difference,fix32_Divide(step,distance),&difference);Vector3fix_Add(&current,&difference,&current);Object3D_CopyPosition((char*)object,(int*)&current);H(self,10)-=delta;return 0;}