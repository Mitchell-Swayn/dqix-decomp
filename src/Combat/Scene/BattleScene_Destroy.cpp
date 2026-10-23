#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3D.h>
ARM
extern "C" {
void SoundSfx_RestoreCurrentHeapState(char*);
void GameState_CleanupOwnedResourcesAndResetRecords(unsigned char*);
void* ActionData_GetGlobalTables();
void ResourceIndex_ClearAlternateLookupTables(unsigned char*);
void* Object_GetGlobalSixteenEntryDisplayState();
void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
void Menu_DestroyQueuedRecordPanelResources(void*);
// Original data: arm9/main @ 0x02108760; symbol: data_02108760 (BSS).
extern char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov000 @ 0x02182FE0; symbol: data_ov000_02182fe0.
// Signed template keys terminated by a negative entry, read without mutation.
extern const int BattleSceneDestroy_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov000 @ 0x021604F0; symbol: func_ov000_021604f0; size: 0xe0.
// Restores the saved sound heap, releases scene resources and registered displays,
// and destroys each of the five initialized scene allocators.
extern "C" void BattleScene_Destroy(void* object)
{
    unsigned char* scene = (unsigned char*)object;
    if (scene[0x7711]) {
        SoundSfx_RestoreCurrentHeapState(Main_UnknownRoleZeroInitializedStorage);
        scene[0x7711] = 0;
    }
    ((Zone3D*)(scene + 0xec8))->ResetZoneResources(true);
    if (!(*(unsigned int*)(scene + 0x55f4) & 0x800))
        GameState_CleanupOwnedResourcesAndResetRecords(scene + 0x3760);
    ResourceIndex_ClearAlternateLookupTables((unsigned char*)ActionData_GetGlobalTables());
    int* displays = (int*)Object_GetGlobalSixteenEntryDisplayState();
    const int* key = BattleSceneDestroy_UnknownRoleInitializedBytes;
    while (*key >= 0) {
        RemoveMatchingNodeAndResetMatchingObjectSlots(displays, *key);
        ++key;
    }
    void* panel = *(void**)(scene + 0x55cc);
    if (panel)
        Menu_DestroyQueuedRecordPanelResources(panel);
    scene += 8;
    for (int i = 0; i < 5; ++i) {
        if (((SafeAllocator*)(scene + i * 20))->GetSignedAllocator())
            ((SafeAllocator*)(scene + i * 20))->Destroy();
    }
}
