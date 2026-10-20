#include "Filesystem/BackgroundLoader.h"
struct GameState{static GameState* GetInstance();};struct LightingManager{static LightingManager* GetInstance();};
extern "C" {
struct Bits{unsigned char a:1,b:1,c:1,d:1,top:4;};
struct Owner {unsigned words[3];unsigned char archive[0x10];unsigned char table[0x20];SafeAllocator* allocators;void* object;unsigned word;void* current;void* previous;unsigned* descriptor;unsigned* previousDescriptor;void* fields[5];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags;Bits bits;unsigned char gap[3];short tasks[5];unsigned char gap2[8];void* pointer;unsigned char list[0x10];};
// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern unsigned BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[];void BestiaryInfo_InitializeSelection(void*);void BestiaryInfo_ResetSelection(void*);void BestiaryHabitat_InitializeLoader(void*);void BestiaryHabitat_CancelLoad(void*);void BestiaryDetail_ResetMonsterStatSummary(void*);void func_02001aac(void*,int,unsigned);void GameState_SetUnknown3b0(GameState*,unsigned);int func_020328b4(void*);void func_02032730(void*);
// Original: arm9/ov014 @ 0x021845EC; symbol: func_ov014_021845ec; size: 0x114.
void BestiaryDetail_ReleaseResources(Owner* p){if(p->task>=0){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(p->task);p->task=-1;}if(p->load>=0){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(p->load);p->load=-1;}for(int i=0;i<5;i++){short task=p->tasks[i];if(task>=0){BackgroundLoader::GetInstance()->RemoveTask(task);p->tasks[i]=-1;}}BestiaryHabitat_CancelLoad(p->table);BestiaryInfo_ResetSelection(p->archive);BestiaryHabitat_InitializeLoader(p->table);GameState_SetUnknown3b0(GameState::GetInstance(),BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[3]);BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[3]=0;((unsigned char*)LightingManager::GetInstance())[0x85]=1;if(p->allocators){for(int i=0;i<6;i++){SafeAllocator* item=p->allocators+i;if(item->GetSignedAllocator())p->allocators[i].Destroy();}}}
}
