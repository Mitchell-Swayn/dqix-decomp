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
// Original data: arm9/main @ 0x20fdd44; symbol: data_020fdd44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210783c; symbol: data_0210783c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111804; symbol: data_02111804.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2112754; symbol: data_02112754.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void ComputeRotatedEndpointFromAngleHeightAndLength(void*,int,int,int);void* MonsterBattleData_BinarySearchWithIdCallback(void*,int,int(*)(void*));int MonsterBattleData_GetRecordId(void*);void WindowFrame_LoadArchivePartsWithReusableAllocator(void*);int Graphics_DecodeSignedBrightness(volatile unsigned short*);void* SafeAllocator_ResetAndReturnPointer(void*);void LinkedList_PushFrontUsingWordTwoLink(void*,void*);void* ZoneState_FindTrackedZoneByIdentifier(void*,int);extern char ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage[],TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage[],PowerManagementPrependSleepCallback_UnknownRoleZeroInitializedStorage[],ZoneStateGetTrackedZoneCache_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/main @ 0x020D220C; symbol: func_020d220c; size: 0x14.
extern "C" void SoundCommand_UnlockMutex(){UnlockMutex((Mutex*)ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage);}
