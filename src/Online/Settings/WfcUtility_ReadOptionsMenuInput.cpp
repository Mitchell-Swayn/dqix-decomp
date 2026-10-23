#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" {
// Original data: arm9/ov031 @ 0x02248dfa; symbol: data_ov031_02248dfa; three eight-byte touch rectangles.
extern const unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes[][4];
// Original data: arm9/ov031 @ 0x02248e12, 0x02248e16, 0x02248e14, 0x02248e18;
// symbols: data_ov031_02248e12, data_ov031_02248e16, data_ov031_02248e14, data_ov031_02248e18; corner coordinates, eight-byte stride.
extern unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2[];
extern unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4[];
extern unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3[];
extern unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/ov031 @ 0x02290c5c; symbol: data_ov031_02290c5c; initially zero, selected options-menu row.
extern unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage;
int WfcUtility_IsTouchPressInsideRectangle(const unsigned short*);
void WfcUtility_LatchBottomButtonSelection(int);
void WfcUtility_CreateCornerSelectionMarkers(int,int,int,int);
int WfcUtility_AreButtonsPressed(unsigned);
int WfcUtility_AreButtonsPressedOrRepeating(unsigned);
void WfcUtility_CycleOptionsMenuSelection(int);
}
// Original: arm9/ov031 @ 0x0222938c; symbol: func_ov031_0222938c; size: 0xf4.
// Handles touch selection, accept/cancel buttons, and repeating vertical movement for the three options-menu rows.
extern "C" void WfcUtility_ReadOptionsMenuInput()
{
    for(unsigned i=0;i<3;++i) {
        if(WfcUtility_IsTouchPressInsideRectangle(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes[i])) {
            WfcUtility_LatchBottomButtonSelection(1);
            WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage=i;
            unsigned offset=WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage*4;
            WfcUtility_CreateCornerSelectionMarkers(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2[offset],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4[offset],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3[offset],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5[offset]);
            return;
        }
    }
    if(WfcUtility_AreButtonsPressed(1)) { WfcUtility_LatchBottomButtonSelection(1); return; }
    if(WfcUtility_AreButtonsPressed(2)) { WfcUtility_LatchBottomButtonSelection(0); return; }
    if(WfcUtility_AreButtonsPressedOrRepeating(0x40)) { WfcUtility_CycleOptionsMenuSelection(1); return; }
    if(WfcUtility_AreButtonsPressedOrRepeating(0x80)) WfcUtility_CycleOptionsMenuSelection(3);
}
#pragma force_active reset
