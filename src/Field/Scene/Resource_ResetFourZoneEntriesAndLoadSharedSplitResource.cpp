#include <globaldefs.h>
ARM
#pragma opt_propagation off
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[],Resource_ResetFourZoneEntriesAndLoadSharedSplitResource_PathDataPrmMonModdataNat[],Main_UnknownRoleZeroInitializedStorage_Variant6[];extern "C" void* _ZN9GameState11GetInstanceEv(),*Zone3D_GetMainInstance(),*ZoneState_GetTrackedZoneCache(),*GetBoundedEntryAtStride318(void*,int),*_ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void ZoneState_ResetTrackedZone(void*),_ZN13SafeAllocator7DestroyEv(void*),Memory_FreeThroughAllocatorUnion(void*,void*),GameState_ClearObjectByIndex(void*,unsigned);extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void* MonsterOverrideTable_Reset(void*);extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(),_ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" void MonsterOverrideTable_Load(void*,void*,const unsigned char*);
// Original: arm9/ov017 @ 0x0219fda0; symbol: Resource_ResetFourZoneEntriesAndLoadSharedSplitResource; size 0x120.
extern "C" void Resource_ResetFourZoneEntriesAndLoadSharedSplitResource(){void* game=_ZN9GameState11GetInstanceEv();Zone3D_GetMainInstance();void* table=ZoneState_GetTrackedZoneCache();for(int i=0;i<4;i++){void* row=GetBoundedEntryAtStride318(table,i);ZoneState_ResetTrackedZone(row);void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(P(row,16));if(allocation){_ZN13SafeAllocator7DestroyEv(P(row,16));Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}}for(int i=112;i<=159;i++)GameState_ClearObjectByIndex(game,i);char* entry=(char*)GetBoundedEntryAtStride318(table,0);unsigned blockSize=0xa000;H(entry,2)|=4;H(entry,0)=3;void* block=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,blockSize);_ZN13SafeAllocator11CreateTypeAEPvj(P(entry,16),block,blockSize);if(entry){MonsterOverrideTable_Reset(entry+0x30c);_ZN16BackgroundLoader13AddLockGlobalEv();unsigned size;if(_Z18LoadFileIntoMemoryPKcPvPj(Resource_ResetFourZoneEntriesAndLoadSharedSplitResource_PathDataPrmMonModdataNat,Main_UnknownRoleZeroInitializedStorage_Variant6,&size))((void(*)(void*,void*,const unsigned char*,unsigned))MonsterOverrideTable_Load)(entry+0x30c,P(entry,16),(unsigned char*)Main_UnknownRoleZeroInitializedStorage_Variant6,size);_ZN16BackgroundLoader16RemoveLockGlobalEv();}}
