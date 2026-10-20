#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" int Event_ResolveCharacterArchiveMember(const char*,char*,char*);extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);extern "C" char Script_LoadEventTextTable_PathDataS[];
struct Pending {char pad[0x88];unsigned count;};
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x21658e0; symbol: data_ov001_021658e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 100 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" Pending EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;extern "C" int BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215EC94; symbol: QueueIndexedFileAndIncrementPendingCount; size: 0x98.
// Queues an indexed GP2 member or formatted file path and increments pending-count88.
extern "C" void QueueIndexedFileAndIncrementPendingCount(unsigned id,int index){void* loader=_ZN16BackgroundLoader11GetInstanceEv();char member[80];char archive[80];int task;if(Event_ResolveCharacterArchiveMember((const char*)id,member,archive)){task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,archive,member,0);BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[index]=task;}else {sprintf(member,Script_LoadEventTextTable_PathDataS,(const char*)id);task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,member,0);BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[index]=task;}EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage.count++;}
