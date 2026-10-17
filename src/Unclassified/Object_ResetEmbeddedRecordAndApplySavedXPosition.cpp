#include <globaldefs.h>
#include <System/Matrix.h>
#include <Resource/Script.h>
#include <Memory/AllocatorUnion.h>
ARM
extern "C"{void Object_Clear40Bytes(void*);void Object_SetVectorComponentsThroughPositionSetter(void*,const Vector3fix*);void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);extern char* data_02109924;extern AllocatorUnion data_02114e20;}
#pragma force_active on
// Original: arm9/main @ 0x020A2744; symbol: func_020a2744; size: 0x2C.
extern "C" void Object_ResetEmbeddedRecordAndApplySavedXPosition(char* p){Object_Clear40Bytes(p+584);int value=*(short*)(p+542);*(int*)(p+544)=value;Object_SetVectorComponentsThroughPositionSetter(p,(Vector3fix*)(p+544));}
