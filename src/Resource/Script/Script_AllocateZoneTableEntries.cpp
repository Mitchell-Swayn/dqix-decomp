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
// Original: arm9/main @ 0x020995C0; symbol: func_020995c0; size: 0x38.
extern "C" int Script_AllocateZoneTableEntries(const Script::Parameter* param){int count=param->ToInt();char* p=ScriptAllocateZoneTableEntries_UnknownRoleZeroInitializedStorage;*(void**)p=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,count*16);*(int*)(p+8)=count;return 1;}
