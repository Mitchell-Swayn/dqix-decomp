#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" {
// Original data: arm9/ov031 @ 0x02248998; symbol: data_ov031_02248998; paired cell-template indices.
extern const unsigned char WfcUtilityCreatePairedSelectionMarkers_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x02250bf0; symbol: data_ov031_02250bf0; zero-initialized marker resource pointer.
extern void** OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage;
void Overlay_ClearFourSharedObjects();
void* WfcUtility_CreateSpriteGroupFromCellTemplate(unsigned,unsigned,int);
void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);
void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);
}
// Original: arm9/ov031 @ 0x02223720; symbol: func_ov031_02223720; size: 0xbc.
// Creates two template-selected marker groups with priority one, then positions each group.
extern "C" void WfcUtility_CreatePairedSelectionMarkers(unsigned kind,unsigned firstX,unsigned secondX,unsigned y)
{
    Overlay_ClearFourSharedObjects();
    const unsigned char* templates=WfcUtilityCreatePairedSelectionMarkers_UnknownRoleInitializedBytes+kind*2;
    for (int i=0;i<2;++i) {
        OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i]=WfcUtility_CreateSpriteGroupFromCellTemplate(0,*templates++,1);
        WfcUtility_SetSpriteGroupPriority(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i],-1,1);
    }
    WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[0],-1,firstX,y);
    WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[1],-1,secondX,y);
}

#pragma force_active reset
