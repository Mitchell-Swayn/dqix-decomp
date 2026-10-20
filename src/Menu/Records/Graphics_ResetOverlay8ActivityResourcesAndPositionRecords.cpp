extern "C" { void Window_ClearResourceBuffers(void*); void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*); void Window_FillCanvasRectanglesOnAlternateLayer(void*,int,int,int); void Graphics_ResetCountedThirtyTwoByteTransfers(void*); void PartyTalk_PositionSummaryPanelCornerSprites(void*); void Graphics_UpdateOverlay8PanelAndReleaseResources(void*); }
struct Overlay8Activity { unsigned char unknown[0xe9b]; signed char second; unsigned char unknownE9c[0x24]; unsigned char active : 1; unsigned char remaining : 7; };
// Original: arm9/ov008 @ 0x02189404; symbol: func_ov008_02189404; size: 0x68.
extern "C" void Graphics_ResetOverlay8ActivityResourcesAndPositionRecords(Overlay8Activity* object) {
    unsigned char* base=(unsigned char*)object;
    Window_ClearResourceBuffers(base+0x18); ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(base+0x18); Window_FillCanvasRectanglesOnAlternateLayer(base+0x18,1,2,1); Graphics_ResetCountedThirtyTwoByteTransfers(base+0x18);
    PartyTalk_PositionSummaryPanelCornerSprites(object);
    if(object->second && object->active) Graphics_UpdateOverlay8PanelAndReleaseResources(base+0x2a8);
}
