#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma force_active on

typedef struct ProfileSprites { unsigned reserved; void* profiles[3]; void* markers[3]; } ProfileSprites;
typedef struct ProfileOwner { unsigned char selection,padding[3]; ProfileSprites* sprites; } ProfileOwner;
typedef struct CoordinateLane { unsigned short value,other; } CoordinateLane;

// Original data: arm9/ov031 @ 0x02290CC0; symbol: data_ov031_02290cc0; initially zero, mutable profile context.
extern ProfileOwner ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x02249082/0x02249084; symbols: data_ov031_02249082/data_ov031_02249084; original interleaved sprite coordinates.
extern CoordinateLane WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes[];
extern CoordinateLane WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes_Variant2[];
int WfcUtility_GetDialogSelectionResult();
void WfcUtility_PlaySequenceArchiveEntry(int);
void WfcUtility_ClearConnectionProfileAndPersist(unsigned);
void* WfcUtility_GetSpriteGroupEntry(void*,unsigned);
void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);
void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);
void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);
void Network_UnlinkNodeAndReleaseRecords(void*);
void CreateSharedDisplayResource();
void WfcUtility_SetMainLoopCallback(void(*)());
void System_ClearControlAndRegisterMainLoopWhenNoSharedObject();
// Original: arm9/ov031 @ 0x02232FE8; symbol: func_ov031_02232fe8; size: 0x16c.
// Applies or cancels a connection-profile reset and restores its icon and marker sprites.
void WfcUtility_HandleProfileResetConfirmation()
{
    unsigned profile=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selection-4;
    switch(WfcUtility_GetDialogSelectionResult()) {
    case 1: {
        WfcUtility_PlaySequenceArchiveEntry(14);
        WfcUtility_ClearConnectionProfileAndPersist(profile);
        WfcUtility_ExpandSpriteCellTemplate(0,0x56,WfcUtility_GetSpriteGroupEntry(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->profiles[profile],0));
        WfcUtility_SetSpriteGroupPosition(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->profiles[profile],-1,WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes[profile].value,WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes_Variant2[profile].value);
        WfcUtility_SetSpriteGroupPriority(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->profiles[profile],-1,3);
        Network_UnlinkNodeAndReleaseRecords(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->markers[profile]);
        ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->markers[profile]=0;
        break;
    }
    case 0: {
        unsigned markerIndex;
        WfcUtility_PlaySequenceArchiveEntry(7);
        WfcUtility_ExpandSpriteCellTemplate(0,0x11,WfcUtility_GetSpriteGroupEntry(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->markers[profile],0));
        markerIndex=profile+3;
        WfcUtility_SetSpriteGroupPosition(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->markers[profile],-1,WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes[markerIndex].value,WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes_Variant2[markerIndex].value);
        WfcUtility_SetSpriteGroupPriority(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.sprites->markers[profile],-1,3);
        break;
    }
    default:return;
    }
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_ClearControlAndRegisterMainLoopWhenNoSharedObject);
}
#pragma force_active reset
