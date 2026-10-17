#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" void StoreValueWithLowByteClearedAndConditionalCarry(void*,int);
// Original: arm9/main @ 0x0203CE14; symbol: func_0203ce14; size: 0x90.
extern "C" void SetTargetPositionAndNormalizedDirection(unsigned char* object,const Vector3fix* target){int distance=Vector3fix_Distance(target,(Vector3fix*)(object+4));if(distance){*(Vector3fix*)(object+0x78)=*target;unsigned flags=*(unsigned*)(object+0x5c)|1;*(unsigned*)(object+0x5c)=flags;if(!(flags&4)){Vector3fix delta;Vector3fix_Subtract((Vector3fix*)(object+0x78),(Vector3fix*)(object+4),&delta);int scale=fix32_Divide(0x1000,distance);Vector3fixMultiplyScalar(&delta,scale,&delta);int angle=fix32_Atan2(delta.x,delta.z);StoreValueWithLowByteClearedAndConditionalCarry(object,angle);}}}
