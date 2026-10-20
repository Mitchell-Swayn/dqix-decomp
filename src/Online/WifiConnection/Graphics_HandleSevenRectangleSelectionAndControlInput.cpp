#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224909a; symbol: data_ov031_0224909a.
// Utility menu touch rectangles, seven eight-byte entries; Graphics_HandleSevenRectangleSelectionAndControlInput iterates them.
// Initial values: hex 08002000540056005a002000a6005600ac002000f800560008007800f800a00008005400540070005a005400a6007000ac005400f8007000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char GraphicsHandleSevenRectangleSelectionAndControlInput_UtilityMenuTouchRectanglesSevenEightByteEntries[],ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
extern "C" int WfcUtility_IsTouchPressInsideRectangle(void*);
extern "C" void WfcUtility_LatchBottomButtonSelection(int);
extern "C" int WfcUtility_AreButtonsPressed(unsigned);
extern "C" int WfcUtility_AreButtonsPressedOrRepeating(unsigned);
extern "C" void WfcUtility_PositionProfileSelectionHighlight(...);
extern "C" void Graphics_MoveSevenStateTransitionSelection(int);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02232858; symbol: Graphics_HandleSevenRectangleSelectionAndControlInput; size: 0xF4.
extern "C" void Graphics_HandleSevenRectangleSelectionAndControlInput(){unsigned i=0;char* rect=GraphicsHandleSevenRectangleSelectionAndControlInput_UtilityMenuTouchRectanglesSevenEightByteEntries;do{if(WfcUtility_IsTouchPressInsideRectangle(rect)){WfcUtility_LatchBottomButtonSelection(1);B(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage,0)=i;WfcUtility_PositionProfileSelectionHighlight();return;}++i;rect+=8;}while(i<7);
 if(WfcUtility_AreButtonsPressed(1)){WfcUtility_LatchBottomButtonSelection(1);return;}if(WfcUtility_AreButtonsPressed(2)){WfcUtility_LatchBottomButtonSelection(0);return;}if(WfcUtility_AreButtonsPressedOrRepeating(64)){Graphics_MoveSevenStateTransitionSelection(1);return;}if(WfcUtility_AreButtonsPressedOrRepeating(128)){Graphics_MoveSevenStateTransitionSelection(3);return;}
 if(WfcUtility_AreButtonsPressedOrRepeating(32)){Graphics_MoveSevenStateTransitionSelection(0);return;}if(WfcUtility_AreButtonsPressedOrRepeating(16))Graphics_MoveSevenStateTransitionSelection(2);
}