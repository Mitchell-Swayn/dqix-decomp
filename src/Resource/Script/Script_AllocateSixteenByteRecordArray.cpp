#include <globaldefs.h>
#include <System/Matrix.h>
#include <Resource/Script.h>
#include <Memory/AllocatorUnion.h>
ARM
extern "C"{void Object_Clear40Bytes(void*);void Object_SetVectorComponentsThroughPositionSetter(void*,const Vector3fix*);void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);extern char* data_02109924;extern AllocatorUnion data_02114e20;}
#pragma force_active on
// Original: arm9/main @ 0x020995C0; symbol: func_020995c0; size: 0x38.
extern "C" int Script_AllocateSixteenByteRecordArray(const Script::Parameter* param){int count=param->ToInt();char* p=data_02109924;*(void**)p=AllocatorUnion_AllocateFourByteAligned(&data_02114e20,count*16);*(int*)(p+8)=count;return 1;}
