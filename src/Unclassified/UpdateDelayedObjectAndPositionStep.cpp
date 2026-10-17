#include <globaldefs.h>
ARM
#pragma block_assign on
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
extern unsigned char data_02108760[];struct Vec{int x,y,z;};extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int),CopyThreeWordsToVectorAt44(void*,void*),Object_ClearD4ByteDisplayEntryAndSetDefaults(void*),InvokePresentOwnerHandle(void*);extern "C" int TestNodeAndChildrenWithinLimits(unsigned);
// Original: arm9/main @ 0x0205A020; symbol: func_0205a020; size: 0x128.
extern "C" void UpdateDelayedObjectAndPositionStep(unsigned char* object,int delta){Vec position,step;GameState::GetInstance();if(*(short*)(object+0xb0)>0)*(short*)(object+0xb0)-=delta;else if(!*(int*)(object+0xac)){int value=*(int*)(object+0xb8);if(value>0&&*(int*)(object+0x28)<=*(int*)(object+0xbc)&&*(int*)(object+0xbc)<*(int*)(object+0x24))DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,value,0);position=*(Vec*)(object+0x44);Vector3fixMultiplyScalar((Vector3fix*)(object+0xc0),delta<<12,(Vector3fix*)&step);Vector3fix_Add((Vector3fix*)&position,(Vector3fix*)&step,(Vector3fix*)&position);CopyThreeWordsToVectorAt44(object,&position);((Object3D*)object)->AdvanceEffects();if((object[0x19]&1)&&((Object3D*)object)->HasAnimationStopped())Object_ClearD4ByteDisplayEntryAndSetDefaults(object);if(*(short*)(object+0xb6)>0){*(short*)(object+0xb6)-=delta;if(*(short*)(object+0xb6)<=0)Object_ClearD4ByteDisplayEntryAndSetDefaults(object);}}else if(TestNodeAndChildrenWithinLimits(*(unsigned*)(object+4))==1)Object_ClearD4ByteDisplayEntryAndSetDefaults(object);else InvokePresentOwnerHandle(object);}
