// Exact relocation targets; SDK/header contracts and original callee return/argument behavior reviewed.
#include <globaldefs.h>
#include <Memory/HPXEAllocator.h>
#include <World/Object3D.h>
#include <System/Mutex.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
struct Triple{int x,y,z;};
extern "C" {void ComputeRotatedEndpointFromAngleHeightAndLength(void*,int,int,int);void* Object_BinarySearch132ByteRecordsByCallback(void*,int,int(*)(void*));int ReadHalfword0Low15Bits(void*);void Object_LoadNarcIntoReusableSafeAllocator(void*);int Graphics_DecodeSignedBrightness(volatile unsigned short*);void* SafeAllocator_ResetAndReturnPointer(void*);void LinkedList_PushFrontUsingWordTwoLink(void*,void*);void* FindRecordAmongFourByNonnegativeKey(void*,int);extern char data_02112754[],data_0210783c[],data_02111804[],data_020fdd44[];}
// Original: arm9/main @ 0x0202E694; symbol: func_0202e694; size: 0x14.
extern "C" void Object_SetVectorComponentsThroughPositionSetter(void* p,const Triple* v){ComputeRotatedEndpointFromAngleHeightAndLength(p,v->x,v->y,v->z);}
