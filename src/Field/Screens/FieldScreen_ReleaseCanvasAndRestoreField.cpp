#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/LightingManager.h>
ARM

struct State;
extern "C" {
unsigned Menu_GetCompletedFieldCleanupPhaseMask(State* self, unsigned value);
void Resource_ReleaseOverlayLoadState(char* self);
void FileCache_RestoreRomTablesIfSpaceAvailable();
void GameResources_ClearPrimaryFlags(unsigned int* word, unsigned int mask);
void GameResources_SetSecondaryFlags(int self, unsigned int mask);
void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
void* Zone3D_GetMainInstance();
void Field_QueueZoneTransitionWithInsertionPolicy(int prepend, int id, int afterHead, int argument);
void* GameState_ReadUnkF8(GameState* state);
void* GameState_GetFieldOrbitCamera(GameState* state);
void GameState_SetUnknown3b0(GameState* state, void* value);
void Camera_ClearFollowControlFlags(unsigned char* p, unsigned char mask);
void Camera_SetFollowControlFlags(int self, unsigned char mask);
void Camera_EnableOrbitInput(int param_1);
void G3X_SetClearColor(unsigned a, unsigned b, unsigned short c, unsigned d, int enabled);
void Field_QueueAllPartyEquipmentRefreshes(void* self);
extern char* ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov017 @ 0x021B2758; symbol: func_ov017_021b2758; size: 0x210.
// Releases the overlay canvas when a shared load object is present, then restores
// field flags, orbit camera input, zone clear color and party equipment.
extern "C" int FieldScreen_ReleaseCanvasAndRestoreField(unsigned char* self)
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = GameResources_GetInstance();
    GameState_SetUnknown3b0(game, *(void**)(self + 0x44));

    if (ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1] != 0) {
        if (Menu_GetCompletedFieldCleanupPhaseMask(
                (State*)ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1], 1) != 0)
            *(unsigned*)(self + 0x38) = (*(unsigned*)(self + 0x38) & ~1u) | 1u;
        if (Menu_GetCompletedFieldCleanupPhaseMask(
                (State*)ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1], 2) != 0)
            *(unsigned*)(self + 0x38) |= 2u;
        if (Menu_GetCompletedFieldCleanupPhaseMask(
                (State*)ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1], 4) != 0)
            *(unsigned*)(self + 0x38) |= 4u;
        Resource_ReleaseOverlayLoadState((char*)self);
        FileCache_RestoreRomTablesIfSpaceAvailable();
    }

    GameResources_ClearPrimaryFlags((unsigned int*)resources, 0x10);

    unsigned flags = *(unsigned*)(self + 0x38);
    unsigned bit0 = flags << 31;
    bit0 >>= 31;
    if (bit0 != 0) {
        Zone3D_GetMainInstance();
        GameResources_ClearPrimaryFlags((unsigned int*)resources, 4);
        Field_QueueZoneTransitionWithInsertionPolicy(1, 0, 0, 0);
        *(unsigned*)(self + 0x38) = *(unsigned*)(self + 0x38) & ~2u;
        unsigned char* tint = (unsigned char*)GameState_ReadUnkF8(game);
        if (*(unsigned char*)(self + 0x48) != 0)
            tint[0x67] = 1;
        return 5;
    }
    if (((flags << 30) >> 31) != 0)
        return 6;
    if (((flags << 29) >> 31) != 0)
        return 7;

    game->GetUnknownGameObject();
    void* camera = GameState_GetFieldOrbitCamera(game);
    unsigned char* zone = (unsigned char*)Zone3D_GetMainInstance();
    if (camera != 0) {
        Camera_ClearFollowControlFlags((unsigned char*)camera, 2);
        if (*(unsigned char*)(self + 0x3e) != 0)
            Camera_SetFollowControlFlags((int)camera, 2);
        Camera_EnableOrbitInput((int)camera);
    }
    if (zone != 0)
        zone[0x105] = (unsigned char)(zone[0x105] & ~1);

    if (((*(unsigned*)(self + 0x38) << 26) >> 31) == 0) {
        GameResources_ClearSecondaryFlags((int)resources, 0x609fe);
        GameResources_SetSecondaryFlags((int)resources, *(unsigned*)(self + 0x40));
    }

    LightingManager* lighting = LightingManager::GetInstance();
    int overrideIndex = *(int*)((char*)lighting + 0x90);
    int index = *(int*)((char*)lighting + 0x98);
    unsigned char* table = zone + 0x10c;
    if (overrideIndex != 0)
        index = overrideIndex;
    int mode = *(int*)(table + 0x304);
    unsigned argB = 0x10;
    unsigned short color;
    if (mode == 1)
        color = *(unsigned short*)(table + (index << 1) + 0x8c);
    else
        color = *(unsigned short*)(table + (index << 1) + 0x126);
    G3X_SetClearColor(color, argB, 0x7fff, 0, 0);
    Field_QueueAllPartyEquipmentRefreshes(resources);
    return 4;
}
