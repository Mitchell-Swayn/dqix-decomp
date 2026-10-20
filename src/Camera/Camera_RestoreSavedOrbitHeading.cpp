#include <globaldefs.h>
#include <System/Matrix.h>
#include <Resource/Script.h>
#include <Memory/AllocatorUnion.h>
ARM
// Original data: arm9/main @ 0x2109924; symbol: data_02109924.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C"{void Camera_ResetInterpolationRecord(void*);void Camera_SetOrbitParameters(void*,const Vector3fix*);void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);extern char* ScriptAllocateZoneTableEntries_UnknownRoleZeroInitializedStorage;extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;}
#pragma force_active on
// Original: arm9/main @ 0x020A2744; symbol: func_020a2744; size: 0x2C.
extern "C" void Camera_RestoreSavedOrbitHeading(char* p){Camera_ResetInterpolationRecord(p+584);int value=*(short*)(p+542);*(int*)(p+544)=value;Camera_SetOrbitParameters(p,(Vector3fix*)(p+544));}
