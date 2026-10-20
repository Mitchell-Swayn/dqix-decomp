#include <globaldefs.h>
ARM
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void*,unsigned);
extern "C" void Window_ClearResourceBuffers(void*);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void*,int,int,int);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void PositionSelectedRecordMarker(void*);
extern "C" void SubmitReadyRecordOffsetPosition(void*);
// Original: arm9/ov013 @ 0x02184A58; symbol: RefreshActiveIndexedResourcesAndTransfers; size: 0x94.
// Refreshes active indexed resources and transfer records, with state3/4 resource reset and byte640 mode.
extern "C" void SkillAllocation_RefreshDisplayResources(unsigned char* p){
 unsigned state=p[0x63c];switch(state){case 0:case 5:case 6:return;}
 switch(state){case 3:case 4:TextLayout_DrawSelectionPanelAndCursor(p+0x3d4,0);break;}
 Window_ClearResourceBuffers(p+0x38);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(p+0x38);
 if(p[0x640])Window_FillCanvasRectanglesOnAlternateLayer(p+0x38,0,2,0);else Window_FillCanvasRectanglesOnAlternateLayer(p+0x38,1,2,1);
 Graphics_ResetCountedThirtyTwoByteTransfers(p+0x38);PositionSelectedRecordMarker(p);SubmitReadyRecordOffsetPosition(p);
}
